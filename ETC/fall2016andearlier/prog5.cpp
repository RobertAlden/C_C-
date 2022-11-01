
// Programmer: your name
// Date:
// Purpose: This file contains a driver program to test all functions in “mylibrary”.
//---------------------------------------------------------------------------------------------------------
#include "mylibrary"
#include <iostream>
using namespace std;
int main()
{
double x, a = 0, b = 0, c = 0, d = 0, e = 0;
cout << "vel:" << endl;
cin >> x;
cout << "angle:" << endl;
cin >> a;
//cout << "years: " << endl;
//cin >> b;
//loan(x,a,b,c,d);
//cout << "payment: " << c << endl;
b = projectileRange(x,a);
cout << b << endl;
}
