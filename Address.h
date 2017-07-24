
#ifndef _ADDRESS_H_
#define _ADDRESS_H_
#include <string>
#include "Path.h"
#include <vector>
#include "Observer.h"
#include "Tile.h"
#include "Subscriptions.h"

class Address : public Tile{
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
	void addAddress(int) override;

	std::vector<int> getNeighbor(){
		return address;
	}

	// set the owner of the building
	void setOwner(std::string) override;

	void notify(std::string, int) override;
	Subscriptions subType() const override;
	void reset() override;
private:

	int number;
	// Modified
	std::string owner;
	std::string buildingType;
	std::vector<int> address;
	bool isInNeighborAddress(int number);

};

#endif
