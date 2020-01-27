#include <iostream>
#include <cstdlib>
#include "deck.hpp"

/********************************************************************
** Function: Deck
** Description: Default constructor for Deck class.
** Parameters: Deck
** Pre-Conditions: Takes in private values.
** Post-Conditions: Initializes the values.
** *****************************************************************/

Deck::Deck()
{
  cards = new Card[52];
  n_cards = 52;
  int index = 0;

  for(int i = 1; i <= 13; i++)
  {
    for(int j = 1; j <= 4; j++)
    {
      cards[index].setRank(i);
      cards[index].setSuit(j);
      index++;
    }
  }
}

/********************************************************************
 ** Function: ~Deck
 ** Description: Default destructor for Deck class.
 ** Parameters: Deck
 ** Pre-Conditions: Takes in card array
 ** Post-Conditions: Deletes the card array.
 ** *****************************************************************/

Deck::~Deck()
{
  delete [] cards;
} 

/********************************************************************
 ** Function: drawCard
 ** Description: Draws a card from the deck.
 ** Parameters: Card / Deck
 ** Pre-Conditions: Takes in cards array
 ** Post-Conditions: Takes card from array and returns to user.
 ** *****************************************************************/

Card Deck::drawCard()
{
  int pickCard = rand() % n_cards;
  Card* deckArray = new Card[n_cards - 1];

  for(int i = 0; i < n_cards; i++)
  {
    if(i < pickCard)
    {
      deckArray[i] = cards[i];
    }
    else if(i > pickCard)
    {
      deckArray[i - 1] = cards[i];
    }
  }
  Card pickedCard = cards[pickCard];

  delete[] cards;

  cards = deckArray;

  n_cards--;

  return pickedCard;
}

int Deck::getDeckAmount()
{
  return n_cards;
}
