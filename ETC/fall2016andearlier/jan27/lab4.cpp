// lab4.cpp
// This program calculates the distance traveled on a trip.
// Add your code where requested.
//
// Input:  speed (MPH), time (hours)
// Output: distance
//
// Sample session
// Enter your speed(MPH): 60
// Enter travel time(hours): 2.5
// Distance = 150
//----------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int speed;
  double time, distance;

  cout << "Enter your speed(MPH): ";
  cin  >> speed;

  cout << "Enter travel time(hours): ";
  cin  >> time;

  // YOUR CODE: calculate the distance.

  distance = speed * time;


  // YOUR CODE: output the distance using a prompt.

 cout << "Your distance traveled is: "  << distance << endl;

  return 0;
}
