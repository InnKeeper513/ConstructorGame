#include <iostream>
#include <vector>
#include "Dice.h"
#include "Board.h"
#include "Builder.h"
#include <string>
#include <sstream>
#include <stdlib.h> // for srand() random number generator
#include <fstream> // for save to file


using namespace std;
void boardLayout(bool def, string board_file, vector<Builder>& builders){
	string line;
	string default_layout;
	if(def){
		default_layout = "layout.txt";
	} else {
		default_layout = board_file;
	}

		ifstream fileStream{default_layout};
		int input_line;
		int counter = 0;
		getline(fileStream, line);
		stringstream ss{line};

		while (ss >> input_line) {
					if(input_line == 0){
						ss >> input_line;
						tiles.emplace_back(Tile(counter, "BRICK", input_line));
					} else if(input_line == 1){
							ss >> input_line;
							tiles.emplace_back(Tile(counter, "ENERGY", input_line));
					}	else if(input_line == 2){
							ss >> input_line;
							tiles.emplace_back(Tile(counter, "GLASS", input_line));
					}	else if(input_line == 3){
							ss >> input_line;
							tiles.emplace_back(Tile(counter, "HEAT", input_line));
					}	else if(input_line == 4){
							ss >> input_line;
							tiles.emplace_back(Tile(counter, "WIFI", input_line));
					} else if(input_line == 5){
							ss >> input_line;
							tiles.emplace_back(Tile(counter, "PARK", input_line));
					}
					counter ++;
		}

}

void resourceDistribution(string resourceName, int amount, int &heat, int &energy, int &brick, int &wifi, int &glass){
	if(resourceName == "HEAT"){
		heat += amount;
	} else if(resourceName == "ENERGY"){
		energy += amount;
	} else if(resourceName == "BRICK"){
		brick += amount;
	} else if(resourceName == "WIFI"){
		wifi += amount;
	} else
		glass += amount;
}

