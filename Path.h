#ifndef _PATH_H_
#define _PATH_H_
#include <vector>
#include <iostream>
#include <string>
#include "Observer.h"
#include "Subscriptions.h"

class Path : public Observer
{
public:
	Path(int number);
	std::string getBuilder();
	int GetNumber();
	void addPath(int);
	void addNeighbor(int);
	// set the owner of the path
	void setOwner(std::string);
	// upgrade the path for a specific building
	void upgrade(std::string);
	// Return the connected address of the path
	std::vector<int> getConnectedAddress();
	// Return all of the neighbor paths for the current path
	std::vector<int> getNeighborPath();

	void notify(std::string, int) override;
	Subscriptions subType() const override;

private:
	int number;
	std::string owner;
 	std::vector<int> neighborPath;
	std::vector<int> connectedAddress;
};

#endif
