#ifndef __HAND_HPP
#define __HAND_HPP

#include "card.hpp"

class Hand
{
  private:
    Card* cards;
    int n_cards;
  public:
    Hand();
    ~Hand();
    Card recieveCard(Card);
    void printDealtCards();
    int getRankAmount(int);
    Card removeCard(int);
    Card getRankCards(int);
    int checkRankCards(int);
    int computerRandCard();
    int getHandAmount(); 
};

#endif
