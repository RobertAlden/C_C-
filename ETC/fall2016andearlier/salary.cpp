#include <iostream>
using namespace std;

//1/20/2016, program to calcualte a 3.4 percent increase in annual salary

int main()
{

	double salary;
	cout << "ENTER PREVIOUS YEARS SALARY: " << endl;
	cin >> salary;
	
	salary = salary + (salary * 0.034);
	
	cout << "EXPECTED SALARY AFTER RAISE: " << salary << endl;
	
	return(0);
}
