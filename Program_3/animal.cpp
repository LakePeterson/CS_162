#include "animal.hpp"

using namespace std;

/********************************************************************
** Function: Animal
** Description: Constructor for Animal class.
** Parameters: Animal
** Pre-Conditions: None
** Post-Conditions: None
** *****************************************************************/

Animal::Animal(int age, int purchaseCost, int numBabies, int foodMult, int baseRevenue)
{
  this->age = age;
  this->purchaseCost = purchaseCost;
  this->numBabies = numBabies;
  this->foodMult = foodMult;
  this->baseRevenue = baseRevenue;
}

/********************************************************************
* ** Function: getAge
* ** Description: A accessor for the original animal age.
* ** Parameters: int
* ** Pre-Conditions: Takes in the copied amount.
* ** Post-Conditions: Returns the age for use in program.
* ******************************************************************/

int Animal::getAge()
{
  return age;
}

/********************************************************************
* ** Function: getPurchaseCost
* ** Description: A accessor for the original animal purchase cost.
* ** Parameters: int
* ** Pre-Conditions: Takes in the copied amount.
* ** Post-Conditions: Returns the purchase cost for use in program.
* ******************************************************************/

int Animal::getPurchaseCost()
{
  return purchaseCost;
}

/********************************************************************
* ** Function: getNumBabies
* ** Description: A accessor for the original babies being born.
* ** Parameters: int
* ** Pre-Conditions: Takes in the copied amount.
* ** Post-Conditions: Returns the amount for use in program.
* ******************************************************************/

int Animal::getNumBabies()
{
  return numBabies;
}

/********************************************************************
* ** Function: getFoodMult
* ** Description: A accessor for the original food multiplier.
* ** Parameters: int
* ** Pre-Conditions: Takes in the copied amount.
* ** Post-Conditions: Returns the amount for use in program.
* ******************************************************************/

int Animal::getFoodMult()
{
  return foodMult;
}

/********************************************************************
* ** Function: getBaseRevenue
* ** Description: A accessor for the original base revenue for each animal.
* ** Parameters: int
* ** Pre-Conditions: Takes in the copied amount.
* ** Post-Conditions: Returns the amount for use in program.
* ******************************************************************/

int Animal::getBaseRevenue()
{
  return baseRevenue;
}

/********************************************************************
* ** Function: incrementAge
* ** Description: Increments the age of the animal by one when called.
* ** Parameters: void
* ** Pre-Conditions: Takes in the copied amount.
* ** Post-Conditions: Returns the age with added day.
* ******************************************************************/

void Animal::incrementAge()
{
  age++;
}
