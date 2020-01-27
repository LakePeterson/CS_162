#ifndef EVENT_HPP
#define EVENT_HPP

class Game;

class Event
{
  private:
  public:
    virtual void triggerEvent(Game *g) = 0;
    virtual void percept() = 0;
    virtual ~Event();
};
#endif
