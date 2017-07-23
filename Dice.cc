#include "Dice.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Dice::Dice(string type): type{type}{}

int Dice::rollDice(){
  int number = 0;

  if(type=="load"){
    cout << "Input a roll between 2 and 12:" << endl;

    // Continue to input the dice number until it is correct
    while(cin >> number){
      if(number < 2 || number > 12){
        cout << "Invalid roll" << endl;
        cout << "Input a roll between 2 and 12:" << endl;
      } else {
        cout << "You rolled " << number << endl;
        break;
      }
      return number;
    }
  }else if(type == "fair"){
    // Generate two random integer between 1 and 6
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sum = dice1 + dice2;
    cout << "You rolled " << sum << endl;
    return sum;
  }
}
