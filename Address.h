
#ifndef _ADDRESS_H_
#define _ADDRESS_H_
#include <string>
#include "Path.h"
#include <vector>

class Address{
// Building type, B H T N
public:
	Address(int number);

	// Get the ownder name of the address
	std::string getBuilder();

	// Return the type of the building
	std::string getBuildingType();

	// Set the type of the buildingType
	void setBuildingType(std::string);

	// Get the address number
	int getNumber();

	// Add adjacent addresses
	void addAddress(int);

	// set the owner of the building
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
