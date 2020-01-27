#include "gold.hpp"
#include "game.hpp"

#include <iostream>

/*********************************************************************
** Function: ~Gold
** Description: Destructor for Gold
** Parameters: void / Gold
** Pre-Conditions: Gold type.
** Post-Conditions: Correctly deletes information from memory.
** ******************************************************************/

Gold::~Gold(){}

/*********************************************************************
** Function: triggerEvent
** Description: Triggers the event for the gold class.
** Parameters: void / Gold
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the gold event.
** ******************************************************************/

void Gold::triggerEvent(Game* g)
{
  bool collectGold = true;

  cout << endl;
  cout << "You found the Gold!" << endl << endl;

  g->setGold(collectGold);
}

/*********************************************************************
** Function: percept
** Description: Triggers the percept for the gold class.
** Parameters: void / Gold
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the gold percept.
** ******************************************************************/

void Gold::percept()
{
  cout << "You see a glimmer nearby." << endl << endl;
}
