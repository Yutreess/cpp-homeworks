// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         10/03/2018
// File:         functions.cpp
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

// OPTION 1
void setNum(int & num,
            bool & haveValidNum, bool & validBase,
            int & numDigits,
            int & digitOne, int & digitTwo,
            int & digitThree, int & digitFour, int & digitFive)
{
  int attempts = 0;
  validBase = false;
  do
  {
    cout << "Enter a value for x: ";
    cin >> num;
    attempts++;
  }
  while (!(num >= MIN_NUM
          && num <= MAX_NUM)
          && attempts < MAX_ATTEMPTS);
  if (!(num >= MIN_NUM && num <= MAX_NUM))
  {
    haveValidNum = false;
    cout << "Invalid x Values, try again." << endl;
  }
  else
  {
    haveValidNum = true;
    if (num >= 0 && num < 10)
      numDigits = 1;
    else if (num >= 10 && num < 100)
    {
      numDigits = 2;
      digitOne = num % 10;
      digitTwo = num / 10;
    }
    else if (num >= 100 && num < 1000)
    {
      numDigits = 3;
      digitOne = num % 10;
      digitTwo = (num / 10) % 10;
      digitThree = num / 100;
    }
    else if (num >= 1000 && num < 10000)
    {
      numDigits = 4;
      digitOne = num % 10;
      digitTwo = (num / 10) % 10;
      digitThree = (num / 100) % 10;
      digitFour = num / 1000;
    }
    else if (num >= 10000 && num < 100000)
    {
      numDigits = 5;
      digitOne = num % 10;
      digitTwo = (num / 10);
      digitThree = (num / 100) % 10;
      digitFour = (num / 1000) % 10;
      digitFive = num / 10000;
    }
    cout << "x is now equal to " << num << endl;
  }
}

// OPTION 2
void setBase(int & base, bool & haveValidBase)
{
  int attempts = 0;
  do
  {
    cout << "Enter a value n: ";
    cin >> base;
    attempts++;
  }
  while (!(base >= MIN_BASE
           && base <= MAX_BASE)
           && attempts < MAX_ATTEMPTS);
  if (!(base >= MIN_BASE && base <= MAX_BASE))
  {
    haveValidBase = false;
    cout << "Invalid n values, try again." << endl;
  }
  else				// gotten good base input
  {
    haveValidBase = true;
    cout << "n is now equal to " << base << endl;
  }
}

// OPTION 3
void verifyNumBase(int num, int base,
                   bool & validBase, bool haveValidNum, bool haveValidBase,
                   int digitOne, int digitTwo, int digitThree,
                   int digitFour, int digitFive,
                   int numDigits)
{
  // Verify x is a valid number of base n by
  // Checking n to all digits of x
  if (haveValidNum && haveValidBase)
  {
    switch (numDigits)
    {
      case 1:
      validBase = false;
        if (base > num)
        {
          validBase = true;
          cout << "The number " << num;
          cout << " is a valid number of base " << base << endl;
        }
        else
        {
          validBase = false;
          cout << "The number " << num;
          cout << " is NOT a valid number of base " << base << endl;
        }
        break;
      case 2:
        if (base > digitOne
            && base > digitTwo)
        {
          validBase = true;
          cout << "The number " << num;
          cout << " is a valid number of base " << base << endl;
        }
        else
        {
          validBase = false;
          cout << "The number " << num;
          cout << " is NOT a valid number of base " << base << endl;
        }
        break;
      case 3:
        if (base > digitOne
            && base > digitTwo
            && base > digitThree)
        {
          validBase = true;
          cout << "The number " << num;
          cout << " is a valid number of base " << base << endl;
        }
        else
        {
          validBase = false;
          cout << "The number " << num;
          cout << " is NOT a valid number of base " << base << endl;
        }
        break;
      case 4:
        if (base > digitOne
            && base > digitTwo
            && base > digitThree
            && base > digitFour)
        {
          validBase = true;
          cout << "The number " << num;
          cout << " is a valid number of base " << base << endl;
        }
        else
        {
          validBase = false;
          cout << "The number " << num;
          cout << " is NOT a valid number of base " << base << endl;
        }
        break;
      case 5:
        if (base > digitOne
            && base > digitTwo
            && base > digitThree
            && base > digitFour
            && base > digitFive)
        {
          validBase = true;
          cout << "The number " << num;
          cout << " is a valid number of base " << base << endl;
        }
        else
        {
          validBase = false;
          cout << "The number " << num;
          cout << " is NOT a valid number of base " << base << endl;
        }
        break;
      }
    }
  else
  {
    cout << "You have not done options 1 and 2 ";
    cout << "to assign" << endl;
    cout << "values to x and n. ";
    cout << "to do option 3, please do so." << endl;
  }
}

