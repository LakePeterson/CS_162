#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

class Animal
{
  protected:
    int age;
    int purchaseCost;
    int numBabies;
    int foodMult;
    int baseRevenue;

  public:
    Animal(int, int, int, int, int);
    int getAge();
    int getPurchaseCost();
    int getNumBabies();
    int getFoodMult();
    int getBaseRevenue();
    void incrementAge();

};

#endif
