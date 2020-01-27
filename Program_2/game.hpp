#ifndef __GAME_HPP
#define __GAME_HPP

#include "deck.hpp"
#include "player.hpp"

class Game
{
  private:
    Deck cards;
    Player players[2];
  public:
    void intro(); 
    void dealCards();
    void printDealtCards();
    void chooseCard();
    void computerChooseCard();
    int bookAmount();
    int winner();
    int validInput(std::string);
};

#endif
