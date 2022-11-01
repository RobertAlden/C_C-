// lab131.cpp
// The program will read the radius of a circle and output its
// area and circumference.
// Add your code where it is required.
//
//---------------------------------------------------------------
#include <iostream>
using namespace std;

// function prototypes

void getRadius (double &radius);
// Outputs a prompt and inputs the radius of a circle.

void compute (double radius, double &area, double &circum);
// Receives the radius of a circle and returns the area and also
// the circumferece.
 
//---------------------------------------------------------------
int main()
{
  double radius, area, circum;

  // YOUR CODE: call the getRadius function
getRadius(radius);


  // YOUR CODE: call the compute function
compute(radius, area, circum);

  // YOUR CODE: display the area and circum using cout stmts
cout << "area: " << area << endl;
cout << "circumference: "  << circum << endl;


  return 0;
}
//---------------------------------------------------------------
void getRadius (double &radius)
{
  // YOUR CODE: propmt the user and input the radius
cout << "input radius: " << endl;
cin >> radius;
}
//---------------------------------------------------------------
void compute (double radius, double &area, double &circum)
{
  // YOUR CODE: calculate area and circum using the formulas:
  // area = 3.14 * radius * radius
  // circum = 2 * 3.14 * radius
  // Don't use any 'cout' or 'return' statements in this function!
area = 3.14 * radius * radius;
circum = 2 * 3.14 * radius;


}
