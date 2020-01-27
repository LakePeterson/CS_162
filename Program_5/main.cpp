/******************************************************
** Author: Lake Peterson
** Date: March 20, 2019
** Description: Final Project
******************************************************/

#include "maze.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[])
{
  ifstream file;

  if(argc != 2)
  {
    cout << "You do not have the correct amount of arguments!" << endl;

    return 1;
  }

  file.open(argv[1]);

  if(!file.is_open())
  {
    cout << "File could not be successfully opened" << endl;

    return 1;
  }

  Maze maze(file);

  maze.print();

  return 0;
}
