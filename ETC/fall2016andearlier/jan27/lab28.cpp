// lab28.cpp
// The retirement eligibility under Oklahoma Teachers Retirement System:
// age + (service years) should be 90 or above
//
// This program determines if a teacher is eligible to retire.
//
// input:  birthYear, startYear
// calc:   age, serviceYears
// output: "ELIGIBLE" or "NOT ELIGIBLE"
//
// Complete the program and test it using the following data.
// birthYear	startYear	Output
// 1975		2005		NOT ELIGIBLE
// 1950		1988		ELIGIBLE
//
// NOTE: startYear is the year a person started to teach.
//--------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int birthYear, startYear;	// inputs
  int age, serviceYears;	// calculated age and years of service

  cout << "Enter the birth year: ";
  cin  >> birthYear;

  // YOUR CODE: input the startYear (the year they started teaching)
  cout << "Enter your starting year:";
  cin >> startYear;


  // YOUR CODE: calculate age (based on 2016)

  age = 2016 - birthYear;

  // YOUR CODE: calculate serviceYears (based on 2016)
  serviceYears = 2016 - startYear;


  // YOUR CODE: output the proper eligibility message
  if (age + serviceYears > 90)
{
 cout << "ELEGIBLE" << endl;
}
 else cout << "NOT ELEGIBLE" << endl;
 return(0);
}




 


