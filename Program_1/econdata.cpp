#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>
#include "econdata.hpp"

using namespace std;

/********************************************************************
* ** Function: intro
* ** Description: Prints out the instruction of the program for the user.
* ** Parameters: void
* ** Pre-Conditions: Takes in predetermined text
* ** Post-Conditions: Outputs text
* ******************************************************************/

void intro()
{
  cout << endl;

  cout << "Hi! Welcome to my program in which you will be able to explore a small set of " << endl;
  cout << "state and county economic data. At the end you will be asked if you wish to continue " << endl;
  cout << "searching through the data or if you wish to end your session. The data includes: " << endl;

  cout << endl;

  cout << "Statewide 2007 unemployment rate" << endl;
  cout << "Statewide 2015 unemployment rate" << endl;
  cout << "Statewide median household income" << endl;

  cout << endl;

  cout << "For some number of counties in the state:" << endl;

  cout << endl;

  cout << "County 2007 unemployment rate" << endl;
  cout << "County 2015 unemployment rate" << endl;
  cout << "County median household income" << endl;
}

/********************************************************************
* ** Function: menuStates
* ** Description: Prints out the menu of the econ data for the user.
* ** Parameters: void
* ** Pre-Conditions: Takes in predetermined text
* ** Post-Conditions: Outputs text
* ******************************************************************/

void menuStates()
{
  cout << endl;

  cout << "Here is your menu, where you will be able to explore a given amount of economic data." << endl;
  cout << "Choose the corresponding integer value that relates to the data you wish to explore." << endl;

  cout << endl;

  cout << "1: State with the highest median household income" << endl;
  cout << "2: State with the lowest median household income" << endl;
  cout << "3: State with the highest unemployment in 2015" << endl;
  cout << "4: State with the lowest unemployment in 2015" << endl;
  cout << "5: States in sorted order by change in unemployment from 2007 to 2015" << endl;
  cout << "6: States in sorted order based on median household income" << endl;
  cout << "7: Select a state to further explore the data of the counties within a state" << endl;
}

/********************************************************************
* ** Function: allocate_states
* ** Description: Dynamically allocates a 1-D array based on the number of states.
* ** Parameters: struct state*
* ** Pre-Conditions: Takes in the number of states.
* ** Post-Conditions: Creates an array the sze of the number of states.
* ******************************************************************/

struct state* allocate_states(int numState)
{
  struct state *sArray = new state[numState];

  return sArray;
}

/********************************************************************
* ** Function: read_state_data
* ** Description: Reads in the text file data, and properly assigns it to the correct variable.
* ** Parameters: void
* ** Pre-Conditions: Takes in file data, reads it into correct struct varible.
* ** Post-Conditions: All data has been read in and assigned correctly.
* ******************************************************************/

void read_state_data(struct state* states, int numState, ifstream& file)
{
  for(int i = 0; i < numState; i++)
  {
    file >> states[i].name;
    file >> states[i].unemployed_2007;
    file >> states[i].unemployed_2015;
    file >> states[i].med_income;
    file >> states[i].n_counties;
    states[i].counties = allocate_counties(states[i].n_counties);
    read_county_data(states[i].counties, states[i].n_counties, file);
  }
}

/********************************************************************
* ** Function: allocate_counties
* ** Description: Dynamically allocates a 1-D array based on the number of counties.
* ** Parameters: struct county*
* ** Pre-Conditions: Takes in the number of counties.
* ** Post-Conditions: Creates an array the sze of the number of counties.
* ******************************************************************/

struct county* allocate_counties(int n_counties)
{
  struct county *cArray = new county[n_counties];
}

/********************************************************************
* ** Function: read_county_data
* ** Description: Reads in the text file data, and properly assigns it to the correct variable.
* ** Parameters: void
* ** Pre-Conditions: Takes in file data, reads it into correct struct varible.
* ** Post-Conditions: All data has been read in and assigned correctly.
* ******************************************************************/

void read_county_data(struct county* counties, int n_counties, ifstream& file)
{
  for(int i = 0; i < n_counties; i++)
  {
    file >> counties[i].name;
    file >> counties[i].unemployed_2007;
    file >> counties[i].unemployed_2015;
    file >> counties[i].med_income;
  }
}

