// Programmer:	Justus Peterson-Rhodes
// Student ID:	jepfn5
// Section:	A
// Date: 	09/14/2018
// File:	krustyMath.cpp
// Description: Convert number x in base n to its form in
//              base 10, where such conversion is valid.
//
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Minimum and Maximum values permitted for num
  const int MIN_NUM = 0;
  const int MAX_NUM = 99999;
  // Minimum and Maximum values for base
  const int MIN_BASE = 2;
  const int MAX_BASE = 9;
  const int MAX_ATTEMPTS = 3;

  int option;
  int num = -1;      // Representing "x"
  int base = 0;      // Representing "n"
  int numDigits;     // Number of digits in num
  int convertedNum = 4;
  // Value of num at digit 1 (1s), 2 (10s), 3 (100s), etc.
  int ones;
  int tens;
  int hundreds;
  int thousands;
  int tenThousands;
  // Using to check if num is a valid base n number.
  bool validBase = false;
  bool have_valid_num = false;
  bool have_valid_base = false;
  // Loop Controls for variable assigning attempts
  int attempts = 0;

  do
  {
    cout << "-----OPTIONS-----" << endl;
    cout << "1: Enter a non-negative Integer, x [5 digits or less]" << endl;
    cout << "2: Enter an integer base n [2 <= n < 10]" << endl;
    cout << "3: Verify x is a valid base n number" << endl;
    cout << "4: Convert x to base 10" << endl;
    cout << "5: Quit" << endl;
    cin >> option;
    attempts = 0;			// reset attempt counter
    switch (option)
    {
      case 1:
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
          have_valid_num = false;
          cout << "Invalid x Values, try again." << endl;
        }
        else
        {
          have_valid_num = true;
          if (num >= 0 && num < 10)
            numDigits = 1;
          else if (num >= 10 && num < 100)
            numDigits = 2;
          else if (num >= 100 && num < 1000)
            numDigits = 3;
          else if (num >= 1000 && num < 10000)
            numDigits = 4;
          else if (num >= 10000 && num < 100000)
            numDigits = 5;
          cout << "x is now equal to " << num << endl;
        }
        break;

      case 2:
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
          have_valid_base = false;
          cout << "Invalid n values, try again." << endl;
        }
        else				// gotten good base input
        {
          have_valid_base = true;
          cout << "n is now equal to " << base << endl;
        }
        break;

      case 3:
        // Verify x is a valid number of base n by
        // Checking n to all digits of x
        if (have_valid_num && have_valid_base)
        {
          switch (numDigits)
          {
            case 1:
              if (base > num)
              {
                validBase = true;
                cout << "The number " << num;
                cout << " is a valid number of base " << base << endl;
              }
              else
              {
                cout << "The number " << num;
                cout << " is NOT a valid number of base " << base << endl;
              }
              break;
  	        case 2:
              ones = num % 10;
              tens = num / 10;
              if (base > ones
                  && base > tens)
              {
                validBase = true;
                cout << "The number " << num;
                cout << " is a valid number of base " << base << endl;
              }
              else
              {
                cout << "The number " << num;
                cout << " is NOT a valid number of base " << base << endl;
              }
              break;
            case 3:
              ones = num % 10;
              tens = (num / 10) % 10;
              hundreds = num / 100;
              if (base > ones
                  && base > tens
                  && base > hundreds)
              {
                validBase = true;
                cout << "The number " << num;
                cout << " is a valid number of base " << base << endl;
              }
              else
              {
                cout << "The number " << num;
                cout << " is NOT a valid number of base " << base << endl;
              }
              break;
            case 4:
              ones = num % 10;
              tens = (num / 10) % 10;
              hundreds = (num / 100) % 10;
              thousands = num / 1000;
              if (base > ones
                  && base > tens
                  && base > hundreds
                  && base > thousands)
              {
                validBase = true;
                cout << "The number " << num;
                cout << " is a valid number of base " << base << endl;
              }
              else
              {
                cout << "The number " << num;
                cout << " is NOT a valid number of base " << base << endl;
              }
              break;
            case 5:
              ones = num % 10;
              tens = (num / 10);
              hundreds = (num / 100) % 10;
              thousands = (num / 1000) % 10;
              tenThousands = num / 10000;
              if (base > ones
                  && base > tens
                  && base > hundreds
                  && base > thousands
                  && base > tenThousands)
              {
                validBase = true;
                cout << "The number " << num;
                cout << " is a valid number of base " << base << endl;
              }
              else
              {
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
        break;

      case 4:
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
              convertedNum = (tens * pow(base, 1))
                              + (ones * pow(base, 0));
              break;
            case 3:
              convertedNum = (hundreds * pow(base , 2))
                             + (tens * pow(base , 1))
                             + (ones * pow(base, 0));
              break;
            case 4:
            convertedNum = (thousands * pow(base, 3))
                           + (hundreds * pow(base, 2))
                           + (tens * pow(base, 1))
                           + (ones * pow(base, 0));
              break;
            case 5:
            convertedNum = (tenThousands * pow(base, 4))
                           + (thousands * pow(base, 3))
                           + (hundreds * pow(base, 2))
                           + (tens * pow(base, 1))
                           + (ones * pow(base, 0));
              break;
          }
          cout << num << " expressed in base 10 is " << convertedNum << endl;
        }
        break;
    }
  }
  while (option != 5);
  cout << "Goodbye." << endl;
  return 0;
}
