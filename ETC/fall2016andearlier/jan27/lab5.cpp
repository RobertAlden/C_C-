// lab5.cpp
// This program calculates miles per gallon efficiency of a vehicle.
//
// Input:  miles traveled, gallons used
// Output: miles per gallon
//
// You can test your program by using the following data at run time.
// miles = 90, gallons = 3.5
// mpg   = 25.7 
//--------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  double miles, gallons, mpg;

  cout << "Enter miles traveled: ";
  cin  >> miles;

  cout << "Enter gallons used: ";
  cin  >> gallons;

  // YOUR CODE: calculate the miles per gallon.
  // Write the formula to calculate the mpg.

	mpg = miles / gallons;



  // YOUR CODE: output the value of mpg with a cout statement.

	cout << "MPG IS: " << mpg << endl;

  return 0;
}