// OPTION 4
void forceValidBase(int num, int & base,
                    bool & validBase, int numDigits,
                    int digitOne, int digitTwo, int digitThree,
                    int digitFour, int digitFive)
{
  // Only executes if num (x) and base (n) are invalid.
  if(!(validBase))
  {
    switch (numDigits)
    {
      case 1:
        base = num + 1;
        validBase = true;
        break;
      case 2:
        while (base <= digitOne
               || base <= digitTwo)
        {
          base += 1;
        }
        validBase = true;
        break;
      case 3:
        while (base <= digitOne
               || base <= digitTwo
               || base <= digitThree)
        {
          base += 1;
        }
        validBase = true;
        break;
      case 4:
        while (base <= digitOne
               || base <= digitTwo
               || base <= digitThree
               || base <= digitFour)
        {
          base += 1;
        }
        validBase = true;
        break;
      case 5:
        while (base <= digitOne
               || base <= digitTwo
               || base <= digitThree
               || base <= digitFour
               || base <= digitFive)
        {
          base += 1;
        }
        validBase = true;
        break;
      }
      cout << "n is now equal to " << base << "." << endl;
    }
    else
    {
      cout << "Invalid Option: x is a valid number of base n." << endl;
      cout << "This option may only be used when x";
      cout << " is NOT a valid number of base n." << endl;
    }
}
// OPTION 5
void forceValidNum(int & num, int base, int numDigits,
                   int & digitOne, int & digitTwo, int & digitThree,
                   int & digitFour, int & digitFive, bool & validBase)
{
  // Only executes if num (x) and base (n) are invalid.
  if(!(validBase))
  {
    // Initialize seed for random number generation
    srand(7);
    switch(numDigits)
    {
      case 1:
        if(base <= num)
        {
          do
          {
            num = rand() % base;
          }
          while(num <= 0
                || num >= base);
        }
        break;
      case 2:
        if (base <= digitOne)
        {
          num -= digitOne;
          do
          {
            digitOne = (rand() % 10);
          }
          while(digitOne <= 0
                || digitOne >= base);
          num += digitOne;
        }
        if(base <= digitTwo)
        {
          num -= digitTwo * 10;
          do
          {
            digitTwo = (rand() % 10);
          }
          while(digitTwo <= 0
                || digitTwo >= base);
          num += digitTwo * 10;
        }
        break;
      case 3:
        if (base <= digitOne)
        {
          num -= digitOne;
          do
          {
            digitOne = (rand() % 10);
          }
          while(digitOne <= 0
                || digitOne >= base);
          num += digitOne;
        }
        if(base <= digitTwo)
        {
          num -= digitTwo * 10;
          do
          {
            digitTwo = (rand() % 10);
          }
          while(digitTwo <= 0
                || digitTwo >= base);
          num += digitTwo * 10;
        }
        if(base <= digitThree)
        {
          num -= digitThree * 100;
          do
          {
            digitThree = (rand() % 10);
          }
          while(digitThree <= 0
                || digitThree >= base);
          num += digitThree * 100;
        }
        break;
      case 4:
        if (base <= digitOne)
        {
          num -= digitOne;
          do
          {
            digitOne = (rand() % 10);
          }
          while(digitOne <= 0
                || digitOne >= base);
          num += digitOne;
        }
        if(base <= digitTwo)
        {
          num -= digitTwo * 10;
          do
          {
            digitTwo = (rand() % 10);
          }
          while(digitTwo <= 0
                || digitTwo >= base);
          num += digitTwo * 10;
        }
        if(base <= digitThree)
        {
          num -= digitThree * 100;
          do
          {
            digitThree = (rand() % 10);
          }
          while(digitThree <= 0
                || digitThree >= base);
          num += digitThree * 100;
        }
        if(base <= digitFour)
        {
          num -= digitFour * 1000;
          do
          {
            digitFour = (rand() % 10);
          }
          while(digitFour <= 0
                || digitFour >= base);
          num += digitFour * 1000;
        }
        break;
      case 5:
        if (base <= digitOne)
        {
          num -= digitOne;
          do
          {
            digitOne = (rand() % 10);
          }
          while(digitOne <= 0
                || digitOne >= base);
          num += digitOne;
        }
        if(base <= digitTwo)
        {
          num -= digitTwo * 10;
          do
          {
            digitTwo = (rand() % 10);
          }
          while(digitTwo <= 0
                || digitTwo >= base);
          num += digitTwo * 10;
        }
        if(base <= digitThree)
        {
          num -= digitThree * 100;
          do
          {
            digitThree = (rand() % 10);
          }
          while(digitThree <= 0
                || digitThree >= base);
          num += digitThree * 100;
        }
        if(base <= digitFour)
        {
          num -= digitFour * 1000;
          do
          {
            digitFour = (rand() % 10);
          }
          while(digitFour <= 0
                || digitFour >= base);
          num += digitFour * 1000;
        }
        if(base <= digitFive)
        {
          num -= digitFive * 10000;
          do
          {
            digitFive = (rand() % 10);
          }
          while(digitFive <= 0
                || digitFive >= base);
          num += digitFive * 10000;
        }
        break;
    }
    validBase = true;
    cout << "num is now set to " << num << endl;
  }
  else
  {
    cout << "Invalid Option: x is a valid number of base n." << endl;
    cout << "This option may only be used when x";
    cout << " is NOT a valid number of base n." << endl;
  }
}


