/*
Name: Robert Alden
Assignment: Prog 6
Purpose: implementations of list functions.
*/
#include list.h
#include <iostream>
using namespace std;

void List::print()
{
	cout << "[";
	for(int i=0;i<size;i++)
	{
		cout << array[i]<< " ";
    };
	cout << "]" << endl;
}

