#include <cstddef>

#include "room.hpp"

/*********************************************************************
** Function: Room
** Description: Default constructor for room class.
** Parameters: Room / Room
** Pre-Conditions: Access to the room class.
** Post-Conditions: Initilzes the private variable contained in Room
** ******************************************************************/

Room::Room()
{
  e = NULL;
  a = NULL;
}

/*********************************************************************
** Function: setEvent
** Description: Mutator for the Event.
** Parameters: void / Room
** Pre-Conditions: Access to the room class.
** Post-Conditions: Sets event = the taken in object.
** ******************************************************************/

void Room::setEvent(Event* e)
{
  this->e = e;
}

/*********************************************************************
** Function: setArrowEvent
** Description: Mutator for the ArrowEvent.
** Parameters: void / Room
** Pre-Conditions: Access to the room class.
** Post-Conditions: Sets event = the taken in object.
** ******************************************************************/

void Room::setArrowEvent(ArrowEvent* a)
{
  this->a = a;
}

/*********************************************************************
** Function: getEvent
** Description: Accessor for the Event.
** Parameters: void / Room
** Pre-Conditions: Access to the room class.
** Post-Conditions: Returns the object.
** ******************************************************************/

Event* Room::getEvent()
{
  return e;
}

/*********************************************************************
** Function: getArrowEvent
** Description: Accessor for the ArrowEvent.
** Parameters: void / Room
** Pre-Conditions: Access to the room class.
** Post-Conditions: Returns the object.
** ******************************************************************/

ArrowEvent* Room::getArrowEvent()
{
  return a;
}
