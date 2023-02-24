// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         10/03/2018
// File:         header.h
// Description:  Convert number x in base n to its form in
//               base 10, where such conversion is valid.
//               Add two options to make this process eaasier
//               for the user by turning invalid combinations of
//               x and n into valid ones.

#ifndef HEADER_H
#define HEADER_H

using namespace std;

// GLOBAL CONSTANTS
// Minimum and Maximum values permitted for num
const int MIN_NUM = 0;
const int MAX_NUM = 99999;
// Minimum and Maximum values for base
const int MIN_BASE = 2;
const int MAX_BASE = 9;
const int MAX_ATTEMPTS = 3;

// PROTOTYPES

  // OPTION 1
// Description:  Prompts the user for a value of num (x)
// Precondition: None
// Postcondition:num is assigned a value if it's valid, and
//               have_valid_num is assigned true or false respectively.
//               Otherwise, have_valid_num is assigned false and
//               num is NOT assigned a value.
void setNum(int & num,
            bool & haveValidNum, bool & validBase,
            int & numDigits,
            int & digitOne, int & digitTwo,
            int & digitThree, int & digitFour, int & digitFive);

  // OPTION 2
// Description:  Prompts the user for a value of base (n)
// Precondition: None
// Postcondition:base is assigned a value if it's valid, and
//               have_valid_base is assigned true or false respectively.
//               Otherwise, have_valid_base is assigned false and
//               base is NOT assigned a value.
void setBase(int & base, bool & haveValidBase);

  // OPTION 3
// Description:  Verify if num (x) is a valid base number of base (n)
// Precondition: base and num are valid.
// Postcondition:validBase is assigned true or false respectively
//               and the menu is reprinted to the console.
void verifyNumBase(int num, int base,
                   bool & validBase, bool haveValidNum, bool haveValidBase,
                   int digitOne, int digitTwo, int digitThree,
                   int digitFour, int digitFive,
                   int numDigits);

  // OPTION 4
// Description:  This forces base (n) and num (x) to be valid via changing
//               base (n) to fit num (x)
// Precondition: base (n) is not valid for num (x).
// Postcondition:base (n) is assigned the smallest possible value
//               that validates num (x) of base (n)
void forceValidBase(int num, int & base,
                    bool & validBase, int numDigits,
                    int digitOne, int digitTwo, int digitThree,
                    int digitFour, int digitFive);

  // OPTION 5
// Description:  This forces base (n) and num (x) to be valid via changing
//               num (x) to fit base (n)
// Precondition: base (n) is not valid for num (x).
// Postcondition:num (x) is assigned a different value that
//               makes base (n) and num (x) valid.
void forceValidNum(int & num, int base, int numDigits,
                   int & digitOne, int & digitTwo, int & digitThree,
                   int & digitFour, int & digitFive, bool & validBase);

  // OPTION 6
// Description:  Convert num (x) to base 10
// Precondition: num and base are veriied to be valid,
// Postcondition:num (x) is converted to base 10 and printed to the console.
void convertNum(int num, int base,
                int digitOne, int digitTwo, int digitThree,
                int digitFour, int digitFive, int numDigits,
                bool validBase,
                int & convertedNum);
#endif
