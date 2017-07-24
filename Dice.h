#ifndef _DICE_H_
#define _DICE_H_

#include <string>
#include <cstdlib>

class Dice{

  std::string type;

  public:

  Dice(std::string type);

  // Will roll the dice based on the type of the dice
  int rollDice();

};

#endif
