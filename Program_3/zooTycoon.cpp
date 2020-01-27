#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "zoo.hpp"
#include "animal.hpp"
#include "monkey.hpp"
#include "seaOtter.hpp"
#include "sloth.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
  srand(time(NULL));

  Zoo play;

  play.intro();

  while(play.getBankAmount() > 0)
  {
    play.buyAnimalType(play.checkBuyAnimal());

    play.totalFoodCost(play.dailyFoodCost());

    play.specialEventChoice();

    play.revenue();

    play.ageIncrease();

    play.daySummary();
  }

  return 0;
}
