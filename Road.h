#ifndef _ROAD_H_
#define _ROAD_H_

#include "player.h"
#include "Subscriptions.h"

class Road{

  Player owner = Player::None;
  int number;
  int adjacent_house1;
  int adjacent_house2;

  public:
  Road(int,int,int){}

  // When notified by a player, then upgrade this path to a road
  void notify(Player);

  // Return the subscription type of this class
  SubscriptionType SubType();

  // Shows the owner of this road
  Player owner();

  // When loading a saving, initialize the current road
  void instantiate(Player, int);


};
#endif
