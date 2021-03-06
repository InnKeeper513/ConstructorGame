#include "Address.h"

using namespace std;

Address::Address(int number):Tile{},number{number},owner{"N"},buildingType{"N"}{}

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
	int temp = address.size();
	for(int i = 0; i < temp; i++){
		if(address[i] == number)
			return true;
	}
	return false;

}

void Address::addAddress(int add)
{
	address.emplace_back(add);
}

void Address::notify(std::string name, int location){
	string temp = name;
	setOwner(temp);


	if(buildingType == "N")
		buildingType = "B";
	else if(buildingType == "B")
		buildingType = "H";
	else if(buildingType == "H")
		buildingType = "T";

}
Subscriptions Address::subType() const{
	return Subscriptions::Address;
}

void Address::reset(){
	owner = "N";
	buildingType = "N";

}
