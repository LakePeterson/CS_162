#ifndef __ZOO_HPP
#define __ZOO_HPP
#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include "monkey.hpp"
#include "sloth.hpp"
#include "seaOtter.hpp"

class Zoo
{
  private:
    int bankAmount;
    Monkey* monkeyArray;
    Otter* otterArray;
    Sloth* slothArray;
    int numMonkey;
    int numOtter;
    int numSloth;
    float foodCost;

  public:
    Zoo();
    ~Zoo();
    int valid(std::string);
    void intro();
    void setBankAmount(int);
    int getBankAmount();
    void getAge();
    void createMonkey();
    void createBabyMonkey();
    void createSloth();
    void createBabySloth();
    void createOtter();
    void createBabyOtter();
    int checkBuyAnimal();
    void buyAnimalType(int);
    int dailyFoodCost();
    void totalFoodCost(int);
    void specialEventChoice();
    void sickAnimal();
    void createBaby();
    void attendenceBoom();
    void deleteMonkey();
    void deleteSloth();
    void deleteOtter();
    void revenue();
    void ageIncrease();
    void daySummary();



};

#endif
