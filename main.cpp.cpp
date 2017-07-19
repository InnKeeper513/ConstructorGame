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

	// The beginning of game.
	vecctor<Builders> builders;
	builders.emplace_back(0,"Blue");
	builders.emplace_back(1,"Red");
	builders.emplace_back(2,"Orange");
	builders.emplace_back(3,"Yellow");

	for(int i = 0; i < 4; i++){
		cout << "Builder " << builders[i].getColor() << " , where do you want to build a basement?" << endl;
		builders[i].
	}
	for(int j = 3; j >= 0; j++){

	}







    return 0;
}
