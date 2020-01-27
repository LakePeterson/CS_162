#include <iostream>

#include "bats.hpp"
#include "game.hpp"

/*********************************************************************
** Function: triggerEvent
** Description: Triggers the event for the bat class.
** Parameters: void / Bats
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the bat event.
** ******************************************************************/

void Bats::triggerEvent(Game *g)
{
  cout << endl;
  cout << "You have walked into a cave that was filled with Super Bats!" << endl << endl;

  g->allocatePlayerBat();
}

/*********************************************************************
** Function: percept
** Description: Triggers the percept for the bat class.
** Parameters: void / Bats
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the bat percept.
** ******************************************************************/

void Bats::percept()
{
  cout << "There's a bat nearby" << endl << endl;
}

/*********************************************************************
** Function: ~Bats
** Description: Destructor for Bats
** Parameters: void / Bats
** Pre-Conditions: Bats type.
** Post-Conditions: Correctly deletes information from memory.
** ******************************************************************/

Bats::~Bats(){}
