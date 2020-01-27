#include <iostream>
#include <cstdlib>
#include "card.hpp"
#include "hand.hpp"

using namespace std;

/********************************************************************
 ** Function: Hand
 ** Description: Default constructor for Hand class.
 ** Parameters: Hand
 ** Pre-Conditions: Takes in private values.
 ** Post-Conditions: Initializes the values.
 ** *****************************************************************/

Hand::Hand()
{
  cards = NULL;
  n_cards = 0;
} 

/********************************************************************
 ** Function: ~Hand
 ** Description: Default destructor for Hand class.
 ** Parameters: Hand
 ** Pre-Conditions: Takes in cards array
 ** Post-Conditions: Deletes the cards array.
 ** *****************************************************************/

Hand::~Hand()
{
  delete [] cards;
}

/********************************************************************
** Function: recieveCard
** Description: Deals the card to a player.
** Parameters: Card / Hand
** Pre-Conditions: Takes in the dealt card.
** Post-Conditions: Puts the dealt card in the desired hand.
** *****************************************************************/

Card Hand::recieveCard(Card dealtCard)
{
  Card* tempArray = new Card[this->n_cards + 1];

  for(int i = 0; i < n_cards; i++)
  {
    tempArray[i] = cards[i];
  }

  tempArray[n_cards] = dealtCard;

  if(this->cards != NULL)
  {
    delete [] cards;
  }

  cards = tempArray;
  n_cards++;

  return dealtCard;
}

/********************************************************************
 ** Function: printDealtCards
 ** Description: Prints the hand of a player.
 ** Parameters: void / Hand
 ** Pre-Conditions: Needs to know the amount of card in the hand.
 ** Post-Conditions: Passes the hand up the the game to be printed.
 ** *****************************************************************/

void Hand::printDealtCards()
{
    for(int i = 0; i < n_cards; i++)
    {
      cout << "Card: " << i + 1 << endl;
      cards[i].printDealtCards();
      cout << endl;
    }
}

/********************************************************************
** Function: removeCard
** Description: Removes the card from the players hand.
** Parameters: Card / Hand
** Pre-Conditions: Takes in the requested card.
** Post-Conditions: Puts the requested card in the opponents hand.
** *****************************************************************/

Card Hand::removeCard(int removedCard)
{
  Card* tempArray = new Card[n_cards - 1];

  for(int i = 0; i < n_cards; i++)
  {
    if(i < removedCard)
    {
      tempArray[i] = cards[i];
    }
    else if(i > removedCard)
    {
      tempArray[i - 1] = cards[i];
    }
  }
  Card pickedCard = cards[removedCard];

  delete[] cards;

  cards = tempArray;

  n_cards--;

  return pickedCard;
}

/********************************************************************
 ** Function: getRankAmount
 ** Description: Gets the rank of cards in players hand.
 ** Parameters: int / Hand
 ** Pre-Conditions: Takes in the user input.
 ** Post-Conditions: Determines how the cards are in the players hand.
 ** *****************************************************************/

int Hand::getRankAmount(int userInput)
{
  int count = 0;

  for(int i = 0; i < n_cards; i++)
  {
    if(cards[i].getRank() == userInput)
    {
      count++;
    }
  }
  return count;
}

/********************************************************************
 ** Function: getRankCards
 ** Description: Takes in user input to get the card that was asked for.
 ** Parameters: Card / Hand
 ** Pre-Conditions: Takes the user input.
 ** Post-Conditions: Either gives card or says go fish.
 ** *****************************************************************/

Card Hand::getRankCards(int userInput)
{
  for(int i = 0; i < n_cards; i++)
  {
    if(cards[i].getRank() == userInput)
    {
      return removeCard(i);
    }
  }
}

/********************************************************************
 ** Function: checkRankCards
 ** Description: Determines the ranks of the cards.
 ** Parameters: int / Hand
 ** Pre-Conditions: Takes in user input.
 ** Post-Conditions: Returns the values in the players hand.
 ** *****************************************************************/

int Hand::checkRankCards(int userInput)
{
  for(int i = 0; i < n_cards; i++)
  {
    if(cards[i].getRank() == userInput)
    {
      return cards[i].getRank();
    }
  }
}

/********************************************************************
 ** Function: computerRandCard
 ** Description: Takes card input from the computer.
 ** Parameters: int / Hand
 ** Pre-Conditions: None
 ** Post-Conditions: Either gives card or says go fish.
 ** *****************************************************************/

int Hand::computerRandCard()
{
  if(n_cards == 0)
  {
    return -1;
  }

  int x = rand() % n_cards;
  return cards[x].getRank();
}

/********************************************************************
 ** Function: getHandAmount
 ** Description: Determines how amount of cards in hand.
 ** Parameters: int / Hand
 ** Pre-Conditions: None
 ** Post-Conditions: Returns the number of cards in each players hand.
 ** *****************************************************************/

int Hand::getHandAmount()
{
  return n_cards;
}
