
#ifndef _TILE_H_
#define _TILE_H_
#include <string>
#include "Address.h"
#include "Path.h"
#include <vector>

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
	void addAddress(int);
private:
	std::vector<int> tileAddress;
	int number;
	std::string resource;
	int value;
	int numAddress;
	int numpath;
	std::string geese;
};
#endif
