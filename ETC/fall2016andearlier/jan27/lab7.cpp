// lab7.cpp
// This program calculates the total cost of a meal at a restaurant.
//
// Input:  cost of a meal
// Output: total cost (after applying a 15% tip)
//
// Verify your program using the following data sets.
// Test data: cost=20.0,  tip=3.0,  total=23.0
//	      cost=13.28, tip=1.99, total=15.27
//------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  double cost, tip, total;

  cout << "Enter the cost of the meal: ";
  cin  >> cost;

  // YOUR CODE: calculate the tip (15% of the cost)
  // HINT: to find 15% of cost, multiply 0.15 by cost
 
  tip = cost * 0.15;


  // YOUR CODE: calculate the total

  total = cost + tip;

  // YOUR CODE: output the tip (include a prompt)

  cout << "The tip for the meal of " << cost << " dollars is: " << tip << endl;

  // YOUR CODE: output the total (include a prompt)

 cout << "This brings the total of the meal to: " << total << endl;


  return 0;
}
