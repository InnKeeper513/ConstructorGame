#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "Subscriptions.h"
class Subject;
class Builder;

class Observer {
 public:
  virtual void notify(std::string, int) = 0;  // pass the Cell that called
                                                  // the notify method
  virtual Subscriptions subType() const = 0;
};
#endif
