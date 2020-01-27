#ifndef __DECK_HPP
#define __DECK_HPP

#include "card.hpp"

class Deck
{
  private:
    Card* cards;
    int n_cards;
  public:
    Deck();
    ~Deck();
    Card drawCard();
    int getDeckAmount();
}; 


#endif
