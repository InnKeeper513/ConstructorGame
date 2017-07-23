#include <iostream>
#include <vector>
#include "Dice.h"
#include "Board.h"
#include "Builder.h"
#include <string>
#include <sstream>
#include <stdlib.h> // for srand() random number generator
#include <fstream> // for save to file
//#include "Address.h"

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
							tiles.emplace_back(Tile(counter, "ROAD", input_line));
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

int main()
{
	Board board;
	cout << "Press enter to load the dafault board" << endl;
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
			def = false;
	    if (word == "-seed") {
	        int seed;
	        ss >> seed;
	        srand(seed);
	    } else if (word == "-load") {
				load_flag = true;
				string game_file;
				ss >> game_file;
				ifstream myfile;
				myfile.open (game_file);

				myfile >> currentTurn; // read in <curTurn>

				string line;
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

					int path;
					while (s >> path) {
						builders[i].addPath(path);
					}

					int address;
					string residence;
					while (s >> address) {
						s >> residence;
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
									tiles.emplace_back(Tile(counter, "ROAD", input_line));
							}
							counter ++;
				}

			} else if (word == "-board") {
	        string board_file;
					ss >> board_file;
	        boardLayout(false, board_file, builders);

	    } else if (word == "-random-board") {
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
									if(res[k] != "PARK"){
										j = rand() % vals.size();
										tiles.emplace_back(i,res[k],vals[j]);
									} else {
										tiles.emplace_back(i,res[k],vals[j]);
									}
	                res.erase(res.begin() + k);
									vals.erase(vals.begin() + j);

	            }
	        }
	    }
	}

	boardLayout(def, " ",builders);

	cout << board;

	//ifstream file(BoardFileName);
	//file >> board;
	bool win = false;

	int random;

	// Continue the game
	while(true){
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

	board.addTileDependency();
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

				cout << "Enter 'load' or 'fair' dice" << endl;
				cout << ">";
				cin >> diceCMD;
				Dice dice(diceCMD);
				// Get the rolled number
				random = dice.rollDice();

				if(random == 7){
					// set the goose stuff


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
							for(int k = 0; k < tiles.size(); k++){
								// The tile value is equivalent to the value of the dice

								if(tiles[k].getValue() == random && tiles[k].getResource() != "Park" && geeseLocation != k){
									// get the address numbers in the tile
									vector<int> allTileAddress = tiles[k].getAddress();
									for(int p = 0; p < allTileAddress.size(); p ++){
//										cout << " Neighbor Address: " << allTileAddress[p] << " Builder: " << addresses[allTileAddress[p]].getBuilder() << " Color " << builders[u].getColor() << endl;

										if(addresses[allTileAddress[p]].getBuilder() == builders[u].getColor().substr(0,1)){
											playerGain = true;
											gained = true;
											if(addresses[allTileAddress[p]].getBuildingType() == "B"){
												// gained the amount of resource
												resourceDistribution(tiles[k].getResource(), 1, heat, energy, brick, wifi, glass);
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
					for(int j = 0; j < builders[i].getAddress().size(); j++){
						if(addresses[builders[i].getAddress()[j]].getBuildingType() == "B")
							cout << builders[i].getAddress()[j] << " ";
					}
					// print houses
					cout << "H: ";
					for(int j = 0; j < builders[i].getAddress().size(); j++){
						if(addresses[builders[i].getAddress()[j]].getBuildingType() == "H")
							cout << builders[i].getAddress()[j] << " ";
					}
					// print towers
					cout << "T: ";
					for(int j = 0; j < builders[i].getAddress().size(); j++){
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
					if(builders[i].getNumHeat() >= 1 && builders[i].getNumWifi() >= 1 &&
					(builders[i].pathNeighbors(roadNumber) || builders[i].pathAddress(roadNumber))){
						// If contain enough resources, build the raod.
						builders[i].removeHeat(1);
						builders[i].removeWifi(1);
					} else {
						cout << "You do not have enough resources." << endl;
					}
					paths[roadNumber].upgrade(builderColor);
					// Build the road at roadNumber
				} else if(userCMD == "build-res") {
					cin >> userCMD;
					istringstream ss{userCMD};
					int resNumber;
					ss >> resNumber;

					// Check if the residence address is valid
					// If yes build a basement
					if(builders[i].checkAdjacent(resNumber) &&
					 addresses[resNumber].getBuildingType() == "B" &&
				 	 builders[i].checkAdjacentPath()){

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
							addresses[resNumber].setBuildingType("B");
							addresses[resNumber].setOwner(builders[i].getColor());
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
						cout << "You cannot build here.";
					}

				} else if(userCMD == "trade") {
						string builder2;
						string resource1;
						string resource2;
						// TODO need to check if these inputs are valid
						cin >> builder2;
						cin >> resource1;
						cin >> resource2;

						int playerNum = 0;
						for(int k = 0; k < 4; k++){
							if(builders[k].getColor() == builder2){
								playerNum = k;
								break;
							}
						}

						cout << builders[i].getColor() << " offers " << builder2 << " one " << resource1 << " for one " << resource2 << endl;
						cout << "Does " << builder2 << " accept this offer?" << endl;
						cout << "Answer with yes / no" << endl;

						string answer;
						cin >> answer;

						// If the answer is yes, then the current builder will gain 1 resource1 and lose 1 resource 2
						// The trading builder will lose 1 resource 1 and gain 1 resource 2
						if(answer == "yes"){
							if(resource1 == "HEAT"){
									builders[i].addHeat(1);
									builders[playerNum].removeHeat(1);
							} else if(resource1 == "WIFI") {
									builders[i].addWifi(1);
									builders[playerNum].removeWifi(1);
							} else if(resource1 == "BRICK") {
									builders[i].addBrick(1);
									builders[playerNum].removeBrick(1);
							} else if(resource1 == "ENERGY") {
									builders[i].addEnergy(1);
									builders[playerNum].removeEnergy(1);
							} else if(resource1 == "GLASS") {
									builders[i].addGlass(1);
									builders[playerNum].removeGlass(1);
							}
							if(resource2 == "HEAT"){
									builders[playerNum].addHeat(1);
									builders[i].removeHeat(1);
							} else if(resource2 == "WIFI") {
									builders[playerNum].addWifi(1);
									builders[i].removeWifi(1);
							} else if(resource2 == "BRICK") {
									builders[playerNum].addBrick(1);
									builders[i].removeBrick(1);
							} else if(resource2 == "ENERGY") {
									builders[playerNum].addEnergy(1);
									builders[i].removeEnergy(1);
							} else if(resource2 == "GLASS") {
									builders[playerNum].addGlass(1);
									builders[i].removeGlass(1);
							}
						} else if(answer == "no"){

						} else {
							// TODO will keep asking until correct command;
							cout << "Invalid Command";
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
							for(int q = 0; i < path.size(); q++){
									ofs << " " << path[q];
							}
							ofs << " h";
							for(int q = 0; q < address.size(); i++){
								ofs << " " << address[q] << " " << addresses[address[q]].getBuildingType();
							}

				      ofs << endl;
				    }

				    for (int q = 0; q < tiles.size(); ++q) { // prints <board>
				        if (tiles[q].getResource() == "BRICK") {
				            if (q = 0) {
				                ofs << 0 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 0 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "ENERGY") {
				            if (q = 0) {
				                ofs << 1 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 1 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "GLASS") {
				            if (q = 0) {
				                ofs << 2 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 2 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "HEAT") {
				            if (q = 0) {
				                ofs << 3 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 3 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "WIFI") {
				            if (q = 0) {
				                ofs << 4 << " " << tiles[q].getValue();
				            }
				            else {
				                ofs << " " << 4 << " " << tiles[q].getValue();
				            }
				        }
				        else if (tiles[q].getResource() == "PARK") {
				            if (q = 0) {
				                ofs << 5 << " " << 7;
				            }
				            else {
				                ofs << " " << 5 << " " << 7;
				            }
				        }
				    }
				    ofs.close(); // closes file

				} else if(userCMD == "help") {
					cout << "Valid commands:" << endl;
					cout << "board" << endl;
					cout << "status" << endl;
					cout << "residences" << endl;
					cout << "build-road <path#>" << endl;
					cout << "build-res <housing#>" << endl;
					cout << "improve <housign#>" << endl;
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
	} else{
		// End game
		break;
	}
	}
  return 0;

}