/********************************************************************
* ** Function: stateHighMedIncome
* ** Description: Sorts through median income for states and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all state median income data.
* ** Post-Conditions: The median income data has been sorted in desired order.
* ******************************************************************/

bool stateHighMedIncome(const state &a, const state &b)
{
  return a.med_income < b.med_income;
}

/********************************************************************
* ** Function: stateLowMedIncome
* ** Description: Sorts through median income for states and orders them low to high.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all state median income data.
* ** Post-Conditions: The median income data has been sorted in desired order.
* ******************************************************************/

bool stateLowMedIncome(const state &a, const state &b)
{
  return a.med_income > b.med_income;
}

/********************************************************************
* ** Function: stateHighUnemployment
* ** Description: Sorts through unemployment data for states and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all state unemployment data (2015).
* ** Post-Conditions: The unemployment data has been sorted in desired order.
* ******************************************************************/

bool stateHighUnemployment(const state &a, const state &b)
{
  return a.unemployed_2015 < b.unemployed_2015;
}

/********************************************************************
* ** Function: stateLowUnemployment
* ** Description: Sorts through unemployment data for states and orders them low to high.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all state unemployment data (2015).
* ** Post-Conditions: The unemployment data has been sorted in desired order.
* ******************************************************************/

bool stateLowUnemployment(const state &a, const state &b)
{
  return a.unemployed_2015 > b.unemployed_2015;
}

/********************************************************************
* ** Function: stateCompare
* ** Description: Sorts through unemployment data for states and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all state unemployment data (2015) and (2007).
* ** Post-Conditions: The unemployment data has been sorted in desired order.
* ******************************************************************/

bool stateCompare(const state &a, const state &b)
{
  return (a.unemployed_2015 - a.unemployed_2007) > (b.unemployed_2015 - b.unemployed_2007);
}

/********************************************************************
* ** Function: stateCompareMedSal
* ** Description: Sorts through median income for states and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all state median income data.
* ** Post-Conditions: The median income data has been sorted in desired order.
* ******************************************************************/

bool stateCompareMedSal(const state &a, const state &b)
{
  return a.med_income > b.med_income;
}

/********************************************************************
* ** Function: countyHighMedIncome
* ** Description: Sorts through median income for counties and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all county median income data.
* ** Post-Conditions: The median income data has been sorted in desired order.
* ******************************************************************/

bool countyHighMedIncome(const county &a, const county &b)
{
  return a.med_income < b.med_income;
}

/********************************************************************
* ** Function: countyLowMedIncome
* ** Description: Sorts through median income for counties and orders them low to high.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all county median income data.
* ** Post-Conditions: The median income data has been sorted in desired order.
* ******************************************************************/

bool countyLowMedIncome(const county &a, const county &b)
{
  return a.med_income > b.med_income;
}

/********************************************************************
* ** Function: countyHighUnemployment
* ** Description: Sorts through unemployment data for counties and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all county unemployment data (2015).
* ** Post-Conditions: The unemployment data has been sorted in desired order.
* ******************************************************************/

bool countyHighUnemployment(const county &a, const county &b)
{
  return a.unemployed_2015 < b.unemployed_2015;
}

/********************************************************************
* ** Function: countyHighUnemployment
* ** Description: Sorts through unemployment data for counties and orders them low to high.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all county unemployment data (2015).
* ** Post-Conditions: The unemployment data has been sorted in desired order.
* ******************************************************************/

bool countyLowUnemployment(const county &a, const county &b)
{
  return a.unemployed_2015 > b.unemployed_2015;
}

/********************************************************************
* ** Function: countyCompare
* ** Description: Sorts through unemployment data for states and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all county unemployment data (2015) and (2007).
* ** Post-Conditions: The unemployment data has been sorted in desired order.
* ******************************************************************/

bool countyCompare(const county &a, const county &b)
{
  return (a.unemployed_2015 - a.unemployed_2007) > (b.unemployed_2015 - b.unemployed_2007);
}

