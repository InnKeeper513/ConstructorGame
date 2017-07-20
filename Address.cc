#include "Address.h"

using namespace std;

Address::Address()
{

}

Address::Address(int number)
{
	this->number = number;
}

string Address::GetBuilder()
{
	return this->owner;
}
string Address::GetBuildingType()
{
	return this->buildingType;
}
int Address::GetNumber()
{
	return this->number;
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
