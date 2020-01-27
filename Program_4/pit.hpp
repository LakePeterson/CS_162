#ifndef PIT_HPP
#define PIT_HPP

#include "event.hpp"
#include <iostream>

using namespace std;

class Pit : public Event
{
  public:
    ~Pit();
    void triggerEvent(Game *g);
    void percept();

};

#endif
