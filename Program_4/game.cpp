#include "game.hpp"
#include "bats.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "wumpus.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*********************************************************************
** Function: Game
** Description: Default constructor for game class.
** Parameters: Game / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Initilzes the private variable contained in Game
** ******************************************************************/

Game::Game()
{
  srand(time(NULL));
  pit = false;
  wumpus = false;
  gold = false;
  checkHit = false;
  arrow = 0;
  startX = -1;
  startY = -1;
}

/*********************************************************************
** Function: Game
** Description: Constructor for game class.
** Parameters: Game / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Creates the game board for Hunt the Wumpus.
** ******************************************************************/

Game::Game(int boardSize)
{
  for(int i = 0; i < boardSize; i++)
  {
    vector<Room> row;
    for(int j = 0; j < boardSize; j++)
    {
      Room r;
      row.push_back(r);
    }
    rooms.push_back(row);
  }
}

/*********************************************************************
** Function: allocateGamePieces
** Description: Allocates the game pieces to the game board.
** Parameters: void / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Correctly allocates the pieces to the game board.
** ******************************************************************/

void Game::allocateGamePieces()
{
  for(int i = 0; i < 2; i++)
  {
    allocateEvent(new Bats);
  }
  allocateEvent(new Pit);
  allocateEvent(new Gold);
  allocateArrowEvent(new Wumpus);
  allocatePlayer();
}

/*********************************************************************
** Function: getRooms
** Description: Returns the number of rooms created from the 2D vector.
** Parameters: vector / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Returns the number of rooms in the game board.
** ******************************************************************/

vector<vector<Room> >& Game::getRooms()
{
  return rooms;
}

/*********************************************************************
** Function: allocateEvent
** Description: Allocates an event of type Event.
** Parameters: void / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Correctly created the events.
** ******************************************************************/

void Game::allocateEvent(Event* e)
{
  int row;
  int column;

  do
  {
    row = rand() % rooms.size();
    column = rand() % rooms.size();
  }while(rooms[row][column].getEvent() != NULL || rooms[row][column].getArrowEvent() != NULL || (row == playerRow && column == playerColumn));

  rooms[row][column].setEvent(e);
}

/*********************************************************************
** Function: allocateArrowEvent
** Description: Allocates an event of type arrowEvent.
** Parameters: void / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Correctly created the arrowEvents.
** ******************************************************************/

void Game::allocateArrowEvent(ArrowEvent* a)
{
  int row;
  int column;

  do
  {
    row = rand() % rooms.size();
    column = rand() % rooms.size();
  }while(rooms[row][column].getEvent() != NULL || rooms[row][column].getArrowEvent() != NULL || (row == playerRow && column == playerColumn));

  rooms[row][column].setArrowEvent(a);
}

/*********************************************************************
** Function: allocatePlayer
** Description: Allocates a player onto the game board.
** Parameters: void / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Correctly placed the player onto the game board.
** ******************************************************************/

void Game::allocatePlayer()
{
  int row;
  int column;

  do
  {
    row = rand() % rooms.size();
    column = rand() % rooms.size();
  }while(rooms[row][column].getEvent() != NULL || rooms[row][column].getArrowEvent() != NULL || (row == playerRow && column == playerColumn));

  playerRow = row;
  playerColumn = column;

  startX = row;
  startY = column;
}

/*********************************************************************
** Function: allocatePlayerBat
** Description: Allocates a player onto the game board.
** Parameters: void / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Correctly placed the player onto the game board.
** ******************************************************************/

void Game::allocatePlayerBat()
{
  int row;
  int column;

  do
  {
    row = rand() % rooms.size();
    column = rand() % rooms.size();
  }while(rooms[row][column].getEvent() != NULL || rooms[row][column].getArrowEvent() != NULL || (row == playerRow && column == playerColumn));

  playerRow = row;
  playerColumn = column;
}

/*********************************************************************
** Function: printGameBoard
** Description: Prints the game board for the user.
** Parameters: void / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Correctly creates the gameBoard.
** ******************************************************************/

void Game::printGameBoard(int boardSize)
{
  cout << "+";
  for(int i = 0; i < boardSize; i++)
  {
    cout << "---+";
  }
  cout << endl;
  for(int i = 0; i < boardSize; i++)
  {
    cout << "|";
    for(int j = 0; j < boardSize; j++)
    {
      if(i == playerRow && j == playerColumn)
      {
        cout << " * |";
      }
      else
      {
        cout << "   |";
      }
    }
    cout << endl;
    cout << "+";
    for(int j = 0; j < boardSize; j++)
    {
      cout << "---+";
    }
    cout << endl;
  }

  cout << endl;

  checkForPercept();
}

