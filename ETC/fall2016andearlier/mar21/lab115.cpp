// lab115.cpp
// This file contains a modified version of lab114.
// This program will calculate the length of the hypotenuse of a
// right triangle. Hypotenuse is the longest side.
//
// Assume that a, b are two of the sides and c is the hypotenuse.
// Complete the main program.
//
// Run and verify your program using the following data:
// If a = 3,  b = 4, then c = 5
// If a = 7,  b = 8, then c = 10.6301
// If a = 12, b =16, then c = 20 
//----------------------------------------------------------------

#include <iostream>
#include <cmath>	// for sqrt()
using namespace std;

// function prototype
double square(double num);
//----------------------------------------------------------------

int main()
{
  double a, b;
  double c;

  // YOUR CODE: input sides a and b of a right triangle



  // YOUR CODE: compute the hypotenuse c.
  // Implement the following formula:
  // c = square root of(square of a + square of b)
  // Make sure to use the functions sqrt and square




  // YOUR CODE: output c



  return 0;
}
//----------------------------------------------------------------

double square(double num)
{
  return num * num;
}
//----------------------------------------------------------------

