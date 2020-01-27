#ifndef GOLD_HPP
#define GOLD_HPP

#include "event.hpp"

using namespace std;

class Gold : public Event
{
  public:
  void triggerEvent(Game *g);
  void percept();
  ~Gold();

};

#endif
