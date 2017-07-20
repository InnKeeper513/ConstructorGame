#include "Builder.h"

using namespace std;

Builder::Builder(int number, string color, int numPoints, int numBrick, int numEnergy, int numGlass, int numHeat, int numWifi):
	number{number},
	color{color},
	numPoints{numPoints},
	numBrick{numBrick},
	numEnergy{numEnergy},
	numGlass{numGlass},
	numHeat{numHeat},
	numWifi{numWifi}
	{}


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

int Builder::GetNumWifi()
{
	return this->numWifi;
}

// Added
void Builder::trade(Builder&, string give, string take){

}

void Builder::status(){
	cout << color << " has " << numPoints << " building points, " << numBrick << " brick, "
	<< numEnergy << " energy, " << numGlass << " glass, " << numHeat << " heat, and " << numWifi
	<< " WiFi." << endl;
}

int Builder::incrPoints(int add){
		numPoints += add;
}

int Builder::addBrick(int add){
	numBrick += add;
}
int Builder::addEnergy(int add){
	numEnergy += add;
}
int Builder::addGlass(int add){
	numGlass += add;
}
int Builder::addHeat(int add){
	numHeat += add;
}
int Builder::addWifi(int add){
	numWifi += add;
}
int Builder::removeBrick(int remove){
	numBrick -= remove;
}
int Builder::removeEnergy(int remove){
	numEnergy -= remove;
}
int Builder::removeGlass(int remove){
	numGlass -= remove;
}
int Builder::removeHeat(int remove){
	numHeat -= remove;
}
int Builder::removeWifi(int remove){
	numWifi -= remove;
}
// Add address
int Builder::addAddress(int set){
	address.emplace_back(Address(set));
}
int Builder::addPath(int set){
	path.emplace_back(Path(set));
}
vector<Address> Builder::getAddress(){
	return address;
}
vector<Path> Builder::getPath(){
	return path;
}
