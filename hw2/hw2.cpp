// Programmer: Justus Peterson-Rhodes
// Student ID: jepfn5 | 12546808
// Date:       09/01/2018
// File:       hw2.cpp
// Description: Calculate the chance of heart attack for
//		a customer based on a certain diet of food items.
//		Using that information, determine how many miles & marathons
//		the customer should run to reduce this risk.

// Including I/O Library
#include <iostream>
using namespace std;

int main()
{
  // Constant  Declarations
  const float AIR_QUALITY = 5.6;
  const float KB_MIT_FACTOR = 19.7;
  // Input and Output Variable Declarations
  int numOfFries;
  int numOfBurgers;
  int numOfMilkshakes;
  int lengthInQueue;
  float chanceOfHeartAttack;
  float milesToRun;
  bool oneEach;
  // User Greeting
  cout << "Welcome to Krusty Burger!" << endl;
  // User Prompts for Variable Assignment
  cout << "How many orders of the following foods have you eaten?" << endl;
  cout << "Burgers: ";
  cin >> numOfBurgers;
  cout << "Fries: ";
  cin >> numOfFries;
  cout << "Milkshakes: ";
  cin >> numOfMilkshakes;
  cout << "Ammount of people in line ahead: ";
  cin >> lengthInQueue;
  oneEach = numOfFries && numOfBurgers && numOfMilkshakes;
  // End of User Prompts
  // Assign Chance of Heart Attack
  chanceOfHeartAttack = (numOfBurgers + numOfFries)
  * (static_cast<float>(numOfMilkshakes) / (lengthInQueue + 1))
  + (oneEach * AIR_QUALITY);
  // Output for the chance of heart attack
  cout << "This gives you a " << chanceOfHeartAttack;
  cout << "% chance of a heart attack. " << endl;
  milesToRun = chanceOfHeartAttack * KB_MIT_FACTOR;
  cout << "It's recommended you run " << static_cast<int>(milesToRun / 26);
  cout << " marathons and ";
  // Take the total miles needed to run, and take away the amount of marathons times 26.
  cout << (milesToRun - ((static_cast<int>(milesToRun / 26)) * 26));
  cout << " more miles!" << endl;
  return 0;
}