/*********************************************************************
** Function: intro
** Description: Intoduces the game to the user.
** Parameters: void / Game
** Pre-Conditions: Access to the game class.
** Post-Conditions: Correctly displays the instructions.
** ******************************************************************/

void Game::intro()
{
  cout << endl;
  cout << "Welcome to the game of Hunt the Wumpus. In this game you will be placed in a " << endl;
  cout << "dark cave, in which your goal will be to collect the gold, as well as kill the " << endl;
  cout << "Wumpus with an arrow! You will only have three shots so make them count, also " << endl;
  cout << "you need to be aware of traps that could kill you replace you in a different cave! " << endl;
  cout << "Once you have killed the Wumpus and collected the gold you must exit out of the "<< endl;
  cout << "room you started in. " << endl << endl;
  cout << "The * indicates where you are in the game." << endl << endl;
}

/*********************************************************************
** Function: playerChoiceMove
** Description: Gives the user options for which direction they want to move.
** Parameters: int / Game
** Pre-Conditions: Takes in userInput
** Post-Conditions: Correctly returns the users input.
** ******************************************************************/

int Game::playerChoiceMove()
{
  int moveChoice;

  cout << endl;
  cout << "Which direction would you like to move?" << endl;
  cout << "1 - Left" << endl;
  cout << "2 - Right" << endl;
  cout << "3 - Up" << endl;
  cout << "4 - Down" << endl << endl;
  cout << "Choose a coresponding integer value to make your choice: ";
  cin >> moveChoice;

  return moveChoice;
}

/*********************************************************************
** Function: movePlayer
** Description: Based in userInput, players game piece will be moved.
** Parameters: void / Game
** Pre-Conditions: takes in value from playerChoiceMove.
** Post-Conditions: Correctly moves the player.
** ******************************************************************/

void Game::movePlayer(int moveChoice)
{
  switch(moveChoice)
  {
    case 1: //Left

    if(playerColumn - 1 >= 0)
    {
      playerColumn--;
    }
    else
    {
      cout << "Sorry, you can not go left anymore!" << endl;
    }

    break;

    case 2: //right

    if(playerColumn + 1 < rooms.size())
    {
      playerColumn++;
    }
    else
    {
      cout << "Sorry, you can not go right anymore!" << endl;
    }

    break;

    case 3: //up

    if(playerRow - 1 >= 0)
    {
      playerRow--;
    }
    else
    {
      cout << "Sorry, you can not go up anymore!" << endl;
    }

    break;

    case 4: //down

    if(playerRow + 1 < rooms.size())
    {
      playerRow++;
    }
    else
    {
      cout << "Sorry, you can not go down anymore!" << endl;
    }

    break;
  }

  checkForEvent();

  cout << endl;
}

/*********************************************************************
** Function: checkForEvent
** Description: Checks for an event in the players current room.
** Parameters: void / Game
** Pre-Conditions: Access to the game board.
** Post-Conditions: Correctly checks what is in each room.
** ******************************************************************/

void Game::checkForEvent()
{
  if(rooms.at(playerRow).at(playerColumn).getEvent() != NULL)
  {
    rooms.at(playerRow).at(playerColumn).getEvent()->triggerEvent(this);
  }
  else if(rooms.at(playerRow).at(playerColumn).getArrowEvent() != NULL)
  {
    rooms.at(playerRow).at(playerColumn).getArrowEvent()->triggerEvent(this);
  }
}

/*********************************************************************
** Function: checkForPercept
** Description: Checks for a percept in the players adjacent rooms.
** Parameters: void / Game
** Pre-Conditions: Access to the game board.
** Post-Conditions: Correctly checks for a percept from all four sides.
** ******************************************************************/

void Game::checkForPercept()
{
  if(playerRow + 1 < rooms.size() && rooms.at(playerRow + 1).at(playerColumn).getEvent() != NULL)
  {
    rooms.at(playerRow + 1).at(playerColumn).getEvent()->percept();
  }
  else if(playerRow + 1 < rooms.size() && rooms.at(playerRow + 1).at(playerColumn).getArrowEvent() != NULL)
  {
    rooms.at(playerRow + 1).at(playerColumn).getArrowEvent()->percept();
  }

  if(playerRow - 1 > 0 && rooms.at(playerRow - 1).at(playerColumn).getEvent() != NULL)
  {
    rooms.at(playerRow - 1).at(playerColumn).getEvent()->percept();
  }
  else if(playerRow - 1 > 0 && rooms.at(playerRow - 1).at(playerColumn).getArrowEvent() != NULL)
  {
    rooms.at(playerRow - 1).at(playerColumn).getArrowEvent()->percept();
  }

  if(playerColumn + 1 < rooms.size() && rooms.at(playerRow).at(playerColumn + 1).getEvent() != NULL)
  {
    rooms.at(playerRow).at(playerColumn + 1).getEvent()->percept();
  }
  else if(playerColumn + 1 < rooms.size() && rooms.at(playerRow).at(playerColumn + 1).getArrowEvent() != NULL)
  {
    rooms.at(playerRow).at(playerColumn + 1).getArrowEvent()->percept();
  }

  if(playerColumn - 1 > 0 && rooms.at(playerRow).at(playerColumn - 1).getEvent() != NULL)
  {
    rooms.at(playerRow).at(playerColumn - 1).getEvent()->percept();
  }
  else if(playerColumn - 1 > 0 && rooms.at(playerRow).at(playerColumn - 1).getArrowEvent() != NULL)
  {
    rooms.at(playerRow).at(playerColumn - 1).getArrowEvent()->percept();
  }
}

