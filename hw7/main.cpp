// Programmer: Justus Peterson-Rhodes
// Student ID: jepfn5
// Section:    A
// Date:       10/15/2018
// File:       main.cpp
// Description:Manipulate a list of burgers
//             by randomly generating burgers,
//             presenting the list of burgers,
//             and removing burgers

#include "header.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int menuChoice;
  Burger burgers[SIZE];
  int dataSet = 0;
  // Force prices tp be listed in 2 decimal places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  do
  {
    cout << "1: Generate New Burger" << endl;
    cout << "2: Display Burger List" << endl;
    cout << "3: Remove Burgers" << endl;
    cout << "[Enter 4 to quit]" << endl;
    cout << "Select an option: ";
    cin >> menuChoice;
    cout << endl;
    switch (menuChoice)
    {
      case 1:
        generateBurger(burgers, dataSet);
        break;
      case 2:
        sortBurgers(burgers, dataSet);
        printBurgerList(burgers, dataSet);
        break;
      case 3:
        removeBurger(burgers, dataSet);
        break;
    }
  }
  while(menuChoice != 4);
  return 0;
}
