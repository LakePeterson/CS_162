#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <iostream>
#include "room.hpp"

using namespace std;

class Game
{
  private:
    vector<vector<Room> > rooms;
    int playerRow;
    int playerColumn;
    int arrow;
    int startX;
    int startY;
    bool pit;
    bool wumpus;
    bool gold;
    bool checkHit;

  public:
    Game();
    Game(int);
    vector<vector<Room> > &getRooms();
    void allocateEvent(Event*);
    void allocateGamePieces();
    void allocateArrowEvent(ArrowEvent*);
    void allocatePlayer();
    void allocatePlayerBat();
    void printGameBoard(int);
    void intro();
    int playerChoiceMove();
    void movePlayer(int);
    void checkForEvent();
    void checkForPercept();
    int playerChoiceShoot();
    void shootArrow(int);
    void shootArrowLeft();
    void shootArrowRight();
    void shootArrowUp();
    void shootArrowDown();
    void setPit(bool);
    bool getPit();
    void setGold(bool);
    bool getGold();
    void setSameRoomWumpus(bool);
    bool getSameRoomWumpus();
    bool checkWin();
};



#endif