vector<Address> addresses;
vector<Tile> tiles;
vector<Path> paths;
int main()
{
	Board board;
	cout << "Press enter to load the dafault board" << endl;
	cout << "The following are the commandline options, '-seed <number>', '-load <file>', '-board <file>', ‘-random-board’" << endl;
	// initialize the builders.
	vector<Builder> builders;
	builders.emplace_back(Builder(0,"Blue"));
	builders.emplace_back(Builder(1,"Red"));
	builders.emplace_back(Builder(2,"Orange"));
	builders.emplace_back(Builder(3,"Yellow"));

	bool loaded = false;
	int currentTurn = 0;
	int geeseLocation = -1;
	// WRITE THE COMMAND LINE HERE
	string commandLine="";
	bool def = true;

	getline(cin,commandLine);

	string word;
	bool load_flag = false;
	stringstream ss {commandLine};

	while (ss >> word) {
	    if (word == "-seed") {
	        int seed;
	        ss >> seed;
	        srand(seed);
	    } else if (word == "-load") {
				def = false;

				load_flag = true;
				string game_file;
				ss >> game_file;
				ifstream myfile;
				myfile.open (game_file);
				string line;
				getline(myfile, line);
				stringstream k{line};
				k >> currentTurn; // read in <curTurn>

				for (int i = 0; i < 4; ++i) { // read in <builder(0-3)data>
					getline(myfile,line);

					stringstream s{line};
					int bricks, energies, glasses, heats, wifis;
					s >> bricks >> energies >> glasses >> heats >> wifis;

					builders[i].addBrick(bricks);
					builders[i].addEnergy(energies);
					builders[i].addGlass(glasses);
					builders[i].addHeat(heats);
					builders[i].addWifi(wifis);

					string r_flush;
					s >> r_flush;

					string path = " ";
					int value;
					while (s >> path && path != "h") {
						stringstream temporary{path};
						temporary >> value;
						builders[i].addPath(value);
					}

					int address;
					string residence;
					while (s >> address) {

						s >> residence;
						if(residence == "B")
							builders[i].incrPoints(1);
						else if(residence == "H")
							builders[i].incrPoints(2);
						else 	builders[i].incrPoints(3);

						builders[i].addAddress(address);
						addresses[address].setBuildingType(residence);
					}
				}

				getline(myfile,line);
				stringstream s{line};
				int input_line;
				int counter = 0;

				while (s >> input_line) {
							if(input_line == 0){
								s >> input_line;
								tiles.emplace_back(Tile(counter, "BRICK", input_line));
							} else if(input_line == 1){
									s >> input_line;
									tiles.emplace_back(Tile(counter, "ENERGY", input_line));
							}	else if(input_line == 2){
									s >> input_line;
									tiles.emplace_back(Tile(counter, "GLASS", input_line));
							}	else if(input_line == 3){
									s >> input_line;
									tiles.emplace_back(Tile(counter, "HEAT", input_line));
							}	else if(input_line == 4){
									s >> input_line;
									tiles.emplace_back(Tile(counter, "WIFI", input_line));
							} else if(input_line == 5){
									s >> input_line;
									tiles.emplace_back(Tile(counter, "PARK", input_line));
							}
							counter ++;
				}

			} else if (word == "-board") {
					def = false;

	        string board_file;
					ss >> board_file;
	        boardLayout(false, board_file, builders);

	    } else if (word == "-random-board") {
					def = false;

	        if (load_flag) {
	            // ignore command
	        }
	        else {
	            // randomly generate tiles
	            vector<string> res = {"WIFI","WIFI","WIFI","HEAT","HEAT","HEAT","BRICK","BRICK","BRICK","BRICK","ENERGY","ENERGY","ENERGY","ENERGY","GLASS","GLASS","GLASS","GLASS","PARK"};
	            vector<int> vals = {2,3,3,4,4,5,5,6,6,8,8,9,9,10,10,11,11,12};
	            for (int i = 0; i < 19; ++i) {  // GO TO TILE TO IMPLEMENT public SETRES AND SETVAL
									int k, j;
									k = rand() % res.size();
									if(res[k] == "PARK"){
										tiles.emplace_back(i,res[k],7);
									} else {
										j = rand() % vals.size();
										tiles.emplace_back(i,res[k],vals[j]);
									}
									if(res[k] == "PARK"){
										res.erase(res.begin() + k);
									} else {
										res.erase(res.begin() + k);
										vals.erase(vals.begin() + j);
									}
	            }
	        }
	    } else {
				cout << "Invalid Command, use default board." << endl;
			}
	}

	if(def)
		boardLayout(def, " ",builders);
	bool win = false;

	int random;

	// Continue the game
	while(true){
	board.addTileDependency();

	// Adding 2 initial address locations for the player
	//TODO Address need to be valid
	// - It must exist
	// - It cannot collapse with other player's address
	if(!load_flag){
		for(int i = 0; i < 4; i++){
			int tempAdd;

			while(true){
				cout << "Builder " << builders[i].getColor() << " , where do you want to build a basement?" << endl;
				cout << ">";
				cin >> tempAdd;

				if(addresses[tempAdd].getBuilder() == "N"){
					builders[i].addAddress(tempAdd);
					addresses[tempAdd].setBuildingType("B");
					break;
				} else {
					cout << "You cannot build here." << endl;
					cin.clear();
					cin.ignore();
				}
			}
		}
		for(int i = 3; i >= 0; i--){
			int tempAdd2;

			while(true){
				cout << "Builder " << builders[i].getColor() << " , where do you want to build a basement?" << endl;
				cout << ">";
				cin >> tempAdd2;

				if(addresses[tempAdd2].getBuilder() == "N"){
					builders[i].addAddress(tempAdd2);
					addresses[tempAdd2].setBuildingType("B");
					break;
				} else {
					cout << "You cannot build here." << endl;
					cin.clear();
					cin.ignore();
				}
			}
		}
	}
	// Print the updated board
	cout << board;

	// Begin the game ********************

	// Beginning of Turn *****************
	// Loop through the game
	while(true){

		if (win == true){
			break;
		}

		// Every turn, there will be 4 player inputing commands
		for(int i = 0; i < 4; i++){
			if(loaded){
				i = currentTurn;
				loaded = false;
			}

			string builderColor;
			if(builders[i].getColor() == "Red")
				builderColor = "R";
			else if(builders[i].getColor() == "Blue")
				builderColor = "B";
			else if(builders[i].getColor() == "Orange")
				builderColor = "O";
			else if(builders[i].getColor() == "Yellow")
				builderColor = "Y";

			if(builders[i].getNumPoints() >= 10){
				cout << "Player " << builders[i].getColor() << " win!";
				win = true;
				break;
			}

			cout << "Builder " << builders[i].getColor() << "'s turn'" << endl;
			// print the builder's status
			builders[i].status();
			// TODO need to make sure the user entered the right input
			// Enter rolling dice commands
			while(true){
				string diceCMD;

				while(true){
					cout << "Enter 'load' or 'fair' dice" << endl;
					cout << ">";
					cin >> diceCMD;
					if(diceCMD != "load" && diceCMD != "fair")
						cout << "Invalid Command" << endl;
					else break;
					}

				Dice dice(diceCMD);
				// Get the rolled number
				random = dice.rollDice();

				// Goose move
				if(random == 7){
					// Any builder with >= 10 resources lose half of the resources chosen at random
						for (int o = 0; o < 4; ++o) {

							int n_resources = builders[o].getNumBrick() + builders[o].getNumEnergy() + builders[o].getNumGlass() +
								builders[o].getNumHeat() + builders[o].getNumWifi();

							int n_lost;
							if (n_resources >= 10) {
								n_lost = n_resources / 2;
								cout << "Builder " << builders[o].getColor() << " loses " << n_lost << " resources to the geese. Lose:" << endl;


								int bTot=0;
								int eTot=0;
								int gTot=0;
								int hTot=0;
								int wTot=0;
								while (n_lost != 0) {
									int b_lost = std::rand() % (std::min(builders[o].getNumBrick(), n_lost) + 1);
									n_lost -= b_lost;
									bTot += b_lost;
									int e_lost = std::rand() % (std::min(builders[o].getNumEnergy(), n_lost) + 1);
									n_lost -= e_lost;
									eTot += e_lost;
									int g_lost = std::rand() % (std::min(builders[o].getNumGlass(), n_lost) + 1);
									n_lost -= g_lost;
									gTot += g_lost;
									int h_lost = std::rand() % (std::min(builders[o].getNumHeat(), n_lost) + 1);
									n_lost -= h_lost;
									hTot += h_lost;
									int w_lost = std::rand() % (std::min(builders[o].getNumWifi(), n_lost) + 1);
									n_lost -= w_lost;
									wTot += w_lost;
								}

								builders[o].removeBrick(bTot);
								cout << bTot << " Brick" << endl;
								builders[o].removeEnergy(eTot);
								cout << eTot << " Energy" << endl;
								builders[o].removeGlass(gTot);
								cout << gTot << " Glass" << endl;
								builders[o].removeHeat(hTot);
								cout << hTot << " Heat" << endl;
								builders[o].removeWifi(wTot);
								cout << wTot << " Wifi" << endl;
							}
						}
						bool exist = false;

						// builder moves geese to any tile
						cout << "Choose where to place the GEESE." << endl;
						cout << ">";
						int tile_n;
						cin >> tile_n;
						builders[i].notifyObservers(Subscriptions::Tile, builders[i].getColor(), tile_n);

						//builder can steal from builders who have built residences on tiles[tile_n]
						cout << "Builder " << builders[i].getColor() << " can choose to steal from: " << endl;
						vector<string> list;
						int temp = tiles[tile_n].getAddress().size();
						for(int w = 0; w < temp; w++){
							int temp2 = list.size();
							exist = false;
							stringstream tempo;
							tempo << builders[i].getColor()[0];
							string k;
							tempo >> k;

							if(addresses[tiles[tile_n].getAddress()[w]].getBuilder() != k && addresses[tiles[tile_n].getAddress()[w]].getBuilder() != "N")

								for(int e = 0; e < temp2; e++){
										if(list[e][0] == addresses[tiles[tile_n].getAddress()[w]].getBuilder()[0]){
											exist = true;
										}
								}
								if(!exist){
									string fullname = " ";
									if(addresses[tiles[tile_n].getAddress()[w]].getBuilder() == "B")
										fullname = "Blue";
									else if(addresses[tiles[tile_n].getAddress()[w]].getBuilder() == "R")
										fullname = "Red";
									else if(addresses[tiles[tile_n].getAddress()[w]].getBuilder() == "Y")
										fullname = "Yellow";
									else if(addresses[tiles[tile_n].getAddress()[w]].getBuilder() == "O")
										fullname = "Orange";
									if(fullname != " "){
										list.emplace_back(fullname);
										cout << fullname << endl;
									}
								}
						}

						if(list.size() != 0){
						cout << endl;
						//attempt to steal
						cout << "Choose a builder to steal from." << endl;
						cout << ">";
						string builder_color;

						while(true){
							bool valid = false;
							cin >> builder_color;
							int temp3 = list.size();
							for(int u = 0; u < temp3; u++){
								if(list[u] == builder_color)
									valid = true;
							}
							if(valid)
								break;
							cout << "Invalid Color, Re-enter! " << endl;
							cin.ignore();
							cin.clear();
						}
						for (int o = 0; o < 4; ++o) {
							if (builders[o].getColor() == builder_color) {

								int total_resources = builders[o].getNumBrick() + builders[o].getNumEnergy() + builders[o].getNumGlass() +
									builders[o].getNumHeat() + builders[o].getNumWifi();
								int k = std::rand() % total_resources;
								if (k < builders[o].getNumBrick()) {
									builders[i].addBrick(1);
									builders[o].removeBrick(1);
									cout << "Builder " << builders[i].getColor() << " steals Brick from builder " << builders[o].getColor() << "." << endl;
								}
								if (k < builders[o].getNumEnergy()) {
									builders[i].addEnergy(1);
									builders[o].removeEnergy(1);
									cout << "Builder " << builders[i].getColor() << " steals Energy from builder " << builders[o].getColor() << "." << endl;
								}
								if (k < builders[o].getNumGlass()) {
									builders[i].addGlass(1);
									builders[o].removeGlass(1);
									cout << "Builder " << builders[i].getColor() << " steals Glass from builder " << builders[o].getColor() << "." << endl;
								}
								if (k < builders[o].getNumHeat()) {
									builders[i].addHeat(1);
									builders[o].removeHeat(1);
									cout << "Builder " << builders[i].getColor() << " steals Heat from builder " << builders[o].getColor() << "." << endl;
								}
								if (k < builders[o].getNumWifi()) {
									builders[i].addWifi(1);
									builders[o].removeWifi(1);
									cout << "Builder " << builders[i].getColor() << " steals Wifi from builder " << builders[o].getColor() << "." << endl;
								}
							}
						}

					} else cout << "Actually, no player can be stole from" << endl;
				} else {
					// If the builder has rolled a number that is different then 7
					bool gained = false;

					// Run through each player
					for(int u = 0; u < 4; u ++){
							// The amount of resources to be gained.
							int heat = 0;
							int energy = 0;
							int brick = 0;
							int wifi = 0;
							int glass = 0;
							bool playerGain = false;

							// Run through each tiles;
							int temp6 = tiles.size();
							for(int k = 0; k < temp6; k++){
								// The tile value is equivalent to the value of the dice

								if(tiles[k].getValue() == random && tiles[k].getResource() != "Park" && geeseLocation != k){
									// get the address numbers in the tile
									vector<int> allTileAddress = tiles[k].getAddress();
									int temp4 = allTileAddress.size();
									for(int p = 0; p < temp4; p ++){
										//	cout << " Neighbor Address: " << allTileAddress[p] << " Builder: " << addresses[allTileAddress[p]].getBuilder() << " Color " << builders[u].getColor() << endl;

										if(addresses[allTileAddress[p]].getBuilder() == builders[u].getColor().substr(0,1)){
											playerGain = true;
											gained = true;
											if(addresses[allTileAddress[p]].getBuildingType() == "B"){
												// gained the amount of resource
												resourceDistribution(tiles[ k].getResource(), 1, heat, energy, brick, wifi, glass);
											} else if(addresses[allTileAddress[p]].getBuildingType() == "H"){
												// gained the amount of resource
												resourceDistribution(tiles[k].getResource(), 2, heat, energy, brick, wifi, glass);
											} else {
												// gained the amount of resource
												resourceDistribution(tiles[k].getResource(), 3, heat, energy, brick, wifi, glass);
											}

										}
									}

								}
							}
							if(playerGain){
								cout << "Builder " << builders[u].getColor() << " gained:" << endl;
								if(heat != 0)
									cout << heat << " Heat" << endl;
								if(energy != 0)
									cout << energy << " Energy" << endl;
								if(brick != 0)
									cout << brick << " Brick" << endl;
								if(wifi != 0)
									cout << wifi << " Wifi" << endl;
								if(glass != 0)
									cout << glass << " Glass" << endl;
							}
							// Add the amount of resources to the builder.
							builders[u].addHeat(heat);
							builders[u].addEnergy(energy);
							builders[u].addBrick(brick);
							builders[u].addWifi(wifi);
							builders[u].addGlass(glass);

						}

				if(!gained)
					cout << "No builders gained resources." << endl;
				}
				break;
			}

	// End Beginning of Turn *********************
	// Begin During the Turn *********************
			// User is able to call the list of commands until end turn
			while(true){
				string userCMD;
				cout << ">";
				cin >> userCMD;

				//TODO endoffile need to be backed up

				if(userCMD == "board")
					cout << board;
				else if(userCMD == "status"){
					for(int i = 0; i < 4; i++){
						builders[i].status();
					}
				} else if(userCMD == "residences") {
					// print all the completed residences
					// print basements
					cout << "B: ";
					int temp5 = builders[i].getAddress().size();
					for(int j = 0; j < temp5; j++){
						if(addresses[builders[i].getAddress()[j]].getBuildingType() == "B")
							cout << builders[i].getAddress()[j] << " ";
					}
					// print houses
					cout << "H: ";
					for(int j = 0; j < temp5; j++){
						if(addresses[builders[i].getAddress()[j]].getBuildingType() == "H")
							cout << builders[i].getAddress()[j] << " ";
					}
					// print towers
					cout << "T: ";
					for(int j = 0; j < temp5; j++){
						if(addresses[builders[i].getAddress()[j]].getBuildingType() == "T")
							cout << builders[i].getAddress()[j] << " ";
					}
					cout << endl;

				} else if(userCMD == "build-road") {

					cin >> userCMD;
					istringstream ss{userCMD};
					int roadNumber;
					ss >> roadNumber;

					// TODO need to check if the road is valid and if resource is enough
					// Cost of building a road
					if(builders[i].getNumHeat() >= 1 && builders[i].getNumWifi() >= 1){


					  if (builders[i].pathNeighbors(roadNumber) || builders[i].pathAddress(roadNumber)){

							// If contain enough resources, build the raod.
							builders[i].removeHeat(1);
							builders[i].removeWifi(1);
							builders[i].addPath(roadNumber);
							builders[i].notifyObservers(Subscriptions::Path, builders[i].getColor(), roadNumber);
						} else {
							cout << "You cannot build here." << endl;
						}
					} else {
						cout << "You do not have enough resources." << endl;
					}
					// Build the road at roadNumber
				} else if(userCMD == "build-res") {

					cin >> userCMD;
					istringstream ss{userCMD};
					int resNumber;
					ss >> resNumber;

					// Check if the residence address is valid
					// If yes build a basement

					if(
					 addresses[resNumber].getBuildingType() == "N" &&
				 	 builders[i].checkAdjacentPath(resNumber)){

						// Check if there are enough resources
						if(builders[i].getNumBrick() >= 1 && builders[i].getNumEnergy() >= 1 &&
							builders[i].getNumGlass() >= 1 && builders[i].getNumWifi() >= 1){

							// Remove the amount of resources by building the basement
							builders[i].removeBrick(1);
							builders[i].removeEnergy(1);
							builders[i].removeGlass(1);
							builders[i].removeWifi(1);

							// Add the basement to the address and set its owner
							builders[i].addAddress(resNumber);
							builders[i].notifyObservers(Subscriptions::Address, builders[i].getColor(), resNumber);

						} else {
							cout << "You do not have enough resources." << endl;
						}
					} else {
						cout << "You cannot build here." << endl;
					}

				} else if(userCMD == "improve") {
					// Improve the residence at the improveNumebr location
					cin >> userCMD;
					istringstream ss{userCMD};
					int improveNumber;
					ss >> improveNumber;
					// check if the owner owns the residence and it is not a tower yet
					if(builders[i].checkImprove(improveNumber)){
						// If the resouce is enough, will build it.
						builders[i].checkBuildingResource(improveNumber);
					} else {
					// invalid address to improve
						cout << "You cannot build here." << endl;
					}

				} else if(userCMD == "trade") {
						string builder2;
						string resource1;
						string resource2;
						// TODO need to check if these inputs are valid
						cin >> builder2;
						cin >> resource1;
						cin >> resource2;

						// Invalid input
						while((builder2 != "Blue" && builder2 != "Red"&& builder2 != "Yellow"&& builder2 != "Orange") ||
									(resource1 != "HEAT"&&resource1 != "WIFI"&&resource1 != "GLASS" &&resource1 != "ENERGY" &&resource1 != "BRICK") ||
									(resource2 != "HEAT"&&resource2 != "WIFI"&&resource2 != "GLASS" &&resource2 != "ENERGY" &&resource2 != "BRICK")){
										cout << "Invalid Input, Re-input" << endl;
										cout << "Trade with ? " << endl;
										cin >> builder2;
										cout << "Trade resource: ";
										cin >> resource1;
										cout << "For : ";
										cin >> resource2;
									}


						int playerNum = 0;
						for(int k = 0; k < 4; k++){
							if(builders[k].getColor() == builder2){
								playerNum = k;
								break;
							}
						}
						// TODO Check if have enough resource
						cout << builders[i].getColor() << " offers " << builder2 << " one " << resource1 << " for one " << resource2 << endl;
						cout << "Does " << builder2 << " accept this offer?" << endl;
						cout << "Answer with yes / no" << endl;

						string answer;
						cin >> answer;

						// If the answer is yes, then the current builder will gain 1 resource1 and lose 1 resource 2
						// The trading builder will lose 1 resource 1 and gain 1 resource 2
						if(answer == "yes"){
							if(resource1 == "HEAT"){
									builders[playerNum].addHeat(1);
									builders[i].removeHeat(1);
							} else if(resource1 == "WIFI") {
									builders[playerNum].addWifi(1);
									builders[i].removeWifi(1);
							} else if(resource1 == "BRICK") {
									builders[playerNum].addBrick(1);
									builders[i].removeBrick(1);
							} else if(resource1 == "ENERGY") {
									builders[playerNum].addEnergy(1);
									builders[i].removeEnergy(1);
							} else if(resource1 == "GLASS") {
									builders[playerNum].addGlass(1);
									builders[i].removeGlass(1);
							}
							if(resource2 == "HEAT"){
									builders[i].addHeat(1);
									builders[playerNum].removeHeat(1);
							} else if(resource2 == "WIFI") {
									builders[i].addWifi(1);
									builders[playerNum].removeWifi(1);
							} else if(resource2 == "BRICK") {
									builders[i].addBrick(1);
									builders[playerNum].removeBrick(1);
							} else if(resource2 == "ENERGY") {
									builders[i].addEnergy(1);
									builders[playerNum].removeEnergy(1);
							} else if(resource2 == "GLASS") {
									builders[i].addGlass(1);
									builders[playerNum].removeGlass(1);
							}
						} else if(answer == "no"){

						} else {
							// TODO will keep asking until correct command;
							cout << "Invalid Command" << endl;
						}

				} else if(userCMD == "next") {
					// Switch to the next player
					break;
				} else if(userCMD == "save") {

				    cin >> userCMD;
				    std::ofstream ofs (userCMD, std::ofstream::out);
				    ofs << builderColor << endl; // prints <curTurn>

				    for (int o = 0; o < 4; o++) {// prints <builder(0-3)Data>
							ofs << builders[o].getNumBrick() << " " << builders[o].getNumEnergy() << " " << builders[o].getNumGlass() << " " << builders[o].getNumHeat() << " " << builders[o].getNumWifi();
							ofs << " r";
							vector<int> path = builders[o].getPath();
							vector<int> address = builders[o].getAddress();

							int temp7 = path.size();
							for(int q = 0; q < temp7; q++){
								ofs << " " << path[q];
							}
							ofs << " h";
							int temp8 = address.size();
							for(int q = 0; q < temp8; q++){
								ofs << " " << address[q] << " " << addresses[address[q]].getBuildingType();
							}

				    	ofs << endl;
				    }

				    for (int q = 0; q < 19; ++q) { // prints <board>
				        if (tiles[q].getResource() == "BRICK") {
				            if (q == 0) {
				                ofs << 0 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 0 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "ENERGY") {
				            if (q == 0) {
				                ofs << 1 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 1 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "GLASS") {
				            if (q == 0) {
				                ofs << 2 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 2 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "HEAT") {
				            if (q == 0) {
				                ofs << 3 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 3 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "WIFI") {
				            if (q == 0) {
				                ofs << 4 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 4 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "PARK") {
				            if (q == 0) {
				                ofs << 5 << " " << 7;
				            }
				            else {
				                ofs << " " << 5 << " " << 7;
				            }
				        }
				    }
						ofs << endl;

				    ofs.close(); // closes file

				} else if(userCMD == "help") {
					cout << "Valid commands:" << endl;
					cout << "board" << endl;
					cout << "status" << endl;
					cout << "residences" << endl;
					cout << "build-road <path#>" << endl;
					cout << "build-res <housing#>" << endl;
					cout << "improve <housing#>" << endl;
					cout << "trade <colour> <give> <take>" << endl;
					cout << "next" << endl;
					cout << "save <file>" << endl;
					cout << "help" << endl;
				} else {
					cout << "Invalid Command." << endl;
				}
			}
		}
	}

	cout <<"Would you like to play again?" << endl;
	string newRound;
	cout << ">";
	cin >> newRound;
	if(newRound == "yes"){
		// Need to reset the game
		builders.clear();

		paths.clear();
		addresses.clear();
		tiles.clear();
		boardLayout(def, " ",builders);
		builders.emplace_back(Builder(0,"Blue"));
		builders.emplace_back(Builder(1,"Red"));
		builders.emplace_back(Builder(2,"Orange"));
		builders.emplace_back(Builder(3,"Yellow"));
		win = false;
	} else{
		// End game
		break;
	}
	}
  return 0;

}
