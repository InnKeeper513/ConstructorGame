#include "Board.h"

Board::Board()
{
	this->lines = 0;
	this->numAddresses = 0;
	this->numPathes = 0;
	this->numTiles = 0;
	this->boardArray = new string[this->lines];
	this->addresses = new Address[this->numAddresses];
	this->pathes = new Path[this->numPathes];
	this->tiles = new Tile[this->numTiles];
}

Board::~Board()
{
	delete[] this->boardArray;
	delete[] this->addresses;
	delete[] this->pathes;
	delete[] this->tiles;
}

void Board::Print(ostream &output)
{
	for (int i=0;i<this->lines;i++)
	{
		output << this->boardArray[i]<< endl;
	}
}

void Board::AddLine(string line)
{
	string* newArr = new string[this->lines + 1];
	copy(this->boardArray, this->boardArray + this->lines, newArr);
	delete[] this->boardArray;
	this->boardArray = newArr;
	this->boardArray[this->lines] = line;
	this->lines++;
}
int Board::FindMaxNumber(string findStr)
{
	int max = 0;
	string lastLine = this->boardArray[this->lines-1];
	size_t found = lastLine.find(findStr);
	if (found != std::string::npos)
	{
		string sValue = lastLine.substr(found + 3, 2);
		return  atoi(sValue.c_str()) + 1;
	}
	return 0;
}
void Board::BuildTiles()
{
	this->numAddresses = this->FindMaxNumber("--|");
	this->numPathes = this->FindMaxNumber("|--");
	this->BuildAddresses();
	this->BuildPathes();
	this->CreateTiles();
}
void Board::BuildAddresses()
{
	delete[] this->addresses;
	this->addresses = new Address[this->numAddresses];
	for (int i=0;i<this->numAddresses;i++)
	{
		this->addresses[i] = Address(i);
	}
}
void Board::BuildPathes()
{
	delete[] this->pathes;
	this->pathes = new Path[this->numPathes];
	for (int i = 0;i<this->numPathes;i++)
	{
		this->pathes[i] = Path(i);
	}
}
void Board::CreateTiles()
{
	for (int i=2; i<this->lines;i=i+4)
	{
		string line = this->boardArray[i];
		for(size_t j=5;j<line.length();j=j+10)
		{
			string sNum = line.substr(j+1, 2);
			string line_nxt = this->boardArray[i + 1];
			string sResource = line_nxt.substr(j, 6);
			stringstream trimmer;
			trimmer << sResource;
			sResource.clear();
			trimmer >> sResource;
			string line_nxt_2 = this->boardArray[i + 2];
			string sValue = line_nxt_2.substr(j+1, 2);
			if (sResource != "")
			{
				this->AddTile(atoi(sNum.c_str()), sResource, atoi(sValue.c_str()),i,j);
			}
		}
	}
}

