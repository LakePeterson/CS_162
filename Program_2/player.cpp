#include <iostream>
#include "player.hpp"

using namespace std;

/********************************************************************
 ** Function: Player
 ** Description: Default constructor for player class.
 ** Parameters: Player
 ** Pre-Conditions: Takes in private values.
 ** Post-Conditions: Initializes the values.
 ** *****************************************************************/

Player::Player()
{
  books = NULL;
  n_books = 0;
}

/********************************************************************
 ** Function: ~Player
 ** Description: Default destructor for player class.
 ** Parameters: Player
 ** Pre-Conditions: Takes in books array.
 ** Post-Conditions: Deletes the book array.
 ** *****************************************************************/

Player::~Player()
{
  delete [] books;
}

/********************************************************************
 ** Function: getCard
 ** Description: Middle man function to deal a card.
 ** Parameters: void / Player
 ** Pre-Conditions: Takes in the dealt card.
 ** Post-Conditions: Puts the dealt card in the desired hand.
 ** *****************************************************************/

void Player::getCard(Card dealtCard)
{
  hand.recieveCard(dealtCard);
}
 
/********************************************************************
 ** Function: printDealtCards
 ** Description: Middle man function to print the hand of a player.
 ** Parameters: void / Player
 ** Pre-Conditions: None
 ** Post-Conditions: Passes the hand up the the game to be printed.
 ** *****************************************************************/

void Player::printDealtCards()
{
  hand.printDealtCards();
}

/********************************************************************
 ** Function: requestCard
 ** Description: Passes user input to get the card that was asked for.
 ** Parameters: Card / Player
 ** Pre-Conditions: Takes the user input.
 ** Post-Conditions: Either gives card or says go fish.
 ** *****************************************************************/

Card Player::requestCard(int userInput)
{
  return hand.getRankCards(userInput);
}

/********************************************************************
 ** Function: cardAmount
 ** Description: Middle man function get rank of cards in players hand.
 ** Parameters: int / Player
 ** Pre-Conditions: Takes in the user input.
 ** Post-Conditions: Determines how the cards are in the players hand.
 ** *****************************************************************/

int Player::countAmount(int userInput)
{
  return hand.getRankAmount(userInput);
}

/********************************************************************
 ** Function: computerRandCard
 ** Description: Middle man function take card from user.
 ** Parameters: int / Player
 ** Pre-Conditions: Takes in the computer integer.
 ** Post-Conditions: Either gives card or says go fish.
 ** *****************************************************************/

int Player::computerRandCard()
{
  return hand.computerRandCard();
}

/********************************************************************
 ** Function: get_n_books
 ** Description: Middle man function determine how many books are in play.
 ** Parameters: int / Player
 ** Pre-Conditions: None
 ** Post-Conditions: Returns the number of books.
 ** *****************************************************************/

int Player::get_n_books()
{
  return n_books;
}

/********************************************************************
 ** Function: findBooks
 ** Description: Finds the books in a players hand.
 ** Parameters: void / Player
 ** Pre-Conditions: Access to the players hand.
 ** Post-Conditions: Records the amount of books for each player.
 ** *****************************************************************/

void Player::findBooks()
{
  int count;

  for(int i = 1; i <= 13; i++)
  {
    count = hand.getRankAmount(i);

    if(count == 4)
    {
      while(hand.getRankAmount(i) >= 1)
      {
        hand.getRankCards(i);
      }

      int* tempArray = new int [n_books + 1];

      for(int i = 0; i < n_books; i++)
      {
        tempArray[i] = books[i];
      }

      tempArray[n_books] = i;

      if(this->books != NULL)
      {
        delete [] books;
      }

      books = tempArray;
      n_books++;
    }
  }
}

/********************************************************************
 ** Function: getHandAmount
 ** Description: Middle man function determine how amount of cards in hand.
 ** Parameters: int / Player
 ** Pre-Conditions: Access to hand.
 ** Post-Conditions: Returns the number of cards in each players hand.
 ** *****************************************************************/

int Player::getHandAmount()
{
  return hand.getHandAmount();
}

/********************************************************************
 ** Function: checkRankCards
 ** Description: Middle man function determine the ranks of the cards.
 ** Parameters: int / Player
 ** Pre-Conditions: Takes in user input.
 ** Post-Conditions: Returns the values in the players hand.
 ** *****************************************************************/

int Player::checkRankCards(int userInput)
{
  return hand.checkRankCards(userInput);
}
