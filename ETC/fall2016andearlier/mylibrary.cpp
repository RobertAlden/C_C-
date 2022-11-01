//CS-1313 Computer Science I			Program - 5			Due: Sunday, April 10
//Spring 2016					Functions
//The purpose of this assignment is to implement and test a library of functions that may be used in future programs. 
//Create a file called mylibrary and implement each of the following functions in this file. 
//To test these functions create the main function in a separate file called prog5.cpp. After coding each function in mylibrary,
// call it several times from main (in file prog5.cpp) and test it.
//Important: the comment statements inside each function must also be included in mylibrary.
// file:	mylibrary
// Author: your name
// Date:	     last date this file was modified
// This file contains a library of useful functions.
//-----------------------------------------------------------------------------------------------------------------------------
#include <cmath>	// for pow and sin functions
using namespace std;
double hatSize(double feet, double inches, double weight)
{
  // This function receives the height of a person in feet and inches; it also receives the weight in pounds.
  // The function returns the hat size for the person using this formula:
  // weight divided by height (total inches) and all that multiplied by 2.9
  // Note: feet and inches should be converted to all inches before using the formula.
  // Example: 5 feet, 8 inches = 5 * 12 + 8 = 68 inches
  feet = feet * 12;
  height = feet + inches;
  return weight/height * 2.9;
  
}
//-----------------------------------------------------------------------------------------------------------------------------
bool isLeepYear(int year)
{
  // Receives a year number and determines if it is a leap year (if it has 366 days).
  // This function returns true for a leap year, and false otherwise.
  // Rules: Any year that is divisible by 400 is a leap year; else, if year is divisible by 4 and year is not   
  // divisible by 100, it is a leap year; else, it is not. 
}
//-----------------------------------------------------------------------------------------------------------------------------
double projectileRange(double velocity, double angle)
{
  // Computes and returns the distance a projectile travels
  // ignoring air resistance & propulsion.
  // velocity = the speed of projectile’s launch (in meters per second) 
  // angle = the angle at which the projectile is launched (in degrees)
  // formula:      
  const double PI = 3.14159265;

}
//-----------------------------------------------------------------------------------------------------------------------------
double projectileTime(double velocity, double angle)
{
  // Computes and returns the time (in seconds) it takes for a projectile to reach the target.
  // velocity = the speed at which a projectile in launched (miles per hour)
  // angle = the angle at which the projectile is launched (degrees)
  // formula: 
  const double PI = 3.14159265;

}
//-----------------------------------------------------------------------------------------------------------------------------
void loan(double amount, double annualRate, double years, double& payment, double& interest)
{ 
  // This function calculates and returns the monthly payment of a loan, and the total interest paid.
  // It receives the loan amount, annual interest rate (in decimal) and the number of years.
  // formula:  
  // note that r is the monthly interest rate; therefore, r = annualRate / 12
  // and m is the total number of payments, m = years * 12
  // To calculate the total interest compute the total of all monthly payments and subtract from it the
  // loan amount.

}
//-----------------------------------------------------------------------------------------------------------------------------
void makeChange(int amount, int& quarters, int& dimes, int& pennies)
{
  // This function receives an amount <= 100 cents. It calculates how many quarters, dimes, and
  // pennies to give out for that amount. The function computes the maximum number of quarters,
  // and then maximum number of dimes. Example, if amount = 67, quarters = 2, dimes = 1, pennies = 7

} 
//***********************************************************************************
// END OF MYLIBRARY
