
#ifndef _ADDRESS_H_
#define _ADDRESS_H_
#include <string>
#include "Path.h"
#include <vector>

class Address{
public:
	Address();
	Address(int number);
	std::string GetBuilder();
	std::string GetBuildingType();
	int GetNumber();
	void addAddress(int);
	// Modified
	void setOwner(std::string);
private:

	int number;
	// Modified
	std::string owner;
	std::string buildingType;

	std::vector<int> addresses;

	bool isInNeighborAddress(int number);
};

#endif
