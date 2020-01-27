 /******************************************************
 ** Author: Lake Peterson
 ** Date: January 15, 2019
 ** Description: Allows user to explore through a given data file.
 ** Input:
 ** Output:
 ******************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include "econdata.hpp"
#include <fstream>

using namespace std;

int main(int argc, const char * argv[])
{
  ifstream file;
  int numState;
  int userInput;
  string playAgain;

  if(argc != 2)
  {
    cout << "You do not have the correct amount of arguments!" << endl;

    return 1;
  }

  file.open(argv[1], ifstream::in);

  if(!file.is_open())
  {
    cout << "File could not be successfully opened" << endl;

    return 1;
  }

  file >> numState;

  struct state* states = allocate_states(numState);

  read_state_data(states, numState, file);

  intro();

  do{

    menuStates();

    cout << endl;

    cout << "What catagory would you like to explore: ";
    cin >> userInput;

    cout << endl;

    menuChoice(states, numState, userInput);

    cout << endl;

    cout << "Would you like to continue exploring econmic data?" << endl;

    cout << endl;

    do{
      cout << "Enter a Y/y for yes or N/n for no: ";
      cin >> playAgain;

    }while(playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n");

  }while(playAgain == "Y" || playAgain == "y");

  free_state_data(states);

  file.close();

  cout << endl;

return 0;
}
