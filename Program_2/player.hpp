#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "hand.hpp"

class Player {
  private:
    Hand hand;
    int* books;
    int n_books;
  public:
    Player();
    ~Player();
    void getCard(Card);
    void printDealtCards();
    Card requestCard(int);
    int countAmount(int);
    int computerRandCard();
    void findBooks();
    int get_n_books();
    int getHandAmount(); 
    int checkRankCards(int);
};


#endif
