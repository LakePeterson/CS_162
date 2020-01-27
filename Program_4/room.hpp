#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"
#include "arrowEvent.hpp"

using namespace std;

class Room
{
  private:
    Event* e;
    ArrowEvent* a;

  public:
    Room();
    void setEvent(Event*);
    void setArrowEvent(ArrowEvent*);
    Event* getEvent();
    ArrowEvent* getArrowEvent();

};

#endif
