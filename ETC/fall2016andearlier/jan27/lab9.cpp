// lab9.cpp
// Extending lab8.
// This program calculates the age of a person in months, days, hours, minutes.
// Assume that a year is always 365 days.
//
// Input:  age (in years)
// Output: months, days, hours, minutes
//
// Test data: age=1,  months=12,  days=365,  hours=8760,  minutes=525600
//	      age=20, months=240, days=7300, hours=175200,minutes=10512000
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int age, months, days, hours, minutes;

  cout << "Enter your age: ";
  cin  >> age;

  // calculate the months from age (your code)
  months = age * 12;


  // calculate the days from age (your code)

 days = age * 365;

  // calculate the hours from days (your code)

 hours = days * 24;

  // calculate the minutes from hours (your code)
 minutes = hours * 60;

  // output all data (ADD ANY MISSING CODE)
  cout << "Your age in years = " << age    << endl;
  cout << "Your age in months= " << months << endl;
  cout << "Your age in days  = " << days   << endl;
  cout << "Your age in min.  = " << minutes << endl; 



  return 0;
}
