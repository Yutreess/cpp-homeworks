// Programmer: Justus Peterson-Rhodes
// Student ID: jepfn5
// Section:    A
// Date:       10/15/2018
// File:       header.h
// Description:Manipulate a list of burgers
//             by randomly generating burgers,
//             presenting the list of burgers,
//             and removing burgers
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
using namespace std;

// CONSTANTS

const int SIZE = 37;
const string DEFAULT = "Krusty";
const string BURGER  = "Burger";
// Burger ingreedient costs
const float PICKLE_PRICE = 0.25;
const float PATTY_PRICE  = 0.75;
const float BACON_PRICE  = 0.50;
const float BUN_PRICE    = 0.50;
// Name per # of Patties
const string SINGLE = "Single";
const string DOUBLE = "Double";
const string TRIPLE = "Triumph";
// Name per Ounces of Bacon
const string ZERO_BACON  = "Health Master";
const string ONE_BACON   = "Bacon";
const string TWO_BACON   = "Wilbur";
const string THREE_BACON = "Klogger";
// Name per Ounces of Pickles
const string ZERO_PICKLE  = "Tasteless";
const string ONE_PICKLE   = "Pickly";
const string TWO_PICKLE   = "Garden-Fresh";
const string THREE_PICKLE = "Kermit";
// Special Case Burger names & Space Insert
const string SIX_MEAT_SHORT_PICKLE = "Koronary";
const string MORE_PICKLE_LESS_MEAT = "Veggie";
const string SP		     = " ";
// Minimum and Maximum ingredient values
const short MIN_PATTIES = 1;
const short MAX_PATTIES = 3;
const short MIN_BACON = 0;
const short MAX_BACON = 3;
const short MIN_PICKLES = 0;
const short MAX_PICKLES = 3;

// STRUCTS

struct Burger
{
  string bName = "";
  double bPrice = 0.0;
  short bPatties = 0;
  short bBacon = 0;
  short bPickles = 0;
};

// FUNCTION PROTOTYPES

// OPTION 1

// Description:  Returns a random interval within the specified
//               interval inclusive.
// Precondition: none
// Postcondition:A random number within the interval
//               is returned
short randInterval(const short lower, const short upper);

// Description:  Generate a new Burger along with it's attributes
//               (Patties, Bacon, and Pickles)
// Precondition: none
// Postcondition:A new burger is added to the Burger array
void generateBurger(Burger burgers[], int & dataSet);


// OPTION 2
// Description:  Prints a list of all Burgers in the Burger array
//               Along with their ingredients
// Precondition: none
// Postcondition:Output lists all burgers and their ingredients
void printBurgerList(Burger burgers[], const int dataSet);

// Description:  Sorts burger array into
//               alphabetical order of their names
// Precondition: Burger array contains at least 2 burgers
// Postcondition:Burger array is rearranged
//               into alphabetical order
void sortBurgers(Burger burgers[], const int dataSet);

// OPTION 3
// Description:  Removes a burger from the list
// Precondition: Burger array contains burgers within in.
// Postcondition:Burger array removes specified burger.
void removeBurger(Burger burgers[], int & dataSet);

#endif
