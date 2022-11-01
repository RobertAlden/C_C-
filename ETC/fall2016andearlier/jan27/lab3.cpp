// lab3.cpp
// Purpose:
//	A Simple Calculator
//	This program inputs 2 integers and displays their sum, difference,
//	product, quotient and modulus (remainder).
// Instructions:
//	Add your code where requested. Compile, run and verify.
//-------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int num1, num2;	// two integers

  // These variables will hold the result of each operation.
  int sum, difference, product, ratio, remainder;

  cout << "Enter the 1st integer: ";
  cin  >> num1;

  cout << "Enter the 2nd integer: ";
  cin  >> num2;

  // YOUR CODE: Write a stmt that calculates the sum of num1 and num2.
  // HINT: sum = _______;
  sum = num1 + num2;


  // YOUR CODE: Calculate the difference of num1 and num2.
  // HINT: difference = ______;

  difference = num1 - num2; 

  // YOUR CODE: Calculate the product of num1 and num2.

  product = num1 * num2; 

  // YOUR CODE: Calculate the ratio of num1 divided by num2.

  ratio = num1 / num2;

  // YOUR CODE: Calculate the remainder of dividing num1 by num2.
  // You need to use the % operator.

  remainder = num1 % num2;

  // Output section - DO NOT MODIFY THIS SECTION
  cout << num1 << " + " << num2 << " = " << sum		<< endl;
  cout << num1 << " - " << num2 << " = " << difference	<< endl;
  cout << num1 << " * " << num2 << " = " << product	<< endl;
  cout << num1 << " / " << num2 << " = " << ratio	<< endl;
  cout << num1 << " % " << num2 << " = " << remainder	<< endl;

  return 0;
}
