#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "Subscriptions.h"
#include "Player.h"
#include <vector>
#include <string>

class Builder{

  Player player;
  int builderPoints;

  std::vector<int> address;
  std::vector<int> path;

  int brick;
  int energy;
  int glass;
  int heat;
  int wifi;

  public:

  Builder(Player player, int builderPoints = 0, int brick=0, int energy=0,
     int glass=0, int heat=0, int wifi=0);
  // Return the player color
  Player subType();

  // Add an address
  void addAddress(int address);

  // Add a path
  void addPath(int path);

  // Return a vector of address
  std::vector<int> ownAddress();

  // Return a vector of paths
  std::vector<int> ownPath();

  // Return the amount of building points
  int getBuildPoints();

  // Set the building points
  void setBuildPoints(int);

  // Incraese the specified resource
  void incrResource(Subscriptions, int);

  // Decraese the specified resource
  void decResource(Subscriptions, int);

  // Return the specified resources
  int getResource(Subscriptions);

  std::string getColor();

  void printStatus();

  // Trade with another player
  void trade(Builder&);

  void instantiate();

};

#endif
