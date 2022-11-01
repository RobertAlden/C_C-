#include <iostream>
using namespace std;

class storage {
	private:
	int value;
	storage * next;
	public:
	void setValue(int a){
		value = a;
	}
	int getValue(){
		return value;
	};
	storage * getNext(){
		return next;
	};
	void setNext(storage* a){
		next = a;
	}
};

class linkedMemory {
	private:
	storage * p1;
	public:
	void addFront(int a){
		storage * temp;
		temp = new storage;
		(*temp).setValue(a);
		if (p1 == 0){
			(*temp).setNext(0);
		}
		else if (p1 != 0)
		{
			(*temp).setNext(p1);
		}
		p1 = temp;
	}
	void addRear(int a){
	/*	storage * temp = p1;
		temp = new storage;
		(*temp).setValue(a);
		while (temp != 0){	
			temp = (*temp).getNext();
		} else {
			
		}*/
	}
	void print(){
		storage * temp = p1;
		while (temp != 0){
			cout << (*temp).getValue() << endl;
			temp = (*temp).getNext();
		}
		
	}
	
	storage	* getP1(){
		return p1;
	}
	void setP1(storage * a){
		p1 = a;
	}
	linkedMemory(){
		p1 = 0;
	}
};


main (){
	linkedMemory obj1;
	obj1.addFront(10);
	obj1.addRear(100);
	obj1.print();
	obj1.addFront(50);
	obj1.addFront(20);
	obj1.addFront(30);
	obj1.addFront(40);
	obj1.addRear(90);
	obj1.print();
	return 0;
}
