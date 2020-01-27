#include <iostream>
#include <string>
#include <cmath>
#include <climits>

#include "game.hpp"

using namespace std;

/********************************************************************
* ** Function: intro
* ** Description: Prints out the instruction of the program for the user.
* ** Parameters: void
* ** Pre-Conditions: Takes in predetermined text
* ** Post-Conditions: Outputs text
* ******************************************************************/

void Game::intro()
{
  cout << endl;
  cout << "Here are your directions to play the game of go fish, in which you will be playing against the computer." << endl;
  cout << "A turn consists of asking a specific player for a specific rank. For example, if it is my turn I might " << endl;
  cout << "say: 'Mary, please give me your jacks'. The player who asks must already hold at least one card of the " << endl;
  cout << "requested rank, so I must hold at least one jack to say this. If the player who was asked (Mary) has cards " << endl;
  cout << "of the named rank (jacks in this case), she must give all her cards of this rank to the player who asked " << endl;
  cout << "for them. That player then gets another turn and may again ask any player for any rank already held by the asker." << endl << endl;
  cout << "If the person asked does not have any cards of the named rank, they say 'Go fish!'. The asker must then draw the " << endl;
  cout << "top card of the undealt stock. If the drawn card is the rank asked for, the asker shows it and gets another turn. " << endl;
  cout << "If the drawn card is not the rank asked for, the asker keeps it, but the turn now passes to the next player to the left." << endl << endl;
  cout << "As soon as a player collects a book of 4 cards of the same rank, this must be shown and discarded face down. " << endl;
  cout << "The game continues until either someone has no cards left in their hand or the stock runs out. The winner is the " << endl;
  cout << "player who then has the most books." << endl << endl;
}

/********************************************************************
* ** Function: dealCards
* ** Description: Iterates through the deck 7 times for each player to deal them cards.
* ** Parameters: void
* ** Pre-Conditions: Needs to have access to deck.
* ** Post-Conditions: Deal 7 cards to each players hand.
* ******************************************************************/

void Game::dealCards()
{
  for(int i = 0; i < 2; i++)
  {
    for(int j = 1; j <= 7; j++)
    {
      Card dealtCard = cards.drawCard();
      players[i].getCard(dealtCard);
    }
  }
}

/********************************************************************
* ** Function: chooseCard
* ** Description: Asks for user input to choose a card from opponents hand.
* ** Parameters: void
* ** Pre-Conditions: Needs to have access to the users/opponents hand.
* ** Post-Conditions: Takes card from opponent and places card in users hand.
* ******************************************************************/

void Game::chooseCard()
{
  int count = 7;
  std::string checkInput;
  int userInput = 0;

  if(players[0].getHandAmount() == 0)
  {
    while(count > 0 && cards.getDeckAmount() > 0)
    {
      Card dealtCard = cards.drawCard();
      players[0].getCard(dealtCard);
      count --;
    }
  }
  cout << endl; 
  cout << "Here are your cards Player 1: " << endl << endl;
  players[0].printDealtCards();
  cout << "Pick a rank that you want from your opponent: ";
  do
	{
		cin >> checkInput;
    userInput = validInput(checkInput);

		if(userInput != players[0].checkRankCards(userInput))
		{
			cout << "Please enter a valid input: ";
		}
	}while(userInput != players[0].checkRankCards(userInput));

    if(players[1].countAmount(userInput) == 0)
    {
      cout << endl;
      cout << "Player 1 Go Fish" << endl << endl;
      if(cards.getDeckAmount() == 0)
      {
        cout << "There are no more cards in the deck!" << endl;
      }
      else
      {
        Card dealtCard = cards.drawCard();
        players[0].getCard(dealtCard);
      }
    }
    while(players[1].countAmount(userInput) >= 1)
    {
      players[0].getCard(players[1].requestCard(userInput));
    }
    players[0].findBooks();
}

/********************************************************************
* ** Function: computerChooseCard
* ** Description: Asks for computer input to choose a card from users hand.
* ** Parameters: void
* ** Pre-Conditions: Needs to have access to the users/opponents hand.
* ** Post-Conditions: Takes card from user and places card in computers hand.
* ******************************************************************/

void Game::computerChooseCard()
{
  int count = 7;
  int temp = players[1].computerRandCard();

  if (temp > 0)
  {
    if(players[1].getHandAmount() == 0)
    {
      while(count > 0 && cards.getDeckAmount() > 0)
      {
        Card dealtCard = cards.drawCard();
        players[1].getCard(dealtCard);
        count --;
      }
    }

    if(players[0].countAmount(temp) == 0)
    {
      cout << endl;
      cout << "Player 2 Go Fish" << endl << endl;
      if(cards.getDeckAmount() == 0)
      {
        cout << "There are no more cards in the deck!" << endl;
      }
      else
      {
        Card dealtCard = cards.drawCard();
        players[1].getCard(dealtCard);
      }
    }
    while(players[0].countAmount(temp) >= 1)
    {
      players[1].getCard(players[0].requestCard(temp));
    }
    players[1].findBooks();
  }
}

/********************************************************************
* ** Function: bookAmount
* ** Description: Determines how many books have been collected in the game.
* ** Parameters: int
* ** Pre-Conditions: Takes the book out of the players hand.
* ** Post-Conditions: Returns how many books have been taken.
* ******************************************************************/

int Game::bookAmount()
{
  return players[0].get_n_books() + players[1].get_n_books();
}

/********************************************************************
* ** Function: winner
* ** Description: Determines how many books have been collected in the game.
* ** Parameters: int
* ** Pre-Conditions: Determines what player has collected the most books.
* ** Post-Conditions: Returns text based on who wins.
* ******************************************************************/

int Game::winner()
{
  cout << endl;
  if(players[0].get_n_books() > players[1].get_n_books())
  {
    cout << "Player 1 wins the game!" << endl;
  }
  else if(players[1].get_n_books() > players[0].get_n_books())
  {
    cout << "Player 2 wins the game!" << endl;
  }
}

/********************************************************************
 ** Function: validInput
 ** Description: takes in a string and outputs an integer.
 ** Parameters: int
 ** Pre-Conditions: Takes in a user input of any type.
 ** Post-Conditions: Outputs an integer.
 ** *****************************************************************/

int Game::validInput(std::string str)
{
	int number;
	int sum = 0;

	for(int i = 0; i < str.length(); i++)
	{
		number = str[i];
		number -= 48;

		if(number < 0 || number > 9)
		{
			return INT_MAX;
		}
		sum += number * pow(10, str.length() - 1 - i);
	}
	return sum;
}
