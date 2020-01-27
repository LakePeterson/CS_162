#ifndef __MAZELEVEL_HPP
#define __MAZELEVEL_HPP

#include <vector>
#include <fstream>
#include "mazeLocation.hpp"

using namespace std;

class MazeLevel
{
  private:
    vector<vector<MazeLocation*> > locations;
    int row;
    int column;

  public:
    MazeLevel(ifstream&, int, int);
    MazeLevel(const MazeLevel &copy);
    ~MazeLevel();
    void print();
};

#endif