/*********************************************************************
** Function: playerChoiceShoot
** Description: Gives the user options for which direction they want to shoot.
** Parameters: int / Game
** Pre-Conditions: Takes in userInput
** Post-Conditions: Correctly returns the users input.
** ******************************************************************/

int Game::playerChoiceShoot()
{
  int shootChoice;
  int userInput;

  if(arrow < 3)
  {
    cout << "Would you like to shoot an arrow?" << endl;
    cout << "Enter a 1 for YES or a 2 for NO: ";
    cin >> userInput;

    if(userInput == 1)
    {
      cout << endl;
      cout << "Which direction would you like to shoot the arrow?" << endl;
      cout << "1 - Left" << endl;
      cout << "2 - Right" << endl;
      cout << "3 - Up" << endl;
      cout << "4 - Down" << endl << endl;
      cout << "Choose a coresponding integer value to make your choice: ";
      cin >> shootChoice;

      arrow++;
    }
  }

  return shootChoice;
}

/*********************************************************************
** Function: moveArrow
** Description: Based in userInput, players arrow will be moved.
** Parameters: void / Game
** Pre-Conditions: takes in value from playerChoiceShoot.
** Post-Conditions: Correctly moves the arrow.
** ******************************************************************/

void Game::shootArrow(int shootChoice)
{

  switch(shootChoice)
  {
    case 1:

    shootArrowLeft();

    break;

    case 2:

    shootArrowRight();

    break;

    case 3:

    shootArrowUp();

    break;

    case 4:

    shootArrowDown();

    break;
  }
}

/*********************************************************************
** Function: shootArrowLeft
** Description: Shoots an arrow at least three rooms / checks for if killed Wumpus.
** Parameters: void / Game
** Pre-Conditions: Must be within the bounds of the gameBoard.
** Post-Conditions: Correctly moves the the arrow / while checking for Wumpus.
** ******************************************************************/

void Game::shootArrowLeft()
{
  for(int i = 1; i <= 3; i++)
  {
    while(playerColumn - i >= 0)
    {
      if(rooms.at(playerRow).at(playerColumn - i).getArrowEvent() != NULL)
      {
        rooms.at(playerRow).at(playerColumn - i).getArrowEvent()->arrowHit(this);
        checkHit = true;
      }
      break;
    }
    break;
  }

  if(checkHit == false)
  {
    for(int i = 0; i < rooms.size(); i++)
    {
      for(int j = 0; j < rooms.at(i).size(); j++)
      {
        if(rooms.at(i).at(j).getArrowEvent() != NULL)
        {
          rooms.at(i).at(j).getArrowEvent()->arrowMiss(this);
        }
      }
    }
  }
}

/*********************************************************************
** Function: shootArrowRight
** Description: Shoots an arrow at least three rooms / checks for if killed Wumpus.
** Parameters: void / Game
** Pre-Conditions: Must be within the bounds of the gameBoard.
** Post-Conditions: Correctly moves the the arrow / while checking for Wumpus.
** ******************************************************************/

void Game::shootArrowRight()
{
  for(int i = 1; i <= 3; i++)
  {
    while(playerColumn + i < rooms.size())
    {
      if(rooms.at(playerRow).at(playerColumn + i).getArrowEvent() != NULL)
      {
        rooms.at(playerRow).at(playerColumn + i).getArrowEvent()->arrowHit(this);
        checkHit = true;
      }
      break;
    }
    break;
  }

  if(checkHit == false)
  {
    for(int i = 0; i < rooms.size(); i++)
    {
      for(int j = 0; j < rooms.at(i).size(); j++)
      {
        if(rooms.at(i).at(j).getArrowEvent() != NULL)
        {
          rooms.at(i).at(j).getArrowEvent()->arrowMiss(this);
        }
      }
    }
  }
}

