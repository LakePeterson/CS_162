#ifndef BATS_HPP
#define BATS_HPP

#include "event.hpp"
#include <iostream>

using namespace std;

class Bats : public Event
{
  public:
    ~Bats();
    void triggerEvent(Game *g);
    void percept();
};

#endif
