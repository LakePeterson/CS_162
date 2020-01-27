#include <string>
#include <iomanip>
#include "zoo.hpp"

using namespace std;

/********************************************************************
** Function: Zoo
** Description: Constructor for Zoo class.
** Parameters: Zoo
** Pre-Conditions: None
** Post-Conditions: None
** *****************************************************************/

Zoo::Zoo()
{
  bankAmount = 100000;
  monkeyArray = NULL;
  otterArray = NULL;
  slothArray = NULL;
  numMonkey = 0;
  numSloth = 0;
  numOtter = 0;
  foodCost = 50.00;
}

/********************************************************************
** Function: ~Zoo
** Description: Default destructor for Zoo class.
** Parameters: Zoo
** Pre-Conditions: None
** Post-Conditions: None
** *****************************************************************/

Zoo::~Zoo()
{
  delete[] monkeyArray;
  delete[] otterArray;
  delete[] slothArray;
}

/********************************************************************
* ** Function: intro
* ** Description: Prints out the instruction of the program for the user.
* ** Parameters: void
* ** Pre-Conditions: Takes in predetermined text.
* ** Post-Conditions: Outputs text.
* ******************************************************************/

void Zoo::intro()
{
  cout << endl;
  cout << "Welcome to the game of Zoo Tycoon, here you are being put " << endl;
  cout << "in charge of your local zoo. You will be in charge of running " << endl;
  cout << "basic zoo operations. You are given 100000 dollars to start out, " << endl;
  cout << "just be sure you make the right decision to avoid going bankrupt!" << endl;
}

/********************************************************************
* ** Function: setBankAmount
* ** Description: A mutator for the original bank amount
* ** Parameters: void
* ** Pre-Conditions: Takes in original amount.
* ** Post-Conditions: Takes a copy of the original amount.
* ******************************************************************/

void Zoo::setBankAmount(int bankAmount)
{
  this->bankAmount = bankAmount;
}

/********************************************************************
* ** Function: getBankAmount
* ** Description: A accessor for the original bank amount.
* ** Parameters: int
* ** Pre-Conditions: Takes in the copied amount.
* ** Post-Conditions: Returns the bank amount for use in program.
* ******************************************************************/

int Zoo::getBankAmount()
{
  return bankAmount;
}

/********************************************************************
 ** Function: validInput
 ** Description: takes in a string and outputs an integer.
 ** Parameters: int
 ** Pre-Conditions: Takes in a user input of any type.
 ** Post-Conditions: Outputs an integer.
 ** *****************************************************************/

int Zoo::valid(std::string str)
{
	int number;
	int sum = 0;

	for(int i = 0; i < str.length(); i++)
	{
		number = str[i];
		number -= 48;

		if(number < 0 || number > 9)
		{
			return INT_MAX;
		}
		sum += number * pow(10, str.length() - 1 - i);
	}
	return sum;
}

/********************************************************************
* ** Function: createMonkey
* ** Description: Creates a monkey object.
* ** Parameters: void
* ** Pre-Conditions: Needs monkey object information.
* ** Post-Conditions: Creates another monkey.
* ******************************************************************/

void Zoo::createMonkey()
{
  Monkey m = Monkey();
  Monkey* tempArray = new Monkey[numMonkey + 1];

  for(int i = 0; i < numMonkey; i++)
  {
    tempArray[i] = monkeyArray[i];
  }
  tempArray[numMonkey] = m;

  if(monkeyArray != NULL)
  {
    delete[] monkeyArray;
  }

  monkeyArray = tempArray;
  numMonkey++;
  bankAmount -= monkeyArray[0].getPurchaseCost();
}

/********************************************************************
* ** Function: deleteMonkey
* ** Description: Deletes a single monkey object.
* ** Parameters: void
* ** Pre-Conditions: Access to the monkey object array.
* ** Post-Conditions: Deletes a single monkey object.
* ******************************************************************/

void Zoo::deleteMonkey()
{
  Monkey* tempArray = new Monkey[numMonkey - 1];

  for(int i = 0; i < numMonkey - 1; i++)
  {
    tempArray[i] = monkeyArray[i];
  }

  delete[] monkeyArray;

  monkeyArray = tempArray;

  numMonkey--;
}

/********************************************************************
* ** Function: createBabyMonkey
* ** Description: Creates a baby monkey object.
* ** Parameters: void
* ** Pre-Conditions: Needs monkey object information.
* ** Post-Conditions: Creates another baby monkey.
* ******************************************************************/

