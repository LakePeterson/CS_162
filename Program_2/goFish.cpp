#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "game.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "card.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
  srand(time(NULL));

  Game play;

  play.intro();
  play.dealCards(); 

  while(play.bookAmount() < 13)
  {
    play.chooseCard();
    play.computerChooseCard();
  }

  play.winner();

  return 0;
}
