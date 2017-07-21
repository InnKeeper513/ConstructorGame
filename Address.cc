#include "Address.h"

using namespace std;

Address::Address(int number):number{number},owner{"N"}{}

string Address::getBuilder()
{
	return owner;
}
string Address::getBuildingType()
{
	return buildingType;
}

void Address::setBuildingType(string set){
	buildingType = set;
}

int Address::getNumber()
{
	return number;
}

void Address::setOwner(string set){
	owner = set;
}

bool Address::isInNeighborAddress(int number)
{
	for(int i = 0; i < addresses.size(); i++){
		if(addresses[i] == number)
			return true;
	}
	return false;

}

void Address::addAddress(int add)
{
	addresses.emplace_back(add);
}
