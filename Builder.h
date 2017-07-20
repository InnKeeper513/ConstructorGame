#ifndef _BUILDER_H_
#define _BUILDER_H_
#include <string>
#include <vector>
#include <iostream>
#include "Address.h"
#include "Path.h"
class Builder{
	int number;
	std::string color;
	int numPoints;
	int numBrick;
	int numEnergy;
	int numGlass;
	int numHeat;
	int numWifi;
	std::vector<Address> address;
	std::vector<Path> path;
public:
	Builder();
	Builder(int number, std::string color, int numPoints=0, int numBrick=0,
		int numEnergy=0, int numGlass=0, int numHeat=0, int numWifi=0);
	int GetNumber();
	std::string GetColor();
	int GetNumPoints();
	int GetNumBrick();
	int GetNumEnergy();
	int GetNumGlass();
	int GetNumHeat();
	int GetNumWifi();
	// Added
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
	std::vector<Address> getAddress();
	std::vector<Path> getPath();
};

#endif
