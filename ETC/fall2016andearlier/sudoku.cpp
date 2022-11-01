#include <iostream>
#include <iomanip>
#include <cstdlib>	
using namespace std;

int main()
{
	srand(time(0));
	int lines[8][8]; // rows, columns.
//	int box[8][8]; // larger area ,inner number
	
	for (int i = 0; i < 9; i++)
	{
		for (int b = 0; b < 9; b++)
		{
			lines[i][b] = 0;
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
	    int o = rand() % 9;
		if (lines[i][o] == 0)
		{
			lines[i][o] = 1;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int o = 0; o < 9; o++)
		{
			cout << lines[i][o] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
