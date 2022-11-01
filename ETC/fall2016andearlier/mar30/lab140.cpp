// lab140.cpp
// Structures
// Read the following program and determine the output.
// Then, compile & run to see if you were correct.
//----------------------------------------------------------
#include <iostream>
using namespace std;

struct Point		// A point in the coordinate system
{
  double x, y;		// The x and y coordinates, (x, y)
};
//----------------------------------------------------------
int main()
{
  Point point1, point2;

  point1.x = 3.0;
  point1.y = 5.0;

  point2 = point1;

  point2.x = point2.x + 4;
  point2.y--;

  cout << "point2 = " << point2.x << "," << point2.y << endl;

  return 0;
}
