#include "Builder.h"
#include "Player.h"
#include "Subscriptions.h"
#include <vector>
#include <string>

using namespace std;

Builder::Builder(Player player, int builderPoints, int brick, int energy,
   int glass, int heat, int wifi):
   player{player},
   builderPoints{builderPoints},
   brick{brick},
   energy{energy},
   glass{glass},
   heat{heat},
   wifi{wifi}{}

void Builder::addAddress(int add){
  address.emplace_back(add);
}

void Builder::addPath(int add){
  path.emplace_back(add);
}

Player Builder::subType(){
  return player;
}

vector<int> Builder::ownAddress(){
  return address;
}

vector<int> Builder::ownPath(){
  return path;
}

int Builder::getBuildPoints(){
  return builderPoints;
}
void Builder::setBuildPoints(int set){
  builderPoints = set;
}
void Builder::incrResource(Subscriptions sub, int amount){

  // Base on the resource type, increase amount of resource gain
  if(sub == Subscriptions::Brick)
    brick += amount;
  else if(sub == Subscriptions::Energy)
    energy += amount;
  else if(sub == Subscriptions::Glass)
    glass += amount;
  else if(sub == Subscriptions::Heat)
    heat += amount;
  else if(sub == Subscriptions::Wifi)
    wifi += amount;

}

void Builder::decResource(Subscriptions sub, int amount){

  // Base on the resource type, decrease amount of resource gain
  if(sub == Subscriptions::Brick)
    brick -= amount;
  else if(sub == Subscriptions::Energy)
    energy -= amount;
  else if(sub == Subscriptions::Glass)
    glass -= amount;
  else if(sub == Subscriptions::Heat)
    heat -= amount;
  else if(sub == Subscriptions::Wifi)
    wifi -= amount;
}

int Builder::getResource(Subscriptions sub){

  // Return the specified resources
  if(sub == Subscriptions::Brick)
    return brick;
  else if(sub == Subscriptions::Energy)
    return energy;
  else if(sub == Subscriptions::Glass)
    return glass;
  else if(sub == Subscriptions::Heat)
    return heat;
  else if(sub == Subscriptions::Wifi)
    return wifi;
}

string Builder::getColor(){
  if(player == Player::Blue)
    return "Blue";
  else if(player == Player::Red)
    return "Red";
  else if(player == Player::Orange)
    return "Orange";
  else if(player == Player::Yellow)
    return "Yellow";
}

// TODO Trade need to be identified later on
void Builder::trade(Builder&){

}

// TODO
void Builder::instantiate(){

}