void Board::AddTile(int number, string resource, int value, int row, int col)
{
	Tile* newArr = new Tile[this->numTiles + 1];
	copy(this->tiles , this->tiles + this->numTiles, newArr);
	delete[] this->tiles;
	this->tiles = newArr;

	Tile newTile= Tile(number, resource, value);

	string topLine = this->boardArray[row - 2]; // | 0|-- 0--| 1|
	string sTopLeftAddress = topLine.substr(col-4, 2); //0
	string sTopRightAddress = topLine.substr(col +6, 2);//1
	string sTopPath = topLine.substr(col + 1, 2);//0

	string currentLine = this->boardArray[row];//1    0    2
	string sLeftPath = currentLine.substr(col - 4, 2);//1
	string sRightPath = currentLine.substr(col + 6, 2);//2

	string line_nxt_2 = this->boardArray[row + 2];// | 2|-- 3--| 3|   3  | 4|-- 4--| 5|
	string sLeftAddress = line_nxt_2.substr(col - 4, 2);//3
	string sRightAddress = line_nxt_2.substr(col + 6, 2);//4

	string line_nxt_4 = this->boardArray[row + 4];// 5    1    6         7    2    8
	string sBottonLeftPath = line_nxt_4.substr(col - 4, 2);//6
	string sBottonRightPath = line_nxt_4.substr(col + 6, 2);//6

	string line_nxt_6 = this->boardArray[row + 6];//| 6|-- 9--| 7|  10  | 8|--10--| 9|   5  |10|--11--|11|
	string sBottonLeftAddress = line_nxt_6.substr(col - 4, 2);//8
	string sBottonRightAddress = line_nxt_6.substr(col + 6, 2);//9
	string sBottonPath = line_nxt_6.substr(col + 1, 2);//10

	Address* p_topLeftAddress = &this->addresses[atoi(sTopLeftAddress.c_str())];
	Address* p_topRightAddress = &this->addresses[atoi(sTopRightAddress.c_str())];

	newTile.AddAddress(p_topLeftAddress);
	newTile.AddAddress(p_topRightAddress);

	Address* p_LeftAddress = &this->addresses[atoi(sLeftAddress.c_str())];
	newTile.AddAddress(p_LeftAddress);

	Address* p_RightAddress = &this->addresses[atoi(sRightAddress.c_str())];
	newTile.AddAddress(p_RightAddress);

	Address* p_BottonLeftAddress = &this->addresses[atoi(sBottonLeftAddress.c_str())];
	newTile.AddAddress(p_BottonLeftAddress);

	Address* p_BottonRightAddress = &this->addresses[atoi(sBottonRightAddress.c_str())];
	newTile.AddAddress(p_BottonRightAddress);

	Path* p_TopPath = &this->pathes[atoi(sTopPath.c_str())];
	newTile.AddPath(p_TopPath);

	Path* p_LeftPath = &this->pathes[atoi(sLeftPath.c_str())];
	newTile.AddPath(p_LeftPath);

	Path* p_RightPath = &this->pathes[atoi(sRightPath.c_str())];
	newTile.AddPath(p_RightPath);

	Path* p_BottonLeftPath = &this->pathes[atoi(sBottonLeftPath.c_str())];
	newTile.AddPath(p_BottonLeftPath);

	Path* p_BottonRightPath = &this->pathes[atoi(sBottonRightPath.c_str())];
	newTile.AddPath(p_BottonRightPath);

	Path* p_BottonPath = &this->pathes[atoi(sBottonPath.c_str())];
	newTile.AddPath(p_BottonPath);

	newTile.SetPos(row,col);


	//build relationships
	p_topLeftAddress->AddNeighborAddress(p_topRightAddress);

	p_topRightAddress->AddNeighborAddress(p_RightAddress);

	p_RightAddress->AddNeighborAddress(p_BottonRightAddress);

	p_BottonRightAddress->AddNeighborAddress(p_BottonLeftAddress);

	p_BottonLeftAddress->AddNeighborAddress(p_LeftAddress);

	p_LeftAddress->AddNeighborAddress(p_topLeftAddress);



	p_topLeftAddress->AddNeighborPath(p_TopPath);
	p_topLeftAddress->AddNeighborPath(p_LeftPath);

	p_topRightAddress->AddNeighborPath(p_TopPath);
	p_topRightAddress->AddNeighborPath(p_RightPath);

	p_RightAddress->AddNeighborPath(p_RightPath);
	p_RightAddress->AddNeighborPath(p_BottonRightPath);

	p_BottonRightAddress->AddNeighborPath(p_BottonRightPath);
	p_BottonRightAddress->AddNeighborPath(p_BottonPath);


	p_BottonLeftAddress->AddNeighborPath(p_BottonPath);
	p_BottonLeftAddress->AddNeighborPath(p_BottonLeftPath);

	p_LeftAddress->AddNeighborPath(p_LeftPath);
	p_LeftAddress->AddNeighborPath(p_BottonLeftPath);



	this->tiles[this->numTiles] = newTile;
	this->numTiles++;


	p_TopPath->AddNeighborPath(p_RightPath);
	p_RightPath->AddNeighborPath(p_BottonRightPath);
	p_BottonRightPath->AddNeighborPath(p_BottonPath);
	p_BottonPath->AddNeighborPath(p_BottonLeftPath);
	p_BottonLeftPath->AddNeighborPath(p_LeftPath);
	p_LeftPath->AddNeighborPath(p_TopPath);

}



ostream &operator<<(ostream &output, Board &board) {
	board.Print(output);
	return output;
}

istream &operator>>(istream &input, Board &board) {
	string line;
	while (getline(input, line)) {
		board.AddLine(line);
	}
	board.BuildTiles();
	return input;
}
