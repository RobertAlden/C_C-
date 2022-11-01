// lab8.cpp
// This program outputs the age of a person in months, days, or hours.
// Assume that a year is always 365 days.
//
// Input:  age (in years)
// Output: age in months, age in days, age in hours
//
// Verify your program using the following data sets.
// Test data: age=1,  months=12,  days=365,  hours=8760
//	      age=20, months=240, days=7300, hours=175200
//---------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int age, months, days, hours;

  cout << "Enter your age: ";
  cin  >> age;

  // YOUR CODE: calculate months from age

 months = age * 12;


  // YOUR CODE: calculate days from age

 days = age * 365;


  // YOUR CODE: calculate hours from days

 hours = days * 24;


  // YOUR CODE: output age, months, days, and hours

  cout << "Your age in various metrics is: " << endl;
  cout << "Years: " << age << ", Months: " << months << endl;
  cout << "Hours: " << hours << endl;
 

  return 0;
}
