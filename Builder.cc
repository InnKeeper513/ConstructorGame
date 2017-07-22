#include "Builder.h"

using namespace std;

Builder::Builder(int number, string color, int numPoints, int numBrick, int numEnergy, int numGlass, int numHeat, int numWifi):
	number{number},
	color{color},
	numPoints{numPoints},
	numBrick{numBrick},
	numEnergy{numEnergy},
	numGlass{numGlass},
	numHeat{numHeat},
	numWifi{numWifi}
	{}


int Builder::getNumber()
{
	return this->number;
}
string Builder::getColor()
{
	return this->color;
}

int Builder::getNumPoints()
{
	return this->numPoints;
}
int Builder::getNumBrick()
{
	return this->numBrick;
}

int Builder::getNumEnergy()
{
	return this->numEnergy;
}

int Builder::getNumGlass()
{
	return this->numGlass;
}

int Builder::getNumHeat()
{
	return this->numHeat;
}

int Builder::getNumWifi()
{
	return this->numWifi;
}

// Added
void Builder::trade(Builder&, string give, string take){

}

void Builder::printData(){
	cout << numBrick << " " << numEnergy << " " << numGlass << " " << numHeat << " " << numWifi;
}

void Builder::status(){
	cout << color << " has " << numPoints << " building points, " << numBrick << " brick, "
	<< numEnergy << " energy, " << numGlass << " glass, " << numHeat << " heat, and " << numWifi
	<< " WiFi." << endl;
}

int Builder::incrPoints(int add){
		numPoints += add;
}

int Builder::addBrick(int add){
	numBrick += add;
}
int Builder::addEnergy(int add){
	numEnergy += add;
}
int Builder::addGlass(int add){
	numGlass += add;
}
int Builder::addHeat(int add){
	numHeat += add;
}
int Builder::addWifi(int add){
	numWifi += add;
}
int Builder::removeBrick(int remove){
	numBrick -= remove;
}
int Builder::removeEnergy(int remove){
	numEnergy -= remove;
}
int Builder::removeGlass(int remove){
	numGlass -= remove;
}
int Builder::removeHeat(int remove){
	numHeat -= remove;
}
int Builder::removeWifi(int remove){
	numWifi -= remove;
}
// Add address
int Builder::addAddress(int set){
	string name;
	if(color == "Red")
		name = "R";
	else if(color == "Blue")
		name = "B";
	else if(color == "Orange")
		name = "O";
	else if(color == "Yellow")
		name = "Y";

	addresses[set].setOwner(name);
	address.emplace_back(set);
}
int Builder::addPath(int set){
	path.emplace_back(set);
}

bool Builder::checkImprove(int check){
		for(int i = 0; i < address.size(); i++){
			// It cannot be a tower
			if(address[i] == check && addresses[address[i]].getBuildingType() != "T")
				return true;
			else if(address[i] == check && addresses[address[i]].getBuildingType() == "T")
				return false;
		}
		return false;
}

void Builder::checkBuildingResource(int check){
	if(addresses[check].getBuildingType() == "B"){
				if(numGlass >= 2 && numHeat >= 3){
					numGlass -= 2;
					numHeat -= 3;
					numPoints ++;
					addresses[check].setBuildingType("H");
				}else{
					cout << "You do not have enough resources." << endl;
				}
	} else if(addresses[check].getBuildingType() == "H"){
				if(numBrick >= 3 && numEnergy >= 2 && numGlass >= 2 && numWifi >= 1 && numHeat >= 2){
					numBrick -= 3;
					numEnergy -= 2;
					numGlass -= 2;
					numWifi -= 1;
					numHeat -= 22;
					numPoints ++;
					addresses[check].setBuildingType("T");
				}else{
					cout << "You do not have enough resources." << endl;
				}
	}
}

vector<int> Builder::getAddress(){
	return address;
}
vector<int> Builder::getPath(){
	return path;
}
