#include "sloth.hpp"

using namespace std;

/********************************************************************
** Function: Sloth
** Description: Constructor for Sloth class.
** Parameters: Sloth
** Pre-Conditions: None
** Post-Conditions: None
** *****************************************************************/

Sloth::Sloth() : Animal(1095, 2000, 3, 1, 100)
{}

/********************************************************************
* ** Function: setAge
* ** Description: A mutator for the original animal age.
* ** Parameters: void
* ** Pre-Conditions: Takes in original age.
* ** Post-Conditions: Takes a copy of the original age.
* ******************************************************************/

void Sloth::setAge(int age)
{
  this->age = age;
}
