#ifndef __WALL_HPP
#define __WALL_HPP

#include "mazeLocation.hpp"

using namespace std;

class Wall : public MazeLocation
{
  public:
    bool is_occupiable();
    char get_display_character();
    MazeLocation *clone();
};

#endif
