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

// Added
int incrPoints(int add){
		numPoints += add;
}

int addBrick(int add){
	numBrick += add;
}
int addEnergy(int add){
	numEnergy += add;
}
int addGlass(int add){
	numGlass += add;
}
int addHeat(int add){
	numHeat += add;
}
int addWifi(int add){
	numWifi += add;
}
int removeBrick(int remove){
	numBrick -= remove;
}
int removeEnergy(int remove){
	numEnergy -= remove;
}
int removeGlass(int remove){
	numGlass -= remove;
}
int removeHeat(int remove){
	numHeat -= remove;
}
int removeWifi(int remove){
	numWifi -= remove;
}
int addAddress(Address& set){
	address.emplace_back(set);
}
int addPath(Path& set){
	path.emplace_back(set);
}
vector<Address> getAddress(){
	return address;
}
vector<Path> getPath(){
	return path;
}
