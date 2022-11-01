#include <iostream>
using namespace std;

//1/20/2016, program to convert a fahrenheit measurement into 
//celsius and kelvin

int main()
{

	double tempur, cel, kel;
	cout << "ENTER CURRENT TEMPERATURE IN FAHRENHEIT: " << endl;
	cin >> tempur;
	
	cel = 5.0 / 9.0 * (tempur - 32);
	kel = cel + 273.15;
	
	cout << "TEMPERATURE IN CELSIUS: " << cel << endl;
	cout << "TEMPERATURE IN KELVIN: " << kel << endl;
}