// OPTION 6
void convertNum(int num, int base,
                int digitOne, int digitTwo, int digitThree,
                int digitFour, int digitFive, int numDigits,
                bool validBase,
                int & convertedNum)
{
  if (!(validBase))
  {
    cout << "Invalid Option." << endl;
    cout << "x and n are not compatible vales." << endl;
    cout << "Please repeat options 1 and 2";
    cout << " with verfied compatability with option 3." << endl;
  }
  else
  {
    switch (numDigits)
    {
      case 1:
        convertedNum = num;
        break;
      case 2:
        convertedNum = (digitTwo * pow(base, 1))
                        + (digitOne * pow(base, 0));
        break;
      case 3:
        convertedNum = (digitThree * pow(base , 2))
                       + (digitTwo * pow(base , 1))
                       + (digitOne * pow(base, 0));
        break;
      case 4:
      convertedNum = (digitFour * pow(base, 3))
                     + (digitThree * pow(base, 2))
                     + (digitTwo * pow(base, 1))
                     + (digitOne * pow(base, 0));
        break;
      case 5:
      convertedNum = (digitFive * pow(base, 4))
                     + (digitFour * pow(base, 3))
                     + (digitThree * pow(base, 2))
                     + (digitTwo * pow(base, 1))
                     + (digitOne * pow(base, 0));
        break;
    }
    cout << num << " expressed in base 10 is " << convertedNum << endl;
  }
}
