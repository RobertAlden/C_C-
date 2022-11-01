#include <iostream>
using namespace std;
/*
class x {
	
}

class y :public x{
	
}
*/
/*
myarray {
int array
int size
normal get() and set() for elements and size
print()
}
sorted array inher from myarray
sort() 
*/

class MyArray {
	protected:
	int size;
	int array[];
	public:
	MyArray(int x){
		size = x;
		int array[size];
	}
	int getE(int index){return array[index];}
	void setE(int element, int index){array[index] = element;}
	void setSize(int x){size = x;}
	int getSize(){return size;}
	void print(){
		for (int i = 0; i < size; i++){
			cout << getE(i) << " ";
		}
		cout << endl;
	}
};

class SortedArray :public MyArray {
	void sort(){
		int temp;
		for (int i =0;i<getSize(); i++){
			for (int j =0;j<getSize()-1; j++){
				if (array[j]>array[j+1]){
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
};

main(){
	SortedArray obj1(5);
	obj1.setE(8,1);
	obj1.setE(15,2);
	obj1.setE(4,3);
	obj1.setE(11,4);
	obj1.setE(3,0);
	obj1.print();
	obj1.sort();
	obj1.print();
	return 0;
}