/*********************************************************************
** Function: shootArrowUp
** Description: Shoots an arrow at least three rooms / checks for if killed Wumpus.
** Parameters: void / Game
** Pre-Conditions: Must be within the bounds of the gameBoard.
** Post-Conditions: Correctly moves the the arrow / while checking for Wumpus.
** ******************************************************************/

void Game::shootArrowUp()
{
  for(int i = 1; i <= 3 && playerRow - i >= 0; i++)
  {
    while(playerRow - i >= 0)
    {
      if(rooms.at(playerRow - 1).at(playerColumn).getArrowEvent() != NULL)
      {
        rooms.at(playerRow - 1).at(playerColumn).getArrowEvent()->arrowHit(this);
        checkHit = true;
      }
      break;
    }
    break;
  }

  if(checkHit == false)
  {
    for(int i = 0; i < rooms.size(); i++)
    {
      for(int j = 0; j < rooms.at(i).size(); j++)
      {
        if(rooms.at(i).at(j).getArrowEvent() != NULL)
        {
          rooms.at(i).at(j).getArrowEvent()->arrowMiss(this);
        }
      }
    }
  }
}

/*********************************************************************
** Function: shootArrowDown
** Description: Shoots an arrow at least three rooms / checks for if killed Wumpus.
** Parameters: void / Game
** Pre-Conditions: Must be within the bounds of the gameBoard.
** Post-Conditions: Correctly moves the the arrow / while checking for Wumpus.
** ******************************************************************/

void Game::shootArrowDown()
{
  for(int i = 1; i <= 3 && playerRow + i <= rooms.size(); i++)
  {
    while(playerRow + i < rooms.size())
    {
      if(rooms.at(playerRow + 1).at(playerColumn).getArrowEvent() != NULL)
      {
        rooms.at(playerRow + 1).at(playerColumn).getArrowEvent()->arrowHit(this);
        checkHit = true;
      }
      break;
    }
    break;
  }

  if(checkHit == false)
  {
    for(int i = 0; i < rooms.size(); i++)
    {
      for(int j = 0; j < rooms.at(i).size(); j++)
      {
        if(rooms.at(i).at(j).getArrowEvent() != NULL)
        {
          rooms.at(i).at(j).getArrowEvent()->arrowMiss(this);
        }
      }
    }
  }
}

/*********************************************************************
** Function: setPit
** Description: Mutator for the pit.
** Parameters: void / Game
** Pre-Conditions: Must be of bool type.
** Post-Conditions: Sets pit = the taken in value.
** ******************************************************************/

void Game::setPit(bool fallInPit)
{
  pit = fallInPit;
}

/*********************************************************************
** Function: getPit
** Description: Accessor for the pit.
** Parameters: void / Game
** Pre-Conditions: Must be of bool type.
** Post-Conditions: Returns the pit boolean value.
** ******************************************************************/

bool Game::getPit()
{
  return pit;
}

/*********************************************************************
** Function: setGold
** Description: Mutator for the gold.
** Parameters: void / Game
** Pre-Conditions: Must be of bool type.
** Post-Conditions: Sets gold = the taken in value.
** ******************************************************************/

void Game::setGold(bool collectGold)
{
  gold = collectGold;
}

/*********************************************************************
** Function: getGold
** Description: Accessor for the Gold.
** Parameters: void / Game
** Pre-Conditions: Must be of bool type.
** Post-Conditions: Returns the gold boolean value.
** ******************************************************************/

bool Game::getGold()
{
  return gold;
}

/*********************************************************************
** Function: setSameRoomWumpus
** Description: Mutator for the Wumpus.
** Parameters: void / Game
** Pre-Conditions: Must be of bool type.
** Post-Conditions: Sets Wumpus = the taken in value.
** ******************************************************************/

void Game::setSameRoomWumpus(bool sameRoomWumpus)
{
  wumpus = sameRoomWumpus;
}

/*********************************************************************
** Function: getSameRoomWumpus
** Description: Accessor for the Wumpus.
** Parameters: void / Game
** Pre-Conditions: Must be of bool type.
** Post-Conditions: Returns the Wumpus boolean value.
** ******************************************************************/

bool Game::getSameRoomWumpus()
{
  return wumpus;
}

/*********************************************************************
** Function: checkWin
** Description: Checks to see if player has won.
** Parameters: void / Game
** Pre-Conditions: Must have conditions that need to be met.
** Post-Conditions: If logic is satisfied the player wins the game.
** ******************************************************************/

bool Game::checkWin()
{
  if(getGold() == true && playerRow == startX && playerColumn == startY && checkHit == true)
  {
    cout << "You have won Hunt the Wumpus!" << endl << endl;

    return true;
  }

  return false;
}
