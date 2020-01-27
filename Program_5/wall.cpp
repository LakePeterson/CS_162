#include "wall.hpp"

/*********************************************************************
** Function: is_occupiable
** Description: Returns wheter the space is occupiable.
** Parameters: Wall
** Pre-Conditions: Access to the maze locations.
** Post-Conditions: returns false for if occupiable.
** ******************************************************************/

bool Wall::is_occupiable()
{
  return false;
}

/*********************************************************************
** Function: get_display_character
** Description: Returns the correct display character for wall objects.
** Parameters: wall
** Pre-Conditions: Access to the maze locations.
** Post-Conditions: Returns the correct display character.
** ******************************************************************/

char Wall::get_display_character()
{
  return '#';
}

/*********************************************************************
** Function: clone
** Description: Returns a copy of the wall.
** Parameters: OpenSpace
** Pre-Conditions: Access to the maze locations/wall
** Post-Conditions: Returns the wall display character.
** ******************************************************************/

MazeLocation *Wall::clone()
{
  return new Wall();
}
