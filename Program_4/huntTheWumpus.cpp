/******************************************************
** Author: Lake Peterson
** Date: March 4, 2019
** Description: Hunt The Wumpus
******************************************************/

#include "game.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[])
{
  int boardSize = atoi(argv[1]);

  Game play(boardSize);

  play.intro();

  play.allocateGamePieces();

  while(play.checkWin() == false && play.getPit() == false && play.getSameRoomWumpus() == false)
  {
    play.printGameBoard(boardSize);

    play.shootArrow(play.playerChoiceShoot());

    play.movePlayer(play.playerChoiceMove());
  }
}
