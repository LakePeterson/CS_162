#ifndef ARROWEVENT_HPP
#define ARROWEVENT_HPP

#include "event.hpp"

class ArrowEvent : public Event
{
  private:
    int row;
    int column;
  public:
    virtual void arrowHit(Game*) = 0;
    virtual void arrowMiss(Game*) = 0;
    virtual void triggerEvent(Game*) = 0;
    virtual void percept() = 0;
    virtual ~ArrowEvent();

};
#endif