/********************************************************************
* ** Function: stateCountyMedSal
* ** Description: Sorts through median income for counties and orders them high to low.
* ** Parameters: bool
* ** Pre-Conditions: Takes in all county median income data.
* ** Post-Conditions: The median income data has been sorted in desired order.
* ******************************************************************/

bool countyCompareMedSal(const county &a, const county &b)
{
  return a.med_income > b.med_income;
}

/********************************************************************
* ** Function: stateInfo
* ** Description: Encapsulates all data for counties and prints out desired data.
* ** Parameters: void
* ** Pre-Conditions: Takes in all county data.
* ** Post-Conditions: Prints out the desired data.
* ******************************************************************/

void stateInfo(state wantedState)
{
  sort(wantedState.counties, wantedState.counties + wantedState.n_counties, countyHighMedIncome);

  cout << "County with the highest median household income: " << wantedState.counties[wantedState.n_counties - 1].name << endl;

  sort(wantedState.counties, wantedState.counties + wantedState.n_counties, countyLowMedIncome);

  cout << "County with the lowest median household income: " << wantedState.counties[wantedState.n_counties - 1].name << endl;

  sort(wantedState.counties, wantedState.counties + wantedState.n_counties, countyHighUnemployment);

  cout << "County with the highest unemployment in the year 2015: " << wantedState.counties[wantedState.n_counties - 1].name << endl;

  sort(wantedState.counties, wantedState.counties + wantedState.n_counties, countyLowUnemployment);

  cout << "County with the lowest unemployment in the year 2015: " << wantedState.counties[wantedState.n_counties - 1].name << endl;

  sort(wantedState.counties, wantedState.counties + wantedState.n_counties, countyCompare);

  cout << "County sorted in order by change in unemployment from 2007 to 2015: ";

  for(int i = 0; i < wantedState.n_counties; i++)
  {
    cout << wantedState.counties[i].name << " ";
  }

  cout << endl;

  sort(wantedState.counties, wantedState.counties + wantedState.n_counties, countyCompareMedSal);

  cout << "Counties sorted in order by largest to lowest median salary: ";

  for(int i = 0; i < wantedState.n_counties; i++)
  {
    cout << wantedState.counties[i].name << " ";
  }

  cout << endl;
}

/********************************************************************
* ** Function: menuChoice
* ** Description: Prints out the users desired menu choice provided from above.
* ** Parameters: void
* ** Pre-Conditions: Takes in user input.
* ** Post-Conditions: Prints out the users selection.
* ******************************************************************/

void menuChoice(state* states, int numStates, int userInput)
{
int stateInput;

  switch(userInput)
  {
    case 1:

      sort(states, states + numStates, stateHighMedIncome);

      cout << "State with the highest median household income: " << states[numStates - 1].name << endl;

    break;

    case 2:

      sort(states, states + numStates, stateLowMedIncome);

      cout << "State with the lowest median household income: " << states[numStates - 1].name << endl;

    break;

    case 3:

      sort(states, states + numStates, stateHighUnemployment);

      cout << "State with the highest unemployment in the year 2015: " << states[numStates - 1].name << endl;

    break;

    case 4:

      sort(states, states + numStates, stateLowUnemployment);

      cout << "State with the lowest unemployment in the year 2015: " << states[numStates - 1].name << endl;

    break;

    case 5:

      sort(states, states + numStates, stateCompare);

      cout << "States sorted in order by change in unemployment from 2007 to 2015: ";

      for(int i = 0; i < numStates; i++)
      {
        cout << states[i].name << " ";
      }

      cout << endl;

    break;

    case 6:

      sort(states, states + numStates, stateCompareMedSal);

      cout << "States sorted in order by largest to lowest median salary: ";

      for(int i = 0; i < numStates; i++)
      {
        cout << states[i].name << " ";
      }

      cout << endl;

    break;

    case 7:

      cout << "Here are your states to choose from: " << endl;

      cout << endl;

      for(int i = 0; i < numStates; i++)
      {
        cout << i + 1 << ": " << states[i].name << endl;
      }
      cout << endl;

      cout << "What state would you like: ";
      cin >> stateInput;

      cout << endl;

      stateInfo(states[stateInput-1]);

    break;
  }
}

void free_state_data(struct state* states)
{
  delete[] states;
}
