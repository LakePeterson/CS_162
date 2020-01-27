#include "maze.hpp"
#include <iostream>

using namespace std;

/*********************************************************************
** Function: Maze
** Description: Paramaterized constructor for the Maze class.
** Parameters: Maze / Maze
** Pre-Conditions: Must take in the file.
** Post-Conditions: Reads in first three values for maze dimensions.
** ******************************************************************/

Maze::Maze(std::ifstream& file)
{
  count = 0;

  file >> level >> row >> column;
  file.ignore();

  for(int i = 0; i < level; i++)
  {
    MazeLevel temp(file, row, column);
    l.push_back(temp);
  }
}

/********************************************************************
* ** Function: getLevel
* ** Description: An accessor for the Level of the maze.
* ** Parameters: int
* ** Pre-Conditions: Access to the level variable.
* ** Post-Conditions: Returns the value of Level.
* ******************************************************************/

int Maze::getLevel()
{
  return level;
}

/********************************************************************
* ** Function: getRow
* ** Description: An accessor for the Row of the maze.
* ** Parameters: int
* ** Pre-Conditions: Access to the Row variable.
* ** Post-Conditions: Returns the value of Row.
* ******************************************************************/

int Maze::getRow()
{
  return row;
}

/********************************************************************
* ** Function: getColumn
* ** Description: An accessor for the Column of the maze.
* ** Parameters: int
* ** Pre-Conditions: Access to the Column variable.
* ** Post-Conditions: Returns the value of Column.
* ******************************************************************/

int Maze::getColumn()
{
  return column;
}

/********************************************************************
* ** Function: print
* ** Description: A middle man funtion to print the maze.
* ** Parameters: void
* ** Pre-Conditions: Access to the mazeLevel class.
* ** Post-Conditions: Allows the maze to be printed from main.
* ******************************************************************/

void Maze::print()
{
  l.at(count).print();
}
