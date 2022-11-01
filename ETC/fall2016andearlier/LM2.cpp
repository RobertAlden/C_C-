
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
		(*temp).setNext(p1);
		p1 = temp;
	}
	void addRear(int a){
		storage * temp;
		temp = new storage;
		(*temp).setValue(a);
		(*temp).setNext(0);
		storage * temp2 = p1;
		if (p1 == 0){
			p1 = temp;
		}
		else { 
		while ((*temp2).getNext() != 0){
			temp2 = (*temp2).getNext();
			}
			(*temp2).setNext(temp);
		}		
		
		
	}
	void print(){
		storage * temp = p1;
		while (temp != 0){
			cout << (*temp).getValue() << endl;
			temp = (*temp).getNext();
		}
		cout<< "--print sequence completed--" << endl;
		
	}
	void removeLast(){
		if (p1 != 0){
		storage * temp2 = p1;
		storage * temp;
		while ((*temp2).getNext() != 0){
			temp = (*temp2).getNext();
			if ((*temp).getNext() == 0){
				(*temp2).setNext(0);
				(*temp).setValue(0);
			}
			else {
				temp2 = (*temp2).getNext();
			}
			}
		}
	
	}
	void addAfter(int a, int b){
		storage * temp;
		temp = new storage;
		(*temp).setValue(b);
		storage * temp2 = p1;
		while ((*temp2).getNext() != 0){
		if ((*temp2).getValue() == a){
			(*temp).setNext((*temp2).getNext());
			break;
		} else {
			temp2 = (*temp2).getNext();
		}
		}
		(*temp2).setNext(temp);
		
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
	obj1.addFront(20);
	obj1.addRear(90);
	obj1.print(); // expected: 20,10,100,90
	obj1.removeLast();
	obj1.print(); // expected: 20,10,100
	obj1.addAfter(20,50);
	obj1.print(); // expected: 20,10,50,100
	return 0;
}
