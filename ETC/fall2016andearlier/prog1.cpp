//********************************************************************* 
// Programmer: Robert Alden 
// Course: CS-1314
// Program: 1 
// Date: 2/8/16
// Purpose: This program computes the total cost of tuition fees for a semester.
// Input: number of credit hours, cost per hour
// Calculate: total cost including $50 misc fees
// Output: total cost
//********************************************************************* 
#include <iostream> 
#include <iomanip>
using namespace std; 
int main()
{
int hours;
// number of credit hours
double costperhour;
// cost of each credit hour
double totalcost;
// total cost of tuition
cout << "How many hours are you enrolled in? ";
cin >> hours;
// ADD YOUR CODE BELOW THIS LINE to input costperhour
cout << "What is the cost per hour? $";
cin >> costperhour;
// ADD YOUR CODE to calculate the total cost of tuition. Include 50.00 for fees
totalcost = costperhour * hours + 50;
cout << fixed << showpoint << setprecision(2); // Format the output to display 2 decimal digits 
//ADD YOUR CODEto output totalcost(see the sample run)
cout << "The total tuition fees are: " << totalcost << endl;

return 0;
}
