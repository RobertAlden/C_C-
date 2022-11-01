#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
void fill(int array[], int size)
{
	for (int i=0;i<size;i++)
	{
		int q = (rand() % 200) + 50;
		cout << "Filling spot " << i << " in array with value " << q << endl;
		array[i] = q;
	}
}
int sum(int array[], int size)
{
	int sum = 0;
	for (int i=0;i<size;i++)
	{
		sum += array[i];
		cout << "sum is currently: " << sum << endl;
	}
	return sum;
}
int main()
{
srand (time(NULL));
int Array [20] = {};
int total = 0;
cout << total << endl;
fill (Array, 20);
total = sum(Array, 20);
cout << total << endl;
return 0;
};

