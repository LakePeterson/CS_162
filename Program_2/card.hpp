#ifndef __CARD_HPP
#define __CARD_HPP

class Card
{
  private:
    int rank;
    int suit;
  public:
    Card();
    ~Card(); 
    void setRank(int);
    void setSuit(int);
    int getRank();
    void printDealtCards();
};

#endif
