#include "monkey.hpp"

using namespace std;

/********************************************************************
** Function: Monkey
** Description: Constructor for Monkey class.
** Parameters: Monkey
** Pre-Conditions: None
** Post-Conditions: None
** *****************************************************************/

Monkey::Monkey() : Animal(1095, 15000, 1, 4, 1500)
{}

/********************************************************************
* ** Function: setAge
* ** Description: A mutator for the original animal age.
* ** Parameters: void
* ** Pre-Conditions: Takes in original age.
* ** Post-Conditions: Takes a copy of the original age.
* ******************************************************************/

void Monkey::setAge(int age)
{
  this->age = age;
}
