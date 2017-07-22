#pragma once

#include <string>
#include "Builder.h"
#include "Path.h"
using namespace std;
class Address
{
public:
	Address();
	Address(int number);
	~Address();
	Builder* GetBuilder();
	string GetBuildingType();
	int GetNumber();
	void AddNeighborAddress(Address* address);
	void PushNeighborAddress(Address* address);
	void AddNeighborPath(Path* path);
private:
	int number;
	Builder* owner;
	string buildingType;
	Address** neighborAddresses;
	int numNeighborAddresses;
	Path** neighborPathes;
	int numNeighborPathes;
	bool isInNeighborAddress(int number);
	bool isInNeighborPath(int number);
};


