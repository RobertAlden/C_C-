#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void fill(int array[], int size)
{
	cout << "The array is being seeded with the following random values from 50 to 250." << endl;
	cout << "Format for output is  < POSITION | VALUE >" << endl;
	for (int i=0;i<size;i++)
	{
		int q = (rand() % 200) + 50;
		cout << " <" << setw(3) << i << " | " << setw(3) << q << " >";
		if ((i + 1) % 5 == 0) cout << endl;
		array[i] = q;
	}
	cout << endl;
}
int sum(int array[], int size)
{
	 cout << "As the array was iterated from beginning to end, this was the running total, presented step by step." << endl;
	 cout << "Total: " << endl;  
	int sum = 0;
	for (int i=0;i<size;i++)
	{
		sum += array[i];
		cout << " " << sum << "," ;
		if ((i + 1) % 5 == 0) cout << endl;
	}
	cout << endl;
	return sum;
}
int lowest(int array[], int size)
{
	int low = 250;
	
	for (int i = 0;i<size;i++)
	{
		int test = array[i];
		if (test < low) low = test;
	}
	return low;
}
int main()
{
srand (time(NULL));
int size = 20;
int Array[20] = {};
int total = 0;
int lownum = 0;
fill (Array, size);
total = sum(Array,size);
lownum = lowest(Array, size);
cout << "The sum of all values in the array is: " << total << endl;
cout << "The lowest value within the array is: " << lownum << endl;
return 0;
};

