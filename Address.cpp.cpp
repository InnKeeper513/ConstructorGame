#include "Address.h"

Address::Address()
{
	this->number = 0;
	this->buildingType = "";
	this->owner = NULL;
	this->numNeighborAddresses = 0;
	this->neighborAddresses = new Address*[0];
	this->numNeighborPathes = 0;
	this->neighborPathes = new Path*[0];
}

Address::Address(int number):Address()
{
	this->number = number;
}

Address::~Address()
{
	//delete this->neighborAddresses;
	//this->neighborAddresses = NULL;
	//delete this->neighborPathes;
	//this->neighborPathes= NULL;
}

Builder* Address::GetBuilder()
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
	for (int i=0;i<this->numNeighborAddresses;i++)
	{
		if (this->neighborAddresses[i]->number == number)
			return true;
	}
	return false;
}

bool Address::isInNeighborPath(int number)
{
	for (int i = 0;i<this->numNeighborPathes;i++)
	{
		if (this->neighborPathes[i]->GetNumber() == number)
			return true;
	}
	return false;
}


void Address::PushNeighborAddress(Address* address)
{
	if (!this->isInNeighborAddress(address->number) && address->number !=this->number)
	{
		Address** newArr = new Address*[this->numNeighborAddresses + 1];
		copy(this->neighborAddresses, this->neighborAddresses + this->numNeighborAddresses, newArr);
		delete[] this->neighborAddresses;
		this->neighborAddresses = newArr;

		this->neighborAddresses[this->numNeighborAddresses] = address;
		this->numNeighborAddresses++;

	}
}
void Address::AddNeighborAddress(Address* address)
{
	this->PushNeighborAddress(address);
	address->PushNeighborAddress(address);
}
void Address::AddNeighborPath(Path* path)
{
	if (!this->isInNeighborPath(path->GetNumber()))
	{
		Path** newArr = new Path*[this->numNeighborPathes + 1];
		copy(this->neighborPathes, this->neighborPathes + this->numNeighborPathes, newArr);
		delete[] this->neighborPathes;
		this->neighborPathes = newArr;

		this->neighborPathes[this->numNeighborPathes] = path;
		this->numNeighborPathes++;
	}
}

