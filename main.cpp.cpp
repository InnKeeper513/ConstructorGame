// TianA5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
    return 0;
}

