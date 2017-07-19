#include "Builder.h"

using namespace std;


Builder::Builder(int number, string color, int numPoints, int numBrick, int numEnergy,
	int numGlass, int numHeat, int numWifi):
	number{number},
	color{color},
	numPoints{numPoints},
	numBrick{numBrick},
	numEnergy{numEnergy},
	numGlass{numGlass},
	numHeat{numHeat},
	numWifi{numWifi}
	{}

Builder::~Builder()
{
}

int Builder::GetNumber()
{
	return this->number;
}
string Builder::GetColor()
{
	return this->color;
}

int Builder::GetNumPoints()
{
	return this->numPoints;
}
int Builder::GetNumBrick()
{
	return this->numBrick;
}

int Builder::GetNumEnergy()
{
	return this->numEnergy;
}

int Builder::GetNumGlass()
{
	return this->numGlass;
}

int Builder::GetNumHeat()
{
	return this->numHeat;
}

int Builder::GetNumWiFi()
{
	return this->numWiFi;
}
