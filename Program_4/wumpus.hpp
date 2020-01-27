#ifndef WUMPUS_HPP
#define WUMPUS_HPP

#include "arrowEvent.hpp"

using namespace std;

class Wumpus : public ArrowEvent
{
  public:
    ~Wumpus();
    void triggerEvent(Game* g);
    void percept();
    void arrowHit(Game* g);
    void arrowMiss(Game* g);


};
#endif
