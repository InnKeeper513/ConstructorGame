
#ifndef _TILE_H_
#define _TILE_H_
#include <string>
#include "Observer.h"
#include <vector>
#include "Subscriptions.h"

class Tile : public Observer{
public:
	Tile(int number, std::string resource, int value);
	Tile();
	int getNumber();
	std::string getResource();
	int getValue();
	std::vector<int> getAddress();
	virtual void addAddress(int add);
	bool hasGoose();
	virtual void setOwner(std::string);
	void notify(std::string, int) override;
	virtual void reset();
  Subscriptions subType() const override;

private:
	bool goose = false;
	std::vector<int> tileAddress;
	int number;
	std::string resource;
	int value;
};
#endif
