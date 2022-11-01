#include <iostream> 
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
using namespace std;
 // int arrayName[20];
 void fillArray(int []);
 void SumArray(int []);
 int MinArray(int []);
 void print (int array1[])
        {
        for (int i=0;i<20;i++){
                cout<<array1[i]<<"\t";
        }
        cout<<"\n";
}
int main(){
        int arrayName[20];
        fillArray(arrayName);
        //cout<<arrayName<<endl;
        print(arrayName);
        SumArray(arrayName);
        cout<<"The minimal value in array is: "<<MinArray(arrayName)<<endl;
        return 0;
}
void fillArray(int array1[]){
        for (int i=0;i<20;i++){
                array1[i]=rand()%201 + 50;
        }
}

void SumArray(int array1[]){
	int sum = 0;
	for (int i=0;i<20;i++)
	{
		sum += array1[i];
	}
	cout << "The sum of the array is: " << sum << endl;
}

int MinArray(int array1[]){
	int low = 250;
	
	for (int i = 0;i<20;i++)
	{
		int test = array1[i];
		if (test < low) low = test;
	}
	return low;
}
