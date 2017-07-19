#pragma once
#include <string>
using namespace std;
class Builder
{
public:
	Builder();
	~Builder();
	int GetNumber();
	string GetColor();
	int GetNumPoints();
	int GetNumBrick();
	int GetNumEnergy();
	int GetNumGlass();
	int GetNumHeat();
	int GetNumWiFi();

private:
	int number;
	string color;
	int numPoints;
	int numBrick;
	int numEnergy;
	int numGlass;
	int numHeat;
	int numWiFi;
};

