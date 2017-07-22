#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "Tile.h"

using namespace std;
class Board
{
public:
	Board();
	~Board();
	friend ostream &operator<<(ostream &output, Board &board);
	friend istream &operator>>(istream &input, Board &board);
	void AddLine(string line);
	void Print(ostream &output);
	void BuildTiles();
private:
	string* boardArray;
	int lines;
	Tile* tiles;
	Address* addresses;
	Path* pathes;
	int numTiles;
	int numAddresses;
	int numPathes;
	int FindMaxNumber(string findStr);
	void BuildAddresses();
	void BuildPathes();
	void CreateTiles();
	void AddTile(int number, string resource, int value, int row, int col);

};
