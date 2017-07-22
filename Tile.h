
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
	int GetNumber();
	std::string GetResource();
	int GetValue();
	void SetGeese(int);
	std::string GetGeese();
	void addAddress(int add);
	void SetPos(int row, int col);
private:
	std::vector<int> tileAddress;
	int number;
	std::string resource;
	int value;
	int numAddress;
	int numpath;
	std::string geese;
	int row;
	int col;
};
#endif
