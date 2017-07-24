#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include "Subscriptions.h"
#include <string>
#include <vector>
class Observer;

class Subject {
 public:
  void notifyObservers(Subscriptions, std::string, int);
};

#endif
