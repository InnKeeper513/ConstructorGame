#include "Subject.h"
#include "Observer.h"
#include "Subscriptions.h"
#include "Board.h"
#include "Address.h"
#include "Tile.h"
#include "Path.h"

using namespace std;

void Subject::notifyObservers(Subscriptions t, string name, int location) {

  string a;

  if(name == "Blue")
    a = "B";
  else if(name == "Red")
    a = "R";
  else if(name == "Yellow")
    a = "Y";
  else if(name == "Orange")
    a = "O";

  if(t == Subscriptions::Address){
        addresses[location].notify(a, location);
  }
  else if(t == Subscriptions::Path){
        paths[location].notify(a, location);
  }
  else if(t == Subscriptions::Tile){
        tiles[location].notify(a, location);
  }

}
