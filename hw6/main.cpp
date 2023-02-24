// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         10/03/2018
// File:         main.cpp
// Description:  Convert number x in base n to its form in
//               base 10, where such conversion is valid.
//               Add two options to make this process eaasier
//               for the user by turning invalid combinations of
//               x and n into valid ones.

#include "header.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
  int choice;
  int num = -1;      // Representing "x"
  int base = 0;      // Representing "n"
  int numDigits;     // Number of digits in num
  int convertedNum = 4;
  // Value of num at digit 1 (1s), 2 (10s), 3 (100s), etc.
  int digitOne = -1;
  int digitTwo = -1;
  int digitThree = -1;
  int digitFour = -1;
  int digitFive = -1;
  // Using to check if num is a valid base n number.
  bool validBase = false;
  bool haveValidNum = false;
  bool haveValidBase = false;

  do
  {
    cout << "-----OPTIONS-----" << endl;
    cout << "1: Enter a non-negative Integer, x [5 digits or less]" << endl;
    cout << "2: Enter an integer base n [2 <= n < 10]" << endl;
    cout << "3: Verify x is a valid base n number" << endl;
    cout << "4: Force validation with new (smallest) base assignment" << endl;
    cout << "5: Force validation with new (random digits in) x" << endl;
    cout << "6: Convert x to base 10" << endl;
    cout << "7: Quit" << endl;
    cout << "Choose an option listed above: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
      setNum (num,
              haveValidNum, validBase,
              numDigits,
              digitOne, digitTwo,
              digitThree, digitFour, digitFive);
        break;
      case 2:
        setBase(base, haveValidBase);
        break;
      case 3:
      verifyNumBase(num, base,
                    validBase, haveValidNum, haveValidBase,
                    digitOne, digitTwo, digitThree,
                    digitFour, digitFive,
                    numDigits);
        break;
      case 4:
        forceValidBase(num, base,
                       validBase, numDigits,
                       digitOne, digitTwo, digitThree,
                       digitFour, digitFive);
        break;
      case 5:
        forceValidNum(num, base, numDigits,
                      digitOne, digitTwo, digitThree,
                      digitFour, digitFive, validBase);
        break;
      case 6:
        convertNum(num, base,
                      digitOne, digitTwo, digitThree,
                      digitFour, digitFive, numDigits,
                      validBase,
                      convertedNum);
        break;
    }
  }
  while(choice != 7);
  return 0;
}
