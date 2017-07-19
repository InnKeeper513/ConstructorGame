#pragma once
#include <string>
#include <vector>

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
	int addAddress(int);
	int addPath(int);
	vector<int> getAddress();
	vector<int> getPath();

private:

	vector<int> address;
	vector<int> path;
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
