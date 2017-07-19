#include "Builder.h"



Builder::Builder()
{
}


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