void Zoo::createBabyMonkey()
{
  Monkey m = Monkey();
  m.setAge(0);
  Monkey* tempArray = new Monkey[numMonkey + 1];

  for(int i = 0; i < numMonkey; i++)
  {
    tempArray[i] = monkeyArray[i];
  }
  tempArray[numMonkey] = m;

  if(monkeyArray != NULL)
  {
    delete[] monkeyArray;
  }

  monkeyArray = tempArray;
  numMonkey++;
}

/********************************************************************
* ** Function: createSloth
* ** Description: Creates a sloth object.
* ** Parameters: void
* ** Pre-Conditions: Needs sloth object information.
* ** Post-Conditions: Creates a sloth.
* ******************************************************************/

void Zoo::createSloth()
{
  Sloth s = Sloth();
  Sloth* tempArray = new Sloth[numSloth + 1];

  for(int i = 0; i < numSloth; i++)
  {
    tempArray[i] = slothArray[i];
  }
  tempArray[numSloth] = s;

  if(monkeyArray != NULL)
  {
    delete[] slothArray;
  }
  slothArray = tempArray;
  numSloth++;
  bankAmount -= slothArray[0].getPurchaseCost();
}

/********************************************************************
* ** Function: deleteSloth
* ** Description: Deletes a single sloth object.
* ** Parameters: void
* ** Pre-Conditions: Access to the sloth object array.
* ** Post-Conditions: Deletes a single sloth object.
* ******************************************************************/

void Zoo::deleteSloth()
{
  Sloth* tempArray = new Sloth[numSloth - 1];

  for(int i = 0; i < numSloth - 1; i++)
  {
    tempArray[i] = slothArray[i];
  }

  delete[] slothArray;

  slothArray = tempArray;

  numSloth--;
}

/********************************************************************
* ** Function: createBabySloth
* ** Description: Creates a baby sloth object.
* ** Parameters: void
* ** Pre-Conditions: Needs sloth object information.
* ** Post-Conditions: Creates another baby sloth.
* ******************************************************************/

void Zoo::createBabySloth()
{
  Sloth s = Sloth();
  s.setAge(0);
  Sloth* tempArray = new Sloth[numSloth + 1];

  for(int i = 0; i < numSloth; i++)
  {
    tempArray[i] = slothArray[i];
  }
  tempArray[numSloth] = s;

  if(slothArray != NULL)
  {
    delete[] slothArray;
  }

  slothArray = tempArray;
  numSloth++;
}

/********************************************************************
* ** Function: createOtter
* ** Description: Creates a otter object.
* ** Parameters: void
* ** Pre-Conditions: Needs otter object information.
* ** Post-Conditions: Creates a otter.
* ******************************************************************/

void Zoo::createOtter()
{
  Otter o = Otter();
  Otter* tempArray = new Otter[numOtter + 1];

  for(int i = 0; i < numOtter; i++)
  {
    tempArray[i] = otterArray[i];
  }
  tempArray[numOtter] = o;

  if(otterArray != NULL)
  {
    delete[] otterArray;
  }

  otterArray = tempArray;
  numOtter++;
  bankAmount -= otterArray[0].getPurchaseCost();
}

/********************************************************************
* ** Function: deleteOtter
* ** Description: Deletes a single otter object.
* ** Parameters: void
* ** Pre-Conditions: Access to the otter object array.
* ** Post-Conditions: Deletes a single otter object.
* ******************************************************************/

void Zoo::deleteOtter()
{
  Otter* tempArray = new Otter[numOtter - 1];

  for(int i = 0; i < numOtter - 1; i++)
  {
    tempArray[i] = otterArray[i];
  }

  delete[] otterArray;

  otterArray = tempArray;

  numOtter--;
}

/********************************************************************
* ** Function: createBabyOtter
* ** Description: Creates a baby otter object.
* ** Parameters: void
* ** Pre-Conditions: Needs otter object information.
* ** Post-Conditions: Creates another baby otter.
* ******************************************************************/

void Zoo::createBabyOtter()
{
  Otter o = Otter();
  o.setAge(0);
  Otter* tempArray = new Otter[numOtter + 1];

  for(int i = 0; i < numOtter; i++)
  {
    tempArray[i] = otterArray[i];
  }
  tempArray[numOtter] = o;

  if(otterArray != NULL)
  {
    delete[] otterArray;
  }

  otterArray = tempArray;
  numOtter++;
}

/********************************************************************
* ** Function: checkBuyAnimal
* ** Description: Checks userInput for when they buy an animal.
* ** Parameters: int
* ** Pre-Conditions: Needs user input.
* ** Post-Conditions: Return a valid output for buying an animal.
* ******************************************************************/

