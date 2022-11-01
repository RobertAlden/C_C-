// lab60.cpp
// Review of Strings
//
// Trace this program and determine the output.
// Then, compile & run to verify your answers.
//---------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int index;	// position index of a character in a string
  string date;

  date = "February";

  date = date + " 15, 2016";

  index = date.find("15");

  cout << date << endl;
  cout << "15 is at index " << index << endl;
  
  return 0;
}
