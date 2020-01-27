#ifndef __OPENSPACE_HPP
#define __OPENSPACE_HPP

#include "mazeLocation.hpp"

using namespace std;

class OpenSpace : public MazeLocation
{
  private:
    bool has_student;
    bool has_ta;
    bool has_skill;
    bool has_ladder;
    bool has_instructor;
  public:
    OpenSpace();
    void set_has_student(bool);
    void set_has_ta(bool);
    void set_has_instructor(bool);
    void set_has_ladder(bool);
    void set_has_skill(bool);
    bool is_occupiable();
    char get_display_character();
    MazeLocation *clone();
};

#endif
