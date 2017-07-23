
#ifndef _TILE_H_
#define _TILE_H_
#include <string>
#include "Address.h"
#include "Path.h"
#include <vector>

class Tile
{
public:
	Tile(int number, std::string resource, int value);
	int getNumber();
	std::string getResource();
	int getValue();
	std::vector<int> getAddress();
	void addAddress(int add);

private:
	std::vector<int> tileAddress;
	int number;
	std::string resource;
	int value;
};
#endif
