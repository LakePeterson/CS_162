#include "openSpace.hpp"

/*********************************************************************
** Function: OpenSpace
** Description: Default constructor for the OpenSpace class
** Parameters: OpenSpace
** Pre-Conditions: Access to the private variables with the class.
** Post-Conditions: Sets all private varables within the class to private.
** ******************************************************************/

OpenSpace::OpenSpace()
{
  has_student = false;
  /*has_ta = false;
  has_instructor = false;
  has_ladder = false;
  has_skill = false;*/
}

/*********************************************************************
** Function: set_has_student
** Description: Mutator for has_student.
** Parameters: OpenSpace
** Pre-Conditions: Access to has student variable
** Post-Conditions: Sets this->has_student = has_student
** ******************************************************************/

void OpenSpace::set_has_student(bool has_student)
{
  this->has_student = has_student;
}

/*void set_has_ta(bool has_ta)
{
  this->has_ta = has_ta;
}

void set_has_instructor(bool has_instructor)
{
  this->has_instructor = has_instructor;
}

void set_has_ladder(bool has_ladder)
{
  this->has_ladder = has_ladder;
}

void has_skill(bool has_skill)
{
  this->has_skill = has_skill;
}*/

/*********************************************************************
** Function: is_occupiable
** Description: Returns wheter the space is occupiable.
** Parameters: OpenSpace
** Pre-Conditions: Access to the maze locations.
** Post-Conditions: returns true if occupiable.
** ******************************************************************/

bool OpenSpace::is_occupiable()
{
  return true;
}

/*********************************************************************
** Function: get_display_character
** Description: Returns the correct display character for open space objects.
** Parameters: OpenSpace
** Pre-Conditions: Access to the maze locations.
** Post-Conditions: Returns the correct display character.
** ******************************************************************/

char OpenSpace::get_display_character()
{
  if(has_student == true)
  {
    return '*';
  }
  /*if(has_ta == true)
  {
    return 'T';
  }
  if(has_instructor == true)
  {
    return '%';
  }
  if(has_ladder == true)
  {
    return '^';
  }
  if(has_skill == true)
  {
    return '$';
  }*/

  return ' ';
}

/*********************************************************************
** Function: clone
** Description: Returns a copy of the has_student.
** Parameters: OpenSpace
** Pre-Conditions: Access to the maze locations/openSpace
** Post-Conditions: Returns the display character.
** ******************************************************************/

MazeLocation *OpenSpace::clone()
{
  OpenSpace *copy = new OpenSpace();
  copy->set_has_student(has_student);

  return copy;
}
