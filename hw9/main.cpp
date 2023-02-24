// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/02/2018
// File:         main.cpp
// Description:

#include <string>
#include <iostream>
#include <cstdlib>
#include "burger.h"
#include "customer.h"
using namespace std;

int main()
{
  srand(time(0));
  Burger burgOne(2, 3, 1, true, true, false);
  Burger burgTwo, burgThree, burgFour;
  //Customer custOne, custTwo, custThree;
  Customer contestants[15];
  for(int i = 0; i < 15; i++)
    cout << contestants[i] << endl;

  // Force prices tp be listed in 2 decimal places
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
/*
  // Print Burgers
  cout << "-----Burger 1-----" << endl;
  cout << burgOne << endl;
  cout << "-----Burger 2-----" << endl;
  cout << burgTwo << endl;
  cout << "-----Burger 3-----" << endl;
  cout << burgThree << endl;
  cout << "-----Burger 4-----" << endl;
  cout << burgFour << endl;

  cout << "---------------" << endl;
  // Print Customer Info
  cout << custOne << endl;
  cout << custTwo << endl;
  cout << custThree << endl;


  // Custoemr 1 Eating the 4 Burgers
  cout << "-----Customer 1-----" << endl;
  custOne.eat(burgOne);
  cout << custOne << endl;
  custOne.eat(burgTwo);
  cout << custOne << endl;
  custOne.eat(burgThree);
  cout << custOne << endl;
  custOne.eat(burgFour);
  cout << custOne << endl;

  // Custoemr 2 Eating the 4 Burgers
  cout << "-----Customer 2-----" << endl;
  custTwo.eat(burgOne);
  cout << custTwo << endl;
  custTwo.eat(burgTwo);
  cout << custTwo << endl;
  custTwo.eat(burgThree);
  cout << custTwo << endl;
  custTwo.eat(burgFour);
  cout << custTwo << endl;

  // Custoemr 3 Eating the 4 Burgers
  cout << "-----Customer 3-----" << endl;
  custThree.eat(burgOne);
  cout << custThree << endl;
  custThree.eat(burgTwo);
  cout << custThree << endl;
  custThree.eat(burgThree);
  cout << custThree << endl;
  custThree.eat(burgFour);
  cout << custThree << endl;
*/
  return 0;
}
