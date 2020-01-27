#ifndef __MAZELOCATION_HPP
#define __MAZELOCATION_HPP

using namespace std;

class MazeLocation
{
  public:
    virtual bool is_occupiable() = 0;
    virtual char get_display_character() = 0;
    virtual MazeLocation *clone() = 0;
};

#endif
