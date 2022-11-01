// lab114.cpp
// This file contains a modified version of lab110.
// This program should input two integers and output their squares.
// Complete the main program.
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// function prototype
int square(int num);
//----------------------------------------------------------------

int main()
{
  int a, b;

  // YOUR CODE: input integers a and b
 cout << "numbers to be squared? ";
 cin << a;
 cin << b;


  // YOUR CODE: output the square of a and b (use the square function)
a = square(a);
b = square(b);
cout << a << endl;
cout << b << endl;



  return 0;
}
//----------------------------------------------------------------

int square(int num)
{
  return num * num;
}
//----------------------------------------------------------------

