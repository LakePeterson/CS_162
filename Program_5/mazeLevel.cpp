#include <iostream>
#include "mazeLevel.hpp"
#include "wall.hpp"
#include "openSpace.hpp"

using namespace std;

/********************************************************************
* ** Function: MazeLevel
* ** Description: A paramterized constructor for MazeLevel.
* ** Parameters: MazeLevel
* ** Pre-Conditions: Access to the file, rows, and columns.
* ** Post-Conditions: Creates the maze from a wall or an open space.
* ******************************************************************/

MazeLevel::MazeLevel(std::ifstream& file, int row, int column)
{
  this->row = row;
  this->column = column;
  char character;

  for(int i = 0; i < row; i++)
  {
    vector<MazeLocation *> row;

    for(int j = 0; j < column; j++)
    {
      MazeLocation *m;

      character = file.get();
      if(character == '#')
      {
        m = new Wall();
      }
      else
      {
        OpenSpace* temp = new OpenSpace();

        if(character == '@')
        {
          temp->set_has_student(true);
        }
        m = temp;
      }
      row.push_back(m);
    }
    file.ignore();
    locations.push_back(row);
  }
}

/********************************************************************
* ** Function: MazeLevel
* ** Description: A copy constructor for mazeLevel.
* ** Parameters: MazeLevel
* ** Pre-Conditions: Has access to the same variables and information.
* ** Post-Conditions: Returns a copy to ensure that a deep copy is made.
* ******************************************************************/

MazeLevel::MazeLevel(const MazeLevel &copy)
{
  row = copy.row;
  column = copy.column;

  for(int i = 0; i < row; i++)
  {
    vector<MazeLocation *> curRow;

    for(int j = 0; j < column; j++)
    {
      curRow.push_back((copy.locations.at(i).at(j)->clone()));
    }
    locations.push_back(curRow);
  }
}

/********************************************************************
* ** Function: ~MazeLevel
* ** Description: Deconstructor for MazeLevel
* ** Parameters: MazeLevel
* ** Pre-Conditions: Ensures two nested for loops of size row and column.
* ** Post-Conditions: Correctly deletes all memory.
* ******************************************************************/

MazeLevel::~MazeLevel()
{
  for(int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      delete locations.at(i).at(j);
    }
  }
}

/********************************************************************
* ** Function: print
* ** Description: Prints the maze out for the user.
* ** Parameters: void
* ** Pre-Conditions: Ensures two nested for loops of size row and column.
* ** Post-Conditions: Correctly prints out maze.
* ******************************************************************/

void MazeLevel::print()
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < column; j++)
    {
      cout << locations.at(i).at(j)->get_display_character();
    }
    cout << endl;
  }
}
