// lab142.cpp
// Structures
//
// Complete the coding of the construct function. Note that this is a
// value-returning function.
//
// The main & print functions are already written. Do not modify main.
// The output of the program should be p = (1, 2)
//--------------------------------------------------------------------
#include <iostream>
using namespace std;

// Prototypes

struct Point
{
  double x, y;	
};

void print(Point p);
// Outputs the point p.

Point construct(int a, int b);
// Receives integers a and b. The function creates a point structure,
// assigns a and b to x and y of the point. Then, it returns the structure. 
//*************************************************************************
int main()
{
  Point p;

  p = construct(1, 2);		// creates the point p(1, 2)

  cout << "p = ";
  print(p);

  return 0;
}
//**************************************************************
// Function implementations

void print(Point p)
{
  cout << '(' << p.x << ',' << p.y << ')' << endl;
}
//--------------------------------------------------------------

Point construct(int a, int b)
{
  // YOUR CODE: declare a new Point variable.
  // Assign a and b to x and y fields of your Point variable.
  // Return the variable.
Point NewPoint;
NewPoint.x = a;
NewPoint.y = b;

return NewPoint;
}
