#include "pit.hpp"
#include "game.hpp"

/*********************************************************************
** Function: ~Pit
** Description: Destructor for Pit
** Parameters: void / Pit
** Pre-Conditions: Pit type.
** Post-Conditions: Correctly deletes information from memory.
** ******************************************************************/

Pit::~Pit()
{}

/*********************************************************************
** Function: triggerEvent
** Description: Triggers the event for the pit class.
** Parameters: void / Pit
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the pit event.
** ******************************************************************/

void Pit::triggerEvent(Game *g)
{
  bool fallInPit = true;

  cout << endl;
  cout << "You have fallen into a pit and died!" << endl;

  g->setPit(fallInPit);
}

/*********************************************************************
** Function: percept
** Description: Triggers the percept for the pit class.
** Parameters: void / pit
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the pit percept.
** ******************************************************************/

void Pit::percept()
{
  cout << "You feel a breeze." << endl << endl;;
}
