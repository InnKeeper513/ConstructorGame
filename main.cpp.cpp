// TianA5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

const string  BarodFileName = "c:\\Users\\Mike-Mac\\documents\\visual studio 2015\\Projects\\TianA5\\TianA5\\Board.txt";
int main()
{
	Board board;
	ifstream file(BarodFileName);
	file >> board;

	cout << board;
	file.close();
	char  c;
	cin >> c;
	// random number for the dice
	int rand;

	// The beginning of game.
	vecctor<Builders> builders;
	builders.emplace_back(0,"Blue");
	builders.emplace_back(1,"Red");
	builders.emplace_back(2,"Orange");
	builders.emplace_back(3,"Yellow");

	// Adding 2 initial address locations for the player
	//TODO Address need to be valid
	// - It must exist
	// - It cannot collapse with other player's address
	for(int i = 0; i < 4; i++){
		int tempAdd;
		cout << "Builder " << builders[i].getColor() << " , where do you want to build a basement?" << endl;
		cin >> tempAdd;
		builders[i].addAddress(tempAdd);
	}
	for(int j = 3; j >= 0; j++){
		int tempAdd2;
		cout << "Builder " << builders[i].getColor() << " , where do you want to build a basement?" << endl;
		cin >> tempAdd2;
		builders[i].addAddress(tempAdd2);
	}

	// Print the updated board
	cout << board;

	// Begin the game ********************

	// Beginning of Turn *****************
	// Loop through the game
	while(true){

		// Every turn, there will be 4 player inputing commands
		for(int i = 0; i < 4; i++){
			cout << "Builder " << builders[i].GetColor() << "'s turn'" << endl;
			// print the builder's status
			builders[i].status();

			// Enter rolling dice commands
			while(true){
				string diceCMD;

				cout << "Enter 'load' or 'fair' dice"
				cin >> diceCMD;
				Dice dice(diceCMD);
				// Get the rolled number
				rand = dice.roll();

				if(diceCMD == "roll"){
					break;
				}
			}

	// End Beginning of Turn *********************
	// Begin During the Turn *********************



		}
	}







    return 0;
}
