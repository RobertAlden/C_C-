// lab144.cpp
// Structures
//
// Write the prototype and coding of a new version of the print function.
// This version should receive a string and also a point variable.
// The function should print the string and then the point in
// parenthesized form (as before). The main has already been written;
// do not change it.
//
// The output of the program will be:
// point p = (-5, 8)
//--------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct Point
{
  double x, y;	
};

// YOUR CODE: write the prototype of the new print function here, the
// heading only!
void print(string a, Point p);

//**************************************************************************
int main()
{
  Point p;

  p.x = -5;
  p.y = 8;

  print("point p = ", p); 

  return 0;
}
//**************************************************************************
// Function implementation

// YOUR CODE: implement the print function here.
void print(string a, Point p)
{
cout << a << "(" << p.x << ',' << p.y << ")" << endl;
};
