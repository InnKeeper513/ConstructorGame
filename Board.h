#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Address.h"
#include "Path.h"
#include "Tile.h"

class Board
{

	public:
	Board();
	friend std::ostream &operator<<(std::ostream &output, Board &board);
	void addTileDependency();
};

extern std::vector<Address> addresses;
extern std::vector<Path> paths;
extern std::vector<Tile> tiles;

#endif
