// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/02/2018
// File:         customer.cpp
// Description

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "burger.h"
#include "customer.h"
using namespace std;


short randInterval(const int lower, const int upper)
{
  return (rand() % upper) + lower;
}


ostream& operator << (ostream& os, Customer& c)
{
  // Name
  c.getName();
  // Weight
  os << " weighs " << c.getWeight() << " lbs, ";
  // Cash
  os << "has $" << c.getCash();
  // Cholesterol
  os << ", " << c.getChol() << " IBU";
  // Life Status
  os << " and is " << (c.getAlive() ? "ALIVE" : "DEAD");
  return os;
}

// Constructors

Customer::Customer()
{
  ifstream name;
  int numNames = 24;
  name.open("simpson_names.dat");
  int nameNumber = randInterval(1, numNames);
  // Pick Name
  for(int i = 1; i <= nameNumber; i++)
    name.getline(cName, MAX_NAME_LENGTH);

  // Randomize Weight
  cWeight = randInterval(MIN_WEIGHT, MAX_WEIGHT);
  // Randomize Cholestorol
  cCholesterolLevel = randInterval(MIN_CHOL, MAX_CHOL);
  // Randomize Cash
  cCash = randInterval(MIN_CASH, MAX_CASH);
  // Make Living
  cIsAlive = true;
  // Close names file
  name.close();
}

void Customer::eat(Burger burg)
{
  if(!cIsAlive)
  {
    cout << "This Customer is dead." << endl;
  }
  else if(burg.getPathogen())
  {
    cout << "R.I.P " << cName << endl;
    cIsAlive = false;
  }
  else
  {
    cCash -= burg.getPrice();
    // TODO: Increase Cholesterol by the following function:
      // chol gain = 2.5 * B + (PI/2) * P + wt/((K + 1)*10)
      //  B = Bacon
      // 	P = Patties
      // 	K = Pickles
    cCholesterolLevel += 2.5 * burg.getNumBacon()
                      + (PI / 2) * burg.getNumPatties()
                      + cWeight / ((burg.getNumPickles() + 1) * 10);
    // TODO: Increase Weight by the following function:
      // wt gain = 0.5*(P^2) + (1/8)*(B^2) - K/4 + C + S
      // C = gain attributed to cheese = 1.2
      // S = gain attributed to special sauce = 2.1
    cWeight += 0.5 * pow(burg.getNumPatties(), 2)
            + (1.0 / 8.0) * pow(burg.getNumBacon(), 2)
            - burg.getNumPickles() / 4
            + WT_FROM_CHEESE + WT_FROM_SAUCE;
  }
}

int Customer::getWeight()
{
  return cWeight;
}

short Customer::getChol()
{
  return cCholesterolLevel;
}

double Customer::getCash()
{
  return cCash;
}

bool Customer::getAlive()
{
  return cIsAlive;
}

void Customer::getName()
{
  int i = 0;
  while (cName[i] != '\0')
  {
    cout << cName[i];
    i++;
  }
}
