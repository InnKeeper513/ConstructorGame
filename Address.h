#pragma once

#include <string>
#include "Builder.h"
#include "Path.h"
class Address
{
public:
	Address();
	Address(int number);
	~Address();
	Builder* GetBuilder();
	std::string GetBuildingType();
	int GetNumber();
	void AddNeighborAddress(Address* address);
	void PushNeighborAddress(Address* address);
	void AddNeighborPath(Path* path);
private:
	int number;
	Builder* owner;
	std::string buildingType;
	Address** neighborAddresses;
	int numNeighborAddresses;
	Path** neighborPathes;
	int numNeighborPathes;
	bool isInNeighborAddress(int number);
	bool isInNeighborPath(int number);
};
