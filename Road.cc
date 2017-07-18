#include "Player.h"
#include "Subscriptions.h"
#include "Road.h"

Road::Road(int number, int adjacent_hosue1, int adjacent_house2):
number{number},
adjacent_house1{adjacent_house1},
adjacent_house2{adjacent_house2}{}

void Road::notify(Player p){
  owner = p;
}

SubscriptionType Road::SubType(){
  return SubscriptionType::Road;
}

Player Road::owner(){
  return owner;
}

void Road::instantiate(Player){
  owner = Player;
  isPath = false;
}
