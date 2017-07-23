
#ifndef _TILE_H_
#define _TILE_H_
#include <string>
#include "Address.h"
#include "Path.h"
#include "Observer.h"
#include <vector>
#include "Subscriptions.h"

class Tile : public Observer{
public:
	Tile(int number, std::string resource, int value);
	int getNumber();
	std::string getResource();
	int getValue();
	std::vector<int> getAddress();
	void addAddress(int add);
	bool hasGoose();

	void notify(std::string, int) override;
  Subscriptions subType() const override;

private:
	bool goose = false;
	std::vector<int> tileAddress;
	int number;
	std::string resource;
	int value;
};
#endif
