#include "Path.h"
#include "Address.h"
#include <algorithm>

using namespace std;



Path::Path(int number):number{number}, owner{"N"}{}

int Path::GetNumber()
{
	return this->number;
}

string Path::getBuilder(){
	return owner;
}

void Path::addPath(int set)
{
	connectedAddress.emplace_back(set);
}

void Path::addNeighbor(int set){
	neighborPath.emplace_back(set);
}

// set the owner of the building
void Path::setOwner(std::string set){
	owner = set;
}

// upgrade the road for the player
void Path::upgrade(string set){
	owner = set;
}
