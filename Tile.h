
#ifndef _TILE_H_
#define _TILE_H_
#include <string>
#include "Address.h"
#include "Path.h"

class Tile
{
public:
	Tile();
	Tile(int number, std::string resource, int value);
	int GetNumber();
	std::string GetResource();
	int GetValue();
	void SetGeese();
	std::string GetGeese();
	void AddAddress(Address *address);
	void AddPath(Path *path);
	void SetPos(int row, int col);
private:
	int number;
	std::string resource;
	int value;
	Address** addresses;
	int numAddress;
	Path** pathes;
	int numpath;
	std::string geese;
	int row;
	int col;
};
#endif
