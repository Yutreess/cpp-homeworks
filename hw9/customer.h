// Programmer:   Justus Peterson-Rhodes
// Student ID:   jepfn5
// Section:      A
// Date:         11/02/2018
// File:         customer.h
// Description:

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

// Constants

const double PI = 3.14;
// Name Length
const int MAX_NAME_LENGTH = 30;
// Cholestorol Levels
const int MIN_CHOL = 30;
const int MAX_CHOL = 300;
// Initial Weight
const int MIN_WEIGHT = 90;
const int MAX_WEIGHT = 250;
// Weight Gain
const double WT_FROM_CHEESE = 1.2;
const double WT_FROM_SAUCE  = 2.1;
// Cash
const double MIN_CASH = 25.0;
const double MAX_CASH = 75.0;

// Burger Class

class Customer
{
  public:
    // Constructors
    Customer();
    void eat(Burger burg);
    int getWeight();
    short getChol();
    double getCash();
    bool getAlive();
    void getName();
  private:
    int cWeight;
    short cCholesterolLevel;
    double cCash;
    bool cIsAlive;
    char cName[MAX_NAME_LENGTH];
};

// Non-member Functions
ostream& operator << (ostream& os, Customer& c);

#endif
