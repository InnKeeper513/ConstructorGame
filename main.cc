#include <iostream>
#include <vector>
#include "Dice.h"
#include "Board.h"
#include "Builder.h"
#include <string>
#include <stdlib.h> // for srand() random number generator
#include <fstream> // for save to file
//#include "Address.h"

using namespace std;

int main()
{

	// WRITE THE COMMAND LINE HERE
	string commandLine;
	getline(commandLine);
	string word;
	bool load_flag = false;
	while (commandLine >> word) {
	    if (word == "-seed") {
	        int seed;
	        commandLine >> seed;
	        srand(seed);
	    }
	    else if (word == "-load") {
	        load_flag = true;
	        string game_file;
	        commandLine >> game_file;
	        //
	    }
	    else if (word == "-board") {
	        string board_file;
	        commandLine >> board_file;
	        //
	    }
	    else if (word == "-random-board") {
	        if (load_flag) {
	            // ignore command
	        }
	        else {
	            // randomly generate tiles
	            vector<string> res = {"WIFI","WIFI","WIFI","HEAT","HEAT","HEAT","BRICK","BRICK","BRICK","BRICK","ENERGY","ENERGY","ENERGY","ENERGY","GLASS","GLASS","GLASS","GLASS","PARK"};
	            vector<int> vals = {2,3,3,4,4,5,5,6,6,8,8,9,9,10,10,11,11,12};
	            for (int i = 0; i < 19; ++i) {  // GO TO TILE TO IMPLEMENT public SETRES AND SETVAL
	                k = rand() % res.size();
	                tiles[i].setRes(res[k]);
	                res.erase(res.begin() + k);
	                
	                if (res[k] != "PARK") {
	                    j = rand() % vals.size();
	                    tiles[i].setVal(vals[j]);
	                    vals.erase(vals.begin() + j);
	                }
	            }
	        }
	    }
	}

	// WRITE THE COMMAND LINE HERE

	Board board;
	cout << board;

	//ifstream file(BoardFileName);
	//file >> board;
	bool win = false;
	//cout << board;
	//file.close();
	// random number for the dice
	int rand;

	// The beginning of game.
	vector<Builder> builders;
	builders.emplace_back(Builder(0,"Blue"));
	builders.emplace_back(Builder(1,"Red"));
	builders.emplace_back(Builder(2,"Orange"));
	builders.emplace_back(Builder(3,"Yellow"));

	// Continue the game
	while(true){
	// Adding 2 initial address locations for the player
	//TODO Address need to be valid
	// - It must exist
	// - It cannot collapse with other player's address
	for(int i = 0; i < 4; i++){
		int tempAdd;
		cout << "Builder " << builders[i].getColor() << " , where do you want to build a basement?" << endl;
		cout << ">";
		cin >> tempAdd;
		builders[i].addAddress(tempAdd);
		addresses[tempAdd].setBuildingType("B");
	}
	for(int j = 3; j >= 0; j--){
		int tempAdd2;
		cout << "Builder " << builders[j].getColor() << " , where do you want to build a basement?" << endl;
		cout << ">";
		cin >> tempAdd2;
		builders[j].addAddress(tempAdd2);
		addresses[tempAdd2].setBuildingType("B");
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
				rand = dice.rollDice();
				if(rand == 7){
					// set the goose stuff
				} else {

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
					for(int i = 0; i < 3; i++){
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

				} else if(userCMD == "build-road") {

					cin >> userCMD;
					istringstream ss{userCMD};
					int roadNumber;
					ss >> roadNumber;

					// TODO need to check if the road is valid and if resource is enough
					// Cost of building a road
					if(builders[i].getNumHeat() >= 1 && builders[i].getNumWifi() >= 1){
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
					// Build the road at roadNumber


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

				} else if(userCMD == "next") {
					break;
				} else if(userCMD == "save") {
				    cin >> userCMD;
				    std::ofstream ofs (userCMD, std::ofstream::out);
				    ofs << builderColor << endl; // prints <curTurn>
				    
				    for (int i = 0; i < 4; i++) {// prints <builder(0-3)Data>
				        ofs << builders[i].printData();
				        ofs << " " << r << " ";
				        vector<int> path = builders[i].getPath();
				        int pathSize = path.size();
				        for (int k = 0; k < pathSize; ++k) {
				            ofs << path[k]<< " ";
				        }
				        ofs << h;
				        vector<int> address = builders[i].getAddress();
				        int addressSize = address.size();
				        for (int k = 0; k < addressSize; ++k) {
				            ofs << " " << address[k].getNumber() << " " << address[k].getBuildingType();
				        }
				        ofs << endl;
				    }
				    
				    for (int i = 0; i < tiles.size(); ++i) { // prints <board>
				        if (tiles[i].getResource() == "BRICK") {
				            if (i = 0) {
				                ofs << 0 << " " << tiles[i].getValue();
				            }
				            else {
				                ofs << " " << 0 << " " << tiles[i].getValue();
				            }
				        }
				        else if (tiles[i].getResource() == "ENERGY") {
				            if (i = 0) {
				                ofs << 1 << " " << tiles[i].getValue();
				            }
				            else {
				                ofs << " " << 1 << " " << tiles[i].getValue();
				            }
				        }
				        else if (tiles[i].getResource() == "GLASS") {
				            if (i = 0) {
				                ofs << 2 << " " << tiles[i].getValue();
				            }
				            else {
				                ofs << " " << 2 << " " << tiles[i].getValue();
				            }
				        }
				        else if (tiles[i].getResource() == "HEAT") {
				            if (i = 0) {
				                ofs << 3 << " " << tiles[i].getValue();
				            }
				            else {
				                ofs << " " << 3 << " " << tiles[i].getValue();
				            }
				        }
				        else if (tiles[i].getResource() == "WIFI") {
				            if (i = 0) {
				                ofs << 4 << " " << tiles[i].getValue();
				            }
				            else {
				                ofs << " " << 4 << " " << tiles[i].getValue();
				            }
				        }
				        else if (tiles[i].getResource() == "PARK") {
				            if (i = 0) {
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
