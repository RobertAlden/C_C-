// file: main.cpp
#include "list.h"
#include <iostream>
using namespace std;
int main()
{
   List mylist;
   List yourlist(7,  99); 
   mylist.print();		// Will output [ ]
   yourlist.print();		// Will output [99 99 99 99 99 99 99]

}
