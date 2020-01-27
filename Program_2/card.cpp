#include <iostream>
#include "card.hpp"

using namespace std;

/********************************************************************
** Function: Card
** Description: Default constructor for Card class.
** Parameters: Card
** Pre-Conditions: Takes in private values.
** Post-Conditions: Initializes the values.
** *****************************************************************/

Card::Card()
{
  rank = 0;
  suit = 0;
}

/********************************************************************
** Function: ~Card
** Description: Default destructor for Card class.
** Parameters: Card
** Pre-Conditions: None
** Post-Conditions: None
** *****************************************************************/

Card::~Card()
{
}

/********************************************************************
 ** Function: setRank
 ** Description: Setter for the rank.
 ** Parameters: void / Card
 ** Pre-Conditions: Access to rank.
 ** Post-Conditions: Sets the rank varaible.
 ** *****************************************************************/

void Card::setRank(int rank)
{
  this->rank=rank;
}

/********************************************************************
 ** Function: setSuit
 ** Description: Setter for the suit.
 ** Parameters: void / Card
 ** Pre-Conditions: Access to suit.
 ** Post-Conditions: Sets the suit varaible.
 ** *****************************************************************/

void Card::setSuit(int suit)
{
  this->suit=suit;
}

/********************************************************************
 ** Function: getRank
 ** Description: Gets the rank of the cards.
 ** Parameters: int / Card
 ** Pre-Conditions: Access to the ranks.
 ** Post-Conditions: Returns the ranks of the cards.
 ** *****************************************************************/

int Card::getRank()
{
  return rank;
}

/********************************************************************
 ** Function: printDealtCards
 ** Description: Prints the card information to the player.
 ** Parameters: void / Card
 ** Pre-Conditions: None
 ** Post-Conditions: Passes the card values up to the player. 
 ** *****************************************************************/

void Card::printDealtCards()
{
  cout << "Rank: " << rank << endl;
  cout << "Suit: " << suit << endl;
}
