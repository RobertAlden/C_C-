// lab118.cpp
// Write the coding of two conversion functions for speed.
//
// The 1st function converts knots to miles-per-hour(mph).
// Knots is a nautical mile which is used by air and sea navigators.
//
// The 2nd function converts mph to kilometers-per-hour(kph).
//
// The main program is already written for you.
// The main program inputs a nautical mile and outputs it in mph and kph.
//
// Run and test the program using the following data:
// knots   mph    kph
// -----------------------
//  10	   11.5   18.515
// 500	  575    925.75
//-----------------------------------------------------------------------

#include <iostream>
using namespace std;

// function prototypes

double knots_to_mph(double knots);
// Converts the speed from knots to miles-per-hour.

double mph_to_kph(double mph);
// Converts the speed from mph to kilometers-per-hour.

//-----------------------------------------------------------------

int main()
{
  double knots, mph, kph;

  cout << "Enter the speed in knots: ";
  cin  >> knots;

  mph = knots_to_mph(knots);	// Convert knots to mph

  kph = mph_to_kph(mph);	// Convert mph to kph

  cout << endl;
  cout << "Speed in MPH = " << mph << endl;
  cout << "Speed in KPH = " << kph << endl;

  return 0;
}
//-----------------------------------------------------------------

// YOUR CODE: Write the complete coding of the function knots_to_mph.
// Formula: knot = 1.15 mph




//-----------------------------------------------------------------

// YOUR CODE: Write the complete coding of the function mph_to_kph.
// Formula: mph = 1.61 kph





//-----------------------------------------------------------------
