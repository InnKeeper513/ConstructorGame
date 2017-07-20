
#ifndef _ADDRESS_H_
#define _ADDRESS_H_
#include <string>
#include "Path.h"

class Address{
public:
	Address();
	Address(int number);
	std::string GetBuilder();
	std::string GetBuildingType();
	int GetNumber();
	void AddNeighborAddress(Address* address);
	void PushNeighborAddress(Address* address);
	void AddNeighborPath(Path* path);
	// Modified
	void setOwner(std::string);
private:
	int number;
	// Modified
	std::string owner;
	std::string buildingType;
	Address** neighborAddresses;
	int numNeighborAddresses;
	Path** neighborPathes;
	int numNeighborPathes;
	bool isInNeighborAddress(int number);
	bool isInNeighborPath(int number);
};

#endif
