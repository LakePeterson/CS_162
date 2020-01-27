#ifndef __MAZE_HPP
#define __MAZE_HPP

#include "mazeLevel.hpp"

class Maze
{
  private:
    int level;
    int row;
    int column;
    vector<MazeLevel> l;
    int count;

  public:
    Maze(std::ifstream&);
    int getLevel();
    int getRow();
    int getColumn();
    void print();
};

#endif
