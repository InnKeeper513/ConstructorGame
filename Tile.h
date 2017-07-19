#pragma once

#include <string>
#include "Address.h"
#include "Path.h"
using namespace std;

class Tile
{
public:
	Tile();
	Tile(int number, string resource, int value);
	~Tile();
	int GetNumber();
	string GetResource();
	int GetValue();
	void SetGeese();
	string GetGeese();
	void AddAddress(Address *address);
	void AddPath(Path *path);
	void SetPos(int row, int col);
private:
	int number;
	string resource;
	int value;
	Address** addresses;
	int numAddress;
	Path** pathes;
	int numpath;
	string geese;
	int row;
	int col;
};


