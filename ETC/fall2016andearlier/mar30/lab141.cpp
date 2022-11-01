// lab141.cpp
// Structures
//
// Complete the coding of the print function. The main function
// is already written. Do not add any code to main.
//
// The output of the program should be:
// (-3, 5)
// (1, 0.2)
//--------------------------------------------------------------
#include <iostream>
using namespace std;

// Prototypes

struct Point		// A point in the coordinate system
{
  double x, y;	
};

void print(Point p);
// Outputs the point p in parenthesized form (x, y).
// For example (2, 1)

//----------------------------------------------------------
int main()
{
  Point p, q;

  p.x = -3;	// initialize p
  p.y = 5;

  q.x = 1;	// initialize q
  q.y = 0.2;

  print(p);
  print(q);

  return 0;
}
//----------------------------------------------------------
// Function implementation

void print(Point p)
{
  // YOUR CODE
cout << "(" << p.x << ", " << p.y << ")" << endl;

}
