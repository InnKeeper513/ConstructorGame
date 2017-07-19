#ifndef _BOARD_H_
#define _BOARD_H_

#include "Builder.h"
#include "Player.h"

class Board{

  // Set the location of a goose
  void setGoose(int);

  // Build a new road
  void buildRoad(Builder&, int);

  // Build a new residence
  void buildResidence(Builder&, int);

  // Upgrade a residence
  void upgradeResidence(Builder&, int);

  // Trading resources between two players
  void resourceTrade(Builder&, Builder&);

  // Print the status of the builder
  void status(Builder&);
  // Print the current grid
  void printGrid();

  // TODO thse are for saving and loading
  void instantiate();
  void save();


};

#endif
