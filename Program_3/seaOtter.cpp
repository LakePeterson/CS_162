#include "seaOtter.hpp"

using namespace std;

/********************************************************************
** Function: Otter
** Description: Constructor for Otter class.
** Parameters: Otter
** Pre-Conditions: None
** Post-Conditions: None
** *****************************************************************/

Otter::Otter() : Animal(1095, 5000, 2, 2, 250)
{}

/********************************************************************
* ** Function: setAge
* ** Description: A mutator for the original animal age.
* ** Parameters: void
* ** Pre-Conditions: Takes in original age.
* ** Post-Conditions: Takes a copy of the original age.
* ******************************************************************/

void Otter::setAge(int age)
{
  this->age = age;
}