int Zoo::checkBuyAnimal()
{
  string checkBuy;
  int buy;

  cout << endl;
  cout << "Would you like to buy an animal?" << endl;
  cout << "Enter 1 for YES or 2 for NO: ";

  do
	{
		getline(cin, checkBuy);
    buy = valid(checkBuy);

		if(buy != 1 && buy != 2)
		{
			cout << "Please enter a valid input: ";
		}
	}while(buy != 1 && buy != 2);

  cout << endl;

  return buy;
}

/********************************************************************
* ** Function: buyAnimalType
* ** Description: Allows user to select what animal they want to buy.
* ** Parameters: void
* ** Pre-Conditions: Takes in users selection.
* ** Post-Conditions: Creates the animal that they selected.
* ******************************************************************/

void Zoo::buyAnimalType(int buy)
{
  string buyAnimal;
  int animalType;

  if(buy == 1)
  {
    cout << "What type of animal would you like to buy, you can buy up to " << endl;
    cout << "two animals per day, but it has to be of the same species." << endl;
    cout << "The following index will indicate what value represents each animal." << endl << endl;
    cout << "1 - Buy one Monkey (15000)" << endl;
    cout << "2 - Buy two Monkies (30000)" << endl;
    cout << "3 - Buy one Sea Otter (5000)" << endl;
    cout << "4 - Buy two Sea Otters (10000)" << endl;
    cout << "5 - Buy one Sloth (2000)" << endl;
    cout << "6 - Buy two Sloths (4000)" << endl << endl;
    cout << "Current bank balance: " << bankAmount << endl << endl;
    cout << "What animal would you like to buy: ";

    do
  	{
  		getline(cin, buyAnimal);
      animalType = valid(buyAnimal);

  		if(animalType != 1 && animalType != 2 && animalType != 3 && animalType != 4 && animalType != 5 && animalType != 6)
  		{
  			cout << "Please enter a valid input: ";
  		}
  	}while(animalType != 1 && animalType != 2 && animalType != 3 && animalType != 4 && animalType != 5 && animalType != 6);

    cout << endl;

    switch(animalType)
    {
      case 1:
        createMonkey();

        break;

      case 2:
        createMonkey();
        createMonkey();

        break;

      case 3:
        createOtter();

        break;

      case 4:
        createOtter();
        createOtter();

        break;

      case 5:
        createSloth();

        break;

      case 6:
        createSloth();
        createSloth();

        break;
    }
  }
}

/********************************************************************
* ** Function: specialEventChoice
* ** Description: Randomly chooses a special event for the day.
* ** Parameters: void
* ** Pre-Conditions: Ranomized number between 0 - 3.
* ** Post-Conditions: Chooses a function that relates to the special event.
* ******************************************************************/

void Zoo::specialEventChoice()
{
  int choice = rand() % 4;

  switch(choice)
  {
    case 0:

    sickAnimal();

    break;

    case 1:

    createBaby();

    break;

    case 2:

    attendenceBoom();

    break;

    case 3:

    cout << "No special event occured today!" << endl << endl;

    break;
  }
}

/********************************************************************
* ** Function: attendenceBoom
* ** Description: Creates a bonus revenue for the zoo.
* ** Parameters: void
* ** Pre-Conditions: Bonus is overwritten each time called.
* ** Post-Conditions: Adds bonus to the bank amount.
* ******************************************************************/

void Zoo::attendenceBoom()
{
  int bonus = 0;

  cout << "Congradulations, you have had an attendence boom today!" << endl;

  for(int i = 0; i < numMonkey; i++)
  {
    bonus = rand() % 251 + 250;

    bankAmount += bonus;
  }

  cout << "Your zoo had a bonus of " << bonus << " dollars today!" << endl << endl;
}

/********************************************************************
* ** Function: createBaby
* ** Description: Randomly chooses a species to have a baby.
* ** Parameters: void
* ** Pre-Conditions: Randomly picks a species.
* ** Post-Conditions: Creates the necissary amount of babies for the species.
* ******************************************************************/

