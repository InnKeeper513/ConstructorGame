#include "Builder.h"

using namespace std;

Builder::Builder(int number, string color, int numPoints, int numBrick, int numEnergy, int numGlass, int numHeat, int numWifi):
	name{color[0]},
	number{number},
	color{color},
	numPoints{numPoints},
	numBrick{numBrick},
	numEnergy{numEnergy},
	numGlass{numGlass},
	numHeat{numHeat},
	numWifi{numWifi}
	{}


int Builder::getNumber()
{
	return this->number;
}
string Builder::getColor()
{
	return this->color;
}

int Builder::getNumPoints()
{
	return this->numPoints;
}
int Builder::getNumBrick()
{
	return this->numBrick;
}

int Builder::getNumEnergy()
{
	return this->numEnergy;
}

int Builder::getNumGlass()
{
	return this->numGlass;
}

int Builder::getNumHeat()
{
	return this->numHeat;
}

int Builder::getNumWifi()
{
	return this->numWifi;
}

void Builder::status(){
	cout << color << " has " << numPoints << " building points, " << numBrick << " brick, "
	<< numEnergy << " energy, " << numGlass << " glass, " << numHeat << " heat, and " << numWifi
	<< " WiFi." << endl;
}

void Builder::incrPoints(int add){
		numPoints += add;
}

void Builder::addBrick(int add){
	numBrick += add;
}
void Builder::addEnergy(int add){
	numEnergy += add;
}
void Builder::addGlass(int add){
	numGlass += add;
}
void Builder::addHeat(int add){
	numHeat += add;
}
void Builder::addWifi(int add){
	numWifi += add;
}
void Builder::removeBrick(int remove){
	numBrick -= remove;
}
void Builder::removeEnergy(int remove){
	numEnergy -= remove;
}
void Builder::removeGlass(int remove){
	numGlass -= remove;
}
void Builder::removeHeat(int remove){
	numHeat -= remove;
}
void Builder::removeWifi(int remove){
	numWifi -= remove;
}
// Add address
void Builder::addAddress(int set){

	// Set the owner name for the address
	addresses[set].setOwner(name);
	// Add the address to the list of address the owner owns
	address.emplace_back(set);
}

void Builder::addPath(int set){
	paths[set].setOwner(name);
	path.emplace_back(set);
}

bool Builder::checkImprove(int check){
		int temp = address.size();
		for(int i = 0; i < temp; i++){
			// It cannot be a tower
			if(address[i] == check && addresses[address[i]].getBuildingType() != "T")
				return true;
			else if(address[i] == check && addresses[address[i]].getBuildingType() == "T")
				return false;
		}
		return false;
}

void Builder::checkBuildingResource(int check){

	if(addresses[check].getBuildingType() == "B"){
				if(numGlass >= 2 && numHeat >= 3){
					numGlass -= 2;
					numHeat -= 3;
					numPoints ++;
					notifyObservers(Subscriptions::Address, getColor(), check);
				}else{
					cout << "You do not have enough resources." << endl;
				}
	} else if(addresses[check].getBuildingType() == "H"){
				if(numBrick >= 3 && numEnergy >= 2 && numGlass >= 2 && numWifi >= 1 && numHeat >= 2){
					numBrick -= 3;
					numEnergy -= 2;
					numGlass -= 2;
					numWifi -= 1;
					numHeat -= 22;
					numPoints ++;
					notifyObservers(Subscriptions::Address, getColor(), check);
				}else{
					cout << "You do not have enough resources." << endl;
				}
	}
}

bool Builder::checkAdjacent(int check){
	// Get all the neighbors of the checking address
	vector<int> vecs = addresses[check].getNeighbor();

	// Loop through all of its adjacent addresses to see if all of them don't have owner
	int k = vecs.size();
	for(int i = 0; i < k; i++){
		stringstream temp ;
		temp << color[1];
		string character;
		temp >> character;

		// If one neighbor contains an owner, then cannot build here.
		if(addresses[vecs[i]].getBuildingType() != "N" && addresses[vecs[i]].getBuilder() != character){

			return false;
		}
	}
	return true;
}

// Check if any of the owner's path is connencted to the desired address
bool Builder::checkAdjacentPath(int check){
	stringstream temp ;
	temp << color[0];
	string character;
	temp >> character;
	int k = path.size();
	for(int i = 0; i < k; i++){

		for(int j = 0; j < 2; j++){
			if(addresses[paths[path[i]].getConnectedAddress()[j]].getBuilder() == character && addresses[paths[path[i]].getConnectedAddress()[j]].getNumber() == check){

				return true;
			}
		}
	}
	return false;
}

vector<int> Builder::getAddress(){
	return address;
}
vector<int> Builder::getPath(){
	return path;
}

bool Builder::pathNeighbors(int check){

	stringstream ss;
	ss << color[0];
	string temp;
	ss >> temp;
	int k = paths[check].getNeighborPath().size();
	for(int i = 0; i < k; i++){
			if(paths[paths[check].getNeighborPath()[i]].getBuilder() == temp)
				return true;
	}

	return false;
}

bool Builder::pathAddress(int check){
	// Check through the neighbour addresses

	for(int i = 0; i < 2; i++){
		stringstream ss;
		ss << color[0];
		string temp;
		ss >> temp;
			if(addresses[paths[check].getConnectedAddress()[i]].getBuilder() == temp)
				return true;
	}

	return false;
}

int Builder::totResource(){
	return numBrick + numHeat + numEnergy + numGlass + numWifi;
}
