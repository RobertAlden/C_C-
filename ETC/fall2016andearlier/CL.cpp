#include <iostream>
#include <cstdlib>
using namespace std;

class node {
	private:
	int value;
	node * next;
	public:
	int getValue(){ return value;}
	void setValue(int x){value = x;}
	
	node * getNext(){ return next;}
	void setNext(node * x){next = x;}
};

class CList {
	private:
	node * first;
	node * last;
	int size;
	public:
	node * getFirst(){ return first;}
	void setFirst(node * x){first = x;}
	
	node * getLast(){ return last;}
	void setLast(node * x){last = x;}
	
	int getSize(){ return size;}
	void setSize(int x){size = x;}
	
	void addFront(int x){
		node * temp;
		temp = new node;
		temp->setValue(x);
		if (size == 0){
			first = temp;
			temp->setNext(temp);
			last = temp;
		} else {
			temp->setNext(first);
			first = temp;
			last->setNext(temp);
		}
		size++;
	}
	
	void remove(int x){
		node * temp = first;
		node * temp2 = last;
		for (int i = 0;i< size;i++) {
			if (temp->getValue() == x){
				temp2->setNext(temp->getNext());
				if (temp == first) first = temp->getNext();
				size--;
				delete temp;
				break;
			} else {
				temp2 = temp;
				temp = temp->getNext();
			}
		}
	}
	
	void print(int x){
		node * temp = first;
		for (int i = 0; i < size * x; i++){
			cout << temp->getValue() << " ";
			temp = temp->getNext();
		}
		cout << "end print" << endl;
	}
	
	CList(){
		first = last = NULL;
		size = 0;
	}
};

int main(){
	CList obj;
	/*
	obj.addFront(15);
	obj.addFront(25);
	obj.addFront(35);
	obj.addFront(45);
	obj.addFront(55);
	obj.addFront(65);
	obj.print(1); // 65 55 45 35 25 15
	obj.remove(65);
	*/
	obj.addFront(65);
	obj.print(2); // 65 55 45 35 15 65 55 45 35 15
	return 0;
}