void Zoo::createBaby()
{
  int totalAdults = 0;
  int choice = 0;
  int count = 0;

  for(int i = 0; i < numMonkey; i++)
  {
    if(monkeyArray[i].getAge() >= 1095)
    {
      totalAdults++;
    }
  }
  for(int i = 0; i < numSloth; i++)
  {
    if(slothArray[i].getAge() >= 1095)
    {
      totalAdults++;
    }
  }
  for(int i = 0; i < numOtter; i++)
  {
    if(otterArray[i].getAge() >= 1095)
    {
      totalAdults++;
    }
  }

  choice = rand() % totalAdults;

  for(int i = 0; i < numMonkey; i++)
  {
    if(monkeyArray[i].getAge() >= 1095)
    {
      if(count == choice)
      {
        cout << "Congradulations, one of your Monkey's has had a baby!" << endl << endl;

        for(int j = 0; j < monkeyArray[0].getNumBabies(); j++)
        {
          createBabyMonkey();
        }
        return;
      }
      count++;
    }
  }
  for(int i = 0; i < numSloth; i++)
  {
    if(slothArray[i].getAge() >= 1095)
    {
      if(count == choice)
      {
        cout << "Congradulations, one of your Sloth's has had three babies!" << endl << endl;

        for(int j = 0; j < slothArray[0].getNumBabies(); j++)
        {
          createBabySloth();
        }
        return;
      }
      count++;
    }
  }
  for(int i = 0; i < numOtter; i++)
  {
    if(otterArray[i].getAge() >= 1095)
    {
      cout << "Congradulations, one of your Sea Otter's has had two babies!" << endl << endl;

      for(int j = 0; j < otterArray[0].getNumBabies(); j++)
      {
        createBabyOtter();
      }
      return;
    }
    count++;
  }
}

/********************************************************************
* ** Function: sickAnimal
* ** Description: Randomly chooses and animal to be sick.
* ** Parameters: void
* ** Pre-Conditions: Needs user input.
* ** Post-Conditions: Either animal dies or is treated.
* ******************************************************************/

void Zoo::sickAnimal()
{
  int numSpecies = 0;
  int choice = 0;
  int count = 0;
  string checkInput;
  int userInput;

  if(numMonkey > 0)
  {
    numSpecies++;
  }
  if(numOtter > 0)
  {
    numSpecies++;
  }
  if(numSloth > 0)
  {
    numSpecies++;
  }

  if(numSpecies == 0)
  {
    return;
  }
  else if(numSpecies > 0)
  {
    choice = rand() % numSpecies;

    if(count == choice && numMonkey > 0)
    {
      if(bankAmount > 7500)
      {
        cout << "Uh Oh! One of your Monkey's has gotten sick!" << endl;
        cout << "Would you like to heal your monkey for 7500 dollars?" << endl;
        cout << "Enter 1 for YES or 2 for NO: ";

        do
      	{
      		getline(cin, checkInput);
          userInput = valid(checkInput);

      		if(userInput != 1 && userInput != 2)
      		{
      			cout << "Please enter a valid input: ";
      		}
      	}while(userInput != 1 && userInput != 2);

        cout << endl;

        if(userInput == 1)
        {
          bankAmount -= 7500;
          return;
        }
        else if(userInput == 2)
        {
          deleteMonkey();
          return;
        }
      }
      else if(bankAmount < 7500)
      {
        cout << "Due to you not have enough money you are not able to cover the medical expenses of your sick animal." << endl << endl;
        deleteMonkey();
        return;
      }
    }
    else if(count < choice && numMonkey > 0)
    {
      count++;
    }

    if(count == choice && numOtter > 0)
    {
      if(bankAmount > 2500)
      {
        cout << "Uh Oh! One of your Sea Otter's has gotten sick!" << endl;
        cout << "Would you like to heal your sea otter for 2500 dollars?" << endl;
        cout << "Enter 1 for yes or 2 for no: ";

        do
      	{
      		getline(cin, checkInput);
          userInput = valid(checkInput);

      		if(userInput != 1 && userInput != 2)
      		{
      			cout << "Please enter a valid input: ";
      		}
      	}while(userInput != 1 && userInput != 2);

        cout << endl;

        if(userInput == 1)
        {
          bankAmount -= 2500;
          return;
        }
        else if(userInput == 2)
        {
          deleteOtter();
          return;
        }
      }
      else if(bankAmount < 2500)
      {
        cout << "Due to you not have enough money you are not able to cover the medical expenses of your sick animal." << endl << endl;
        deleteOtter();
        return;
      }
    }
    else if(count < choice && numOtter > 0)
    {
      count++;
    }

    if(count == choice && numSloth > 0)
    {
      if(bankAmount > 1000)
      {
        cout << "Uh Oh! One of your Sloth's has gotten sick!" << endl;
        cout << "Would you like to heal your sloth for 1000 dollars?" << endl;
        cout << "Enter 1 for yes or 2 for no: ";

        do
      	{
      		getline(cin, checkInput);
          userInput = valid(checkInput);

      		if(userInput != 1 && userInput != 2)
      		{
      			cout << "Please enter a valid input: ";
      		}
      	}while(userInput != 1 && userInput != 2);

        cout << endl;

        if(userInput == 1)
        {
          bankAmount -= 1000;
          return;
        }
        else if(userInput == 2)
        {
          deleteSloth();
          return;
        }
      }
      else if(bankAmount < 1000)
      {
        cout << "Due to you not have enough money you are not able to cover the medical expenses of your sick animal." << endl << endl;
        deleteSloth();
        return;
      }
    }
    else if(count < choice && numSloth > 0)
    {
      count++;
    }
  }
}

