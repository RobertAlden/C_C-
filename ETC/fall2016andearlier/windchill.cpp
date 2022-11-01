
//**********************************************************
// Programmer: Robert Alden
// Course:	CS-1314
// Program:	4
// Date:	date of completion
// Purpose:	This program produces a chart of the intensity of wind chill based on tempurates and windspeed
//**********************************************************
#include <iostream>
#include <cmath>		// for round and pow functions
#include <iomanip>		// for setw function
using namespace std;
 
int main()
{
	int  windchill, S, T;
	// YOUR CODE: output the table heading (top 4 rows of table) with separate cout stmts.

  cout << "Wind Chill Table" << endl;
  cout << "Speed  Temperature T" << endl;
  cout << "MPH     45   40   35   30   25   20   15   10    5    0   -5  -10" << endl;
  cout << "-----------------------------------------------------------------" << endl;
  
  
  // YOUR CODE: use a nested for-loop to output the wind chill. The outer loop should generate   
  // wind speeds S = 5, 10 , 15, …, 50. The inner loop should generate temperatures T = 45, 40, …  
  // .., -10. In the innermost loop calculate the wind chill and display it.
  for (S = 5; S <= 50; S = S + 5)
  {
	  cout << setw(3) << S << " |";
	  for (T = 45; T >= -10; T = T - 5)
	  {
		windchill = round(35.74+0.6215*T-35.75*pow(S,0.16)+0.4275*T*pow(S,0.16));
		cout << setw(5) << windchill;
	  }
	  cout << endl;
  }

  // YOUR CODE: output the bottom border of the table(a row of dashes)

    cout << "-----------------------------------------------------------------" << endl;
  return 0;
}
