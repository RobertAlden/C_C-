// lab143.cpp
// Structures
//
// Complete the coding of the function distanceToOrigin. Note that this is a
// value-returning function. Also, complete the main function.
//
// The print and construct functions have already been written.
// The output of the program should be:
// p = (3, 4)
// Distance to origin = 5
//--------------------------------------------------------------------------
#include <iostream>
#include <cmath>	// for sqrt()
using namespace std;

// Prototypes

struct Point
{
  double x, y;	
};

void print(Point p);
// Outputs the point p.

Point construct(int a, int b);
// Creates and returns the point (a, b)

double distanceToOrigin(Point p);
// Computes how far the point p is from the origin.

//****************************************************
int main()
{
  Point p;
  double dist;		// distance of p from the origin

  p = construct(3, 4);

  cout << "p = ";
  print(p);

  cout << "Distance to origin = ";

  // YOUR CODE: call the function distanceToOrigin to compute
  // the distance of point p from the origin. Assign the distance
  // to variable dist. Then, output this variable.
  dist = distanceToOrigin(p);
  cout << dist <<  endl;


  return 0;
}
//****************************************************************
// Function implementations

void print(Point p)
{
  cout << '(' << p.x << ',' << p.y << ')' << endl;
}
//----------------------------------------------------------------
Point construct(int a, int b)
{
  Point p;
  p.x = a;
  p.y = b;
  return p;
}
//----------------------------------------------------------------
double distanceToOrigin(Point p)
{
  // YOUR CODE: compute and return the distance using the formula:
  // square-root-of(x squared + y squared) where x and y are
  // the x and y coordinates of point p
double distance = sqrt(p.x*p.x + p.y*p.y);
return distance;

}
//----------------------------------------------------------------
