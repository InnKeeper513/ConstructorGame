#include <iostream>
#include <vector>
#include "Dice.h"
#include "Board.h"
#include "Builder.h"
#include <string>
//#include "Address.h"

using namespace std;

int main()
{
	// WRITE THE COMMAND LINE HERE
	string commandLine;

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
		cout << "Builder " << builders[i].GetColor() << " , where do you want to build a basement?" << endl;
		cout << ">";
		cin >> tempAdd;
		builders[i].addAddress(tempAdd);
	}
	for(int j = 3; j >= 0; j--){
		int tempAdd2;
		cout << "Builder " << builders[j].GetColor() << " , where do you want to build a basement?" << endl;
		cout << ">";
		cin >> tempAdd2;
		builders[j].addAddress(tempAdd2);
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
			if(builders[i].GetNumPoints() >= 10){
				cout << "Player " << builders[i].GetColor() << " win!";
				win = true;
				break;
			}

			cout << "Builder " << builders[i].GetColor() << "'s turn'" << endl;
			// print the builder's status
			builders[i].status();

			// Enter rolling dice commands
			while(true){
				string diceCMD;

				cout << "Enter 'load' or 'fair' dice" << endl;
				cout << ">";
				cin >> diceCMD;
				Dice dice(diceCMD);
				// Get the rolled number
				rand = dice.rollDice();
				cin >> diceCMD;
				if(diceCMD == "roll"){
					break;
				}
			}

	// End Beginning of Turn *********************
	// Begin During the Turn *********************
			// User is able to call the list of commands until end turn
			while(true){
				string userCMD;
				cout << ">";
				cin >> userCMD;

				if(userCMD == "board")
					cout << board;
				else if(userCMD == "status"){
					for(int i = 0; i < 3; i++){
						builders[i].status();
					}
				} else if(userCMD == "residences") {
					// print all the completed residences
				} else if(userCMD == "build-road") {
					cin >> userCMD;
					istringstream ss{userCMD};
					int roadNumber;
					ss >> roadNumber;
					// Build the road at roadNumber
				} else if(userCMD == "build-res") {
					cin >> userCMD;
					istringstream ss{userCMD};
					int resNumber;
					ss >> resNumber;
					// Build the road at roadNumber
				} else if(userCMD == "improve") {
					cin >> userCMD;
					istringstream ss{userCMD};
					int improveNumber;
					ss >> improveNumber;
					// Improve the residence at the improveNumebr location
				} else if(userCMD == "trade") {

				} else if(userCMD == "next") {
					break;
				} else if(userCMD == "save") {

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
