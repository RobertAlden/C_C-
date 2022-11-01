// lab6.cpp
// This program calculates the total amount of sales tax on a purchase.
//
// Input:  cost, tax rate (both in decimal)
// Output: sales tax amount
//
// Complete the program and test it using the following data sets.
// cost=30,  rate=0.10,  tax=3
// cost=12,  rate=0.085, tax=1.02
//---------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  double cost, taxrate, taxamount;

  cout << "Enter the cost of your item: ";
  cin  >> cost;

  // YOUR CODE: input the taxrate.
  // HINT: use a cout stmt to display a prompt.
  //       use a cin  stmt to input the taxrate.

  cout << "Input taxrate: ";
  cin >> taxrate;

  // YOUR CODE: calculate the taxamount.

  taxamount = cost * taxrate;

  // YOUR CODE: output the taxamount (make sure to include a prompt).

 cout << "Cost of sales tax at rate of " << taxrate * 100 << " percent is: " << taxamount << endl;

  return 0;
}
