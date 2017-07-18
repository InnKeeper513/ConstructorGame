#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "Subscription.h"
#include "Player.h"
#include <vector>

class Builder{

  Player player;

  int builderPoints;
  vector<int> address;
  vector<int> path;

  int brick;
  int energy;
  int glass;
  int heat;
  int wifi;

  public:

  Builder(Player player, int builderPoints = 0, int brick=0, int energy=0,
     int glass=0, int heat=0, int wifi=0){}
  // Return the player color
  Player subType();

  // Return a vector of address
  vector<int> ownAddress();

  // Return a vector of paths
  vector<int> ownPath();

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

  // Trade with another player
  void trade(Builder&);

  void instantiate(){

  }

};

#endif
