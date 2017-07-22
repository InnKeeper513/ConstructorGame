#ifndef _BUILDER_H_
#define _BUILDER_H_
#include <string>
#include <vector>
#include <iostream>
#include "Address.h"
#include "Board.h"
#include "Path.h"

class Builder{
	std::string name;
	int number;
	std::string color;
	int numPoints;
	int numBrick;
	int numEnergy;
	int numGlass;
	int numHeat;
	int numWifi;
	std::vector<int> address;
	std::vector<int> path;
public:
	Builder();
	Builder(int number, std::string color, int numPoints=0, int numBrick=0,
		int numEnergy=0, int numGlass=0, int numHeat=0, int numWifi=0);
	int getNumber();
	std::string getColor();
	int getNumPoints();
	int getNumBrick();
	int getNumEnergy();
	int getNumGlass();
	int getNumHeat();
	int getNumWifi();
	// Added
	void printData();
	void trade(Builder&, std::string, std::string);
	void status();
	int incrPoints(int);
	int addBrick(int);
	int addEnergy(int);
	int addGlass(int);
	int addHeat(int);
	int addWifi(int);
	int removeBrick(int);
	int removeEnergy(int);
	int removeGlass(int);
	int removeHeat(int);
	int removeWifi(int);
	int addAddress(int);
	int addPath(int);
	bool checkImprove(int);
	bool checkAdjacent(int);
	bool checkAdjacentPath();
	void checkBuildingResource(int);
	std::vector<int> getAddress();
	std::vector<int> getPath();

	// Check if the selected path has adjacent path built to it
	bool pathNeighbors(int);
		// Check if the selected path has adjacent player address built to it
	bool pathAddress(int);
};

#endif