/********************************************************************
* ** Function: dailyFoodCost
* ** Description: Determines what the daily food multiplier is.
* ** Parameters: int
* ** Pre-Conditions: Randomly generates a value between .75 and 1.25.
* ** Post-Conditions: Returns that specific value.
* ******************************************************************/

int Zoo::dailyFoodCost()
{
  float costMultiplier;
  costMultiplier = ((rand() * foodCost) / RAND_MAX) + 75;

  cout << fixed << setprecision(2);

  costMultiplier /= 100;
  foodCost *= costMultiplier;

  return foodCost;
}

/********************************************************************
* ** Function: totalFoodCost
* ** Description: Determines what the daily food cost is.
* ** Parameters: void
* ** Pre-Conditions: Needs the food multiplier.
* ** Post-Conditions: Returns added food cost for each species.
* ******************************************************************/

void Zoo::totalFoodCost(int foodCost)
{
  int foodTotal = 0;

  if(numMonkey > 0)
  {
    foodTotal += monkeyArray[0].getFoodMult() * numMonkey * foodCost;
  }
  if(numSloth > 0)
  {
    foodTotal += slothArray[0].getFoodMult() * numSloth * foodCost;
  }
  if(numOtter > 0)
  {
    foodTotal += otterArray[0].getFoodMult() * numOtter * foodCost;
  }

  cout << "Your food cost for the day was " << foodTotal << " dollars." << endl << endl;

  bankAmount -= foodTotal;
}

/********************************************************************
* ** Function: revenue
* ** Description: Determines what the revenue for the zoo is.
* ** Parameters: void
* ** Pre-Conditions: Access to the amount of animals.
* ** Post-Conditions: Determines the total revenue for the day.
* ******************************************************************/

void Zoo::revenue()
{
  if(numMonkey > 0)
  {
    for(int i = 0; i < numMonkey; i++)
    {
      if(monkeyArray[i].getAge() >= 1095)
      {
        bankAmount += monkeyArray[i].getBaseRevenue();
      }
      else if(monkeyArray[i].getAge() <= 30)
      {
        bankAmount += (2 * monkeyArray[i].getBaseRevenue());
      }
    }
  }
  if(numSloth > 0)
  {
    for(int i = 0; i < numSloth; i++)
    {
      if(slothArray[i].getAge() >= 1095)
      {
        bankAmount += slothArray[i].getBaseRevenue();
      }
      else if(slothArray[i].getAge() <= 30)
      {
        bankAmount += (2 * slothArray[i].getBaseRevenue());
      }
    }
  }
  if(numOtter > 0)
  {
    for(int i = 0; i < numOtter; i++)
    {
      if(otterArray[i].getAge() >= 1095)
      {
        bankAmount += otterArray[i].getBaseRevenue();
      }
      else if(otterArray[i].getAge() <= 30)
      {
        bankAmount += (2 * otterArray[i].getBaseRevenue());
      }
    }
  }
}

/********************************************************************
* ** Function: ageIncrease
* ** Description: Increases an animals age by one after each day.
* ** Parameters: void
* ** Pre-Conditions: Access the species array.
* ** Post-Conditions: Overwrites the age that they had by adding one.
* ******************************************************************/

void Zoo::ageIncrease()
{
  if(numMonkey > 0)
  {
    for(int i = 0; i < numMonkey; i++)
    {
        monkeyArray[i].incrementAge();
    }
  }
  if(numSloth > 0)
  {
    for(int i = 0; i < numSloth; i++)
    {
        slothArray[i].incrementAge();
    }
  }
  if(numOtter > 0)
  {
    for(int i = 0; i < numOtter; i++)
    {
        otterArray[i].incrementAge();
    }
  }
}

/********************************************************************
* ** Function: daySummary
* ** Description: Outputs an end of day summary of the zoo.
* ** Parameters: void
* ** Pre-Conditions: Needs access the bank amount.
* ** Post-Conditions: Returns the text information.
* ******************************************************************/

void Zoo::daySummary()
{
  cout << "At the end of day your current bank amount is " << bankAmount << "." << endl;
}
