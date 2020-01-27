#include "game.hpp"
#include "wumpus.hpp"

/*********************************************************************
** Function: ~Wumpus
** Description: Destructor for Wumpus
** Parameters: void / Wumpus
** Pre-Conditions: Wumpus type.
** Post-Conditions: Correctly deletes information from memory.
** ******************************************************************/

Wumpus::~Wumpus()
{}

/*********************************************************************
** Function: triggerEvent
** Description: Triggers the event for the Wumpus class.
** Parameters: void / Wumpus
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the Wumpus arrowEvent.
** ******************************************************************/

void Wumpus::triggerEvent(Game *g)
{
  bool killed = true;

  cout << endl;
  cout << "You have walked into the same room as the Wumpus, you have now been killed!" << endl;

  g->setSameRoomWumpus(killed);
}

/*********************************************************************
** Function: percept
** Description: Triggers the percept for the Wumpus class.
** Parameters: void / Wumpus
** Pre-Conditions: Must be done polymorphically.
** Post-Conditions: Correctly triggers the Wumpus percept.
** ******************************************************************/

void Wumpus::percept()
{
  cout << "You smell a terrible stench." << endl;
}

/*********************************************************************
** Function: arrowHit
** Description: Detects if Wumpus was hit from arrow
** Parameters: void / Wumpus
** Pre-Conditions: Must have access to Game
** Post-Conditions: Correctly determines if Wumpus was hit.
** ******************************************************************/

void Wumpus::arrowHit(Game* g)
{
  for(int i = 0; i < g->getRooms().size(); i++)
  {
    for(int j = 0; j < g->getRooms().at(i).size(); j++)
    {
      if(g->getRooms().at(i).at(j).getArrowEvent() != NULL)
      {
        delete g->getRooms().at(i).at(j).getArrowEvent();
        cout << endl;
        cout << "You have killed the Wumpus!" << endl;
      }
    }
  }
}

/*********************************************************************
** Function: arrowMiss
** Description: Detects if Wumpus was missed by an arrow.
** Parameters: void / Wumpus
** Pre-Conditions: Must have access to Game
** Post-Conditions: Correctly determines if Wumpus was missed.
** ******************************************************************/

void Wumpus::arrowMiss(Game *g)
{
  for(int i = 0; i < g->getRooms().size(); i++)
  {
    for(int j = 0; j < g->getRooms().at(i).size(); j++)
    {
      if(g->getRooms().at(i).at(j).getArrowEvent() != NULL)
      {
        delete g->getRooms().at(i).at(j).getArrowEvent();
        g->getRooms().at(i).at(j).setArrowEvent(NULL);
        g->allocateArrowEvent(new Wumpus);
      }
    }
  }
  cout << endl;
  cout << "You missed the Wumpus!" << endl;
}
