// Programmer:	 Justus Peterson-Rhodes
// Student ID:	 jepfn5
// Section:      A
// Date:	 09/08/2018
// Filoe:	 burgerNamer.cpp
// Description:  Take a 3 digit code input from the user. Using this
//		 code, give the burger a name and price based on the digits.


#include <iostream>
using namespace std;

int main()
{ 
  int burgerCode;
  string burgerName = "";
  float burgerPrice;
  const string DEFAULT = "Krusty";
  const string BURGER  = "Burger";
  // Burger Ingredients to be extracted from burgerCode
  int ozOfBacon;
  int ozOfPickles;
  int numPatties;  
  // Burger ingreedient costs
  const float PICKLE_PRICE = 0.25;
  const float PATTY_PRICE  = 0.75;
  const float BACON_PRICE  = 0.50;
  const float BUN_PRICE    = 0.50;
  // Name per # of Patties
  const string SINGLE = "Single";
  const string DOUBLE = "Double";
  const string TRIPLE = "Triumph";
  // Name per Ounces of Bacon
  const string ZERO_BACON  = "Health Master";
  const string ONE_BACON   = "Bacon";
  const string TWO_BACON   = "Wilbur";
  const string THREE_BACON = "Klogger";
  // Name per Ounces of Pickles
  const string ZERO_PICKLE  = "Tasteless";
  const string ONE_PICKLE   = "Pickly";
  const string TWO_PICKLE   = "Garden-Fresh";
  const string THREE_PICKLE = "Kermit";
  // Special Case Burger names & Space Insert
  const string SIX_MEAT_SHORT_PICKLE = "Koronary";
  const string MORE_PICKLE_LESS_MEAT = "Veggie";
  const string SP		     = " ";
  // Force prices tp be listed in 2 decimal places
  cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); 
  cout.precision(2);
  // Begin User Prompt
  cout << "-----BURGER GENERATOR-----" << endl;
  do 
  {
    burgerName = "";
    burgerPrice = 0.00;
    cout << "Please type a 3 Digit Code to"; 
    cout << " generate your burger and name" << endl;
    cin >> burgerCode;
    numPatties	  = burgerCode / 100;       // 100s place of Burger Code 
    ozOfBacon	  = (burgerCode / 10) % 10; // 10s place of Burger Code
    ozOfPickles   = burgerCode % 10;        // 1s place of Burger Code
    // Check Code Validity
    if ((numPatties > 0 && numPatties < 4)
         && (ozOfBacon >= 0 && ozOfBacon < 4) 
        && (ozOfPickles >= 0 && ozOfPickles < 4))
    {
      // Special Cases    
      if (ozOfPickles >= (ozOfBacon + numPatties))
      {
        burgerName = DEFAULT
                     + SP + MORE_PICKLE_LESS_MEAT
                     + SP + BURGER;
        burgerPrice = BUN_PRICE
                      + (numPatties * PATTY_PRICE)
                      + (ozOfBacon * BACON_PRICE)
                      + (ozOfPickles * PICKLE_PRICE);
        cout << "The " << burgerName;
        cout << " will be sold at $" << burgerPrice << endl;
        burgerName = "";
        burgerPrice = 0.00;
      }
      else if ((ozOfBacon + numPatties)== 6
          && ozOfPickles < 2)
      {
        burgerName = DEFAULT 
                     + SP + SIX_MEAT_SHORT_PICKLE
                     + SP + BURGER;
        burgerPrice = BUN_PRICE
                      + (numPatties * PATTY_PRICE)
                      + (ozOfBacon * BACON_PRICE)
                      + (ozOfPickles * PICKLE_PRICE);
        cout << "The " << burgerName;
        cout << " will be sold at $" << burgerPrice << endl;
        burgerName = "";
        burgerPrice = 0.00;
      }
      // Default Pricing & Naming
      else
      {
        
        // Name in respect to Patties
        if (numPatties == 1)
          burgerName += DEFAULT + SP + SINGLE;
        if (numPatties == 2)
          burgerName += DEFAULT + SP + DOUBLE;
        if (numPatties == 3)
          burgerName += DEFAULT + SP + TRIPLE;
        // Name in respect to Bacon
        if (ozOfBacon == 0)
          burgerName += SP + ZERO_BACON;
        if (ozOfBacon == 1)
          burgerName += SP + ONE_BACON;
        if (ozOfBacon == 2)
          burgerName += SP + TWO_BACON;
        if (ozOfBacon == 3)
          burgerName += SP + THREE_BACON;
        // Name in respect to Pickles
        if (ozOfPickles == 0)
          burgerName += SP + ZERO_PICKLE
                        + SP + BURGER;
        if (ozOfPickles == 1)
          burgerName += SP + ONE_PICKLE
                        + SP + BURGER;
        if (ozOfPickles == 2)
          burgerName += SP + TWO_PICKLE
                        + SP + BURGER;
        if (ozOfPickles == 3)
          burgerName += SP + THREE_PICKLE
                        + SP + BURGER;
        // Naming Ends. Set Burger's Price
        burgerPrice = BUN_PRICE
                      + (numPatties * PATTY_PRICE)
                      + (ozOfBacon * BACON_PRICE)
                      + (ozOfPickles * PICKLE_PRICE);
        cout << "The " << burgerName;
        cout << " will be sold at $" << burgerPrice << endl;
        burgerName = "";
        burgerPrice = 0.00;
      }
    } 
    else
      cout << "Invalid Code." << endl;
  } 
  while (burgerCode != 0);
  return 0; 
}
