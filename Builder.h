#pragma once
#include <string>
#include <vector>
#include "Address.h"
#include "Path.h"

#ifndef _BUILDER_H_
#define _BUILDER_H_

class Builder
{
public:
	Builder(int number, std::string color, int numPoints=0, int numBrick=0,
		int numEnergy=0, int numGlass=0, int numHeat=0, int numWifi=0);
	~Builder();
	int GetNumber();
	std::string GetColor();
	int GetNumPoints();
	int GetNumBrick();
	int GetNumEnergy();
	int GetNumGlass();
	int GetNumHeat();
	int GetNumWiFi();
	// Added
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
	int addAddress(Address&);
	int addPath(Path&);
	vector<Address> getAddress();
	vector<Path> getPath();

private:

	vector<Address> address;
	vector<Path> path;
	int number;
	std::string color;
	int numPoints;
	int numBrick;
	int numEnergy;
	int numGlass;
	int numHeat;
	int numWiFi;
};

#endif
