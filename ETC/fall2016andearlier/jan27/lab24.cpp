// lab24.cpp: if-else statements
//
// Trace the following program by hand and determine what it will print.
// Then, compile and run the program to see if you were correct.
// DO NOT ADD ANY CODE TO THIS PROGRAM.
//
// To compile: g++ lab24.cpp
// To run:     ./a.out
//------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int salary = 2500;
  int incomeTax, net;
  

  if(salary > 3000)
    incomeTax = 900;
  else
    incomeTax = 600;


  net = salary - incomeTax;


  cout << "Salary is 2500, netpay is " << net << endl;
 
  return 0;
}
