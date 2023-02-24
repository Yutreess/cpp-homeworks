// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         09/24/2018
// File:         hw5.cpp
// Description:  Given a range of integer values given by the user,
//               print a table for the projected profit for every
//               integer values within said range.

#include <iostream>
#include <cmath>
using namespace std;

// Description:  Outputs a greeting message to the user
// Precondition: none
// Postcondition:Greeting mesage is displayed on the screen
void greeting();

// Description:  Takes user input for the range of
//               values for the variable animalPartsUsed
// Precondition: none
// Postcondition:Lower and Upper value limits for animalPartsUsed are assigned
void promptRangeForAnimalPartsUsed(int & lower, int & upper);

// Description:  Takes user input for the range of
//               values for the variable typesOfAnimals
// Precondition: none
// Postcondition:Lower and Upper value limits for typesOfAnimals are assigned
void promptRangeForTypesOfAnimals(int & lower, int & upper);

// Description:  Calculate the profit by according to Krusty's formula
// Precondition: none
// Postcondition:Return value representing profit expected
float calculateProfit(float animalPartsUsed, float typesOfAnimals);

// Description:  Print the result of calculateProfit() for all values of
//               animalPartsUsed and typesOfAnimals that are in the range
//               given in the promptRangeFor<variable>() functions.
// Precondition: promptRangeForPartsUsed() and promptRangeForTypesOfAnimals()
//               have been executed to give this function the range of values
//               to print.
// Postcondition:A table of values for profit given the two variables are
//               shown on screen
void table(const int lowerAPU, const int upperAPU, const int lowerTOA, const int upperTOA);

// Description:  Prints a signoff message to the user
// Precondition: none
// Postcondition:Signoff message is shown on the screen
void signoff();

int main()
{
  // f(X,Y) = X * e^(-(Y^2)/X)
  // x = animalPartsUsed
  // y = typesOfAnimals

  // User choice to print another table
  char choice;
  // Bounds for the variables
  int lowerAPU;
  int upperAPU;
  int lowerTOA;
  int upperTOA;
  // Force decimals to be printed to 2 places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  // START PROGRAM
  greeting();
  do
  {
    promptRangeForAnimalPartsUsed(lowerAPU, upperAPU);
    promptRangeForTypesOfAnimals(lowerTOA, upperTOA);
    table(lowerAPU, upperAPU, lowerTOA, upperTOA);
    cout << "Print another table of values? [y / n]: ";
    cin >> choice;
  }
  while(choice == 'y');

  signoff();

  return 0;
}

void greeting()
{
  cout << "Hello Krusty the Klown!" << endl;
}

void promptRangeForAnimalPartsUsed(int & lower, int & upper)
{
  cout << "Enter the lower limit for Animal Parts Used: ";
  cin >> lower;
  cout << "Enter the upper limit for Animal Parts Used: ";
  cin >> upper;
}

void promptRangeForTypesOfAnimals(int & lower, int & upper)
{
  cout << "Enter the lower limit for Types of Animals: ";
  cin >> lower;
  cout << "Enter the upper limit for Types of Animals: ";
  cin >> upper;
}

float calculateProfit(float animalPartsUsed, float typesOfAnimals)
{
    // f(X,Y) = X * e^(-(Y^2)/X)
    // x = animalPartsUsed
    // y = typesOfAnimals
    float profit;
    float x = animalPartsUsed;
    float y = typesOfAnimals;
    float e = exp(1);
    profit = x * pow(e, (-(pow(y, 2)) / x));
    return profit;
}

void table(const int lowerAPU, const int upperAPU, const int lowerTOA, const int upperTOA)
{
  for(int x = lowerAPU; x <= upperAPU; x++)
  {
    for(int y = lowerTOA; y <= upperTOA; y++)
    {
      cout << "f(" << x << "," << y << "): ";
      cout << calculateProfit(x, y) << "\t";
    }
    cout << endl;
  }
}

void signoff()
{
  cout << "Bye bye Krusty. We will miss you." << endl;
}
