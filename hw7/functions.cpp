// Programmer: Justus Peterson-Rhodes
// Student ID: jepfn5
// Section:    A
// Date:       10/15/2018
// File:       functions.cpp
// Description:Manipulate a list of burgers
//             by randomly generating burgers,
//             presenting the list of burgers,
//             and removing burgers

#include <iostream>
#include <cstdlib>
#include "header.h"

using namespace std;

ostream& operator <<(ostream& os, const Burger& b)
{
  os << b.bName << endl;
  os << "Price: $" << b.bPrice << endl;
  os << "Patties: " << b.bPatties << endl;
  os << "Bacon: " << b.bBacon << endl;
  os << "Pickles: " << b.bPickles << endl;
  return os;
}

short randInterval(const short lower, const short upper)
{
    short val;
    do
    {
      val = rand() % 10;
    }
    while(val < lower
          || val > upper);
    return val;
}

// OPTION 1
void generateBurger(Burger burgers[], int & dataSet)
{
  // Move dataSet to location of new Burger
  // Randomize Ingredient Values
  srand(time(0));
  burgers[dataSet].bPatties = randInterval(MIN_PATTIES, MAX_PATTIES);
  srand(time(0) + 5);
  burgers[dataSet].bBacon = randInterval(MIN_BACON, MAX_BACON);
  srand(time(0) - 2);
  burgers[dataSet].bPickles = randInterval(MIN_PICKLES, MAX_PICKLES);

  // Set Burger Price
  burgers[dataSet].bPrice += BUN_PRICE
                          + (burgers[dataSet].bPatties
                             * PATTY_PRICE)
                          + (burgers[dataSet].bBacon
                             * BACON_PRICE)
                          + (burgers[dataSet].bPickles
                             * PICKLE_PRICE);
  // Decide Burger Name based on ingredients
  burgers[dataSet].bName = DEFAULT;
  // "Veggie" Burger
  if (burgers[dataSet].bPickles >= (burgers[dataSet].bBacon
  + burgers[dataSet].bPatties))
  {
    burgers[dataSet].bName += SP
                              + MORE_PICKLE_LESS_MEAT
                              + SP + BURGER;
  }
  // "Koronary" Burger
  else if ((burgers[dataSet].bBacon
            + burgers[dataSet].bPatties) == 6
            && burgers[dataSet].bPickles < 2)
  {
    burgers[dataSet].bName += SP
                              + SIX_MEAT_SHORT_PICKLE
                              + SP + BURGER;
  }
  // Default Naming
  else
  {
    // Name in respect to Patties
    if (burgers[dataSet].bPatties == 1)
      burgers[dataSet].bName += SP + SINGLE;
    if (burgers[dataSet].bPatties == 2)
      burgers[dataSet].bName += SP + DOUBLE;
    if (burgers[dataSet].bPatties == 3)
      burgers[dataSet].bName += SP + TRIPLE;
    // Name in respect to Bacon
    if (burgers[dataSet].bBacon == 0)
      burgers[dataSet].bName += SP + ZERO_BACON;
    if (burgers[dataSet].bBacon == 1)
      burgers[dataSet].bName += SP + ONE_BACON;
    if (burgers[dataSet].bBacon == 2)
      burgers[dataSet].bName += SP + TWO_BACON;
    if (burgers[dataSet].bBacon == 3)
      burgers[dataSet].bName += SP + THREE_BACON;
    // Name in respect to Pickles
    if (burgers[dataSet].bPickles == 0)
      burgers[dataSet].bName += SP + ZERO_PICKLE
                    + SP + BURGER;
    if (burgers[dataSet].bPickles == 1)
      burgers[dataSet].bName += SP + ONE_PICKLE
                    + SP + BURGER;
    if (burgers[dataSet].bPickles == 2)
      burgers[dataSet].bName += SP + TWO_PICKLE
                    + SP + BURGER;
    if (burgers[dataSet].bPickles == 3)
      burgers[dataSet].bName += SP + THREE_PICKLE
                    + SP + BURGER;
  }
  dataSet++;
}

// OPTION 2
void sortBurgers(Burger burgers[], const int dataSet)
{
  Burger temp = burgers[dataSet + 1];
  for(int i = 1; i < dataSet; i++)
  {
    if(burgers[i - 1].bName > burgers[i].bName)
    {
      temp = burgers[i - 1];
      burgers[i - 1] = burgers[i];
      burgers[i] = temp;
    }
  }
}


void printBurgerList(Burger burgers[], const int dataSet)
{

  for(int i = 0; i < dataSet; i++)
    cout << burgers[i] << endl;
}

// OPTION 3
void removeBurger(Burger burgers[], int & dataSet)
{
  int patties;
  int bacon;
  int pickles;
  int indexRemovedBurg = -3;
  // Prompt to find the burger to remove
  cout << "How many patties does";
  cout << " the burger you'd like to remove have?" << endl;
  cout << "Patties: ";
  cin >> patties;
  cout << "How much bacon does";
  cout << " the burger you'd like to remove have?" << endl;
  cout << "Bacon: ";
  cin >> bacon;
  cout << "How many pickles does";
  cout << " the burger you'd like to remove have?" << endl;
  cout << "Pickles: ";
  cin >> pickles;
  // Find burger to Remove

  for(int i = 0; i < dataSet; i++)
  {
    if(burgers[i].bPatties == patties
       && burgers[i].bBacon == bacon
       && burgers[i].bPickles == pickles)
    {
      indexRemovedBurg = i;
      cout << "The following burger has been removed: " << endl;
      cout << endl;
      cout << burgers[indexRemovedBurg] << endl;
      // Remove Burger
      burgers[indexRemovedBurg].bName = "";
      burgers[indexRemovedBurg].bPrice = 0.0;
      burgers[indexRemovedBurg].bPatties = 0;
      burgers[indexRemovedBurg].bBacon = 0;
      burgers[indexRemovedBurg].bPickles = 0;
      // Move Burgers to Override Removed Burger
      for(int i = indexRemovedBurg + 1;
          indexRemovedBurg <= i
          && i < dataSet;
          i++)
      {
        burgers[i - 1].bName = burgers[i].bName;
        burgers[i - 1].bPatties = burgers[i].bPatties;
        burgers[i - 1].bBacon = burgers[i].bBacon;
        burgers[i - 1].bPickles = burgers[i].bPickles;
      }
      dataSet--;
    }
  }
  if(indexRemovedBurg == -3)
    cout << "Burger Not Found." << endl;
}
