#include <iostream>
using namespace std;

class SNode {
	private:
	int value;
	int position;
	SNode * previous;
	SNode * next;
	public:
	void setValue(int a){
		value = a;
	}
	int getValue(){
		return value;
	};
	SNode * getNext(){
		return next;
	};
	void setNext(SNode* a){
		next = a;
	}
	SNode * getPrevious(){
		return previous;
	};
	void setPrevious(SNode* a){
		previous = a;
	}
	int getPosition(){
		return position;
	};
	void setPosition(int a){
		position = a;
	}
};


class SList {
	private:
	SNode * first;
	SNode * last;
	int size;
	public:
	void addFront(int a){
		SNode * temp;
		temp = new SNode;
		(*temp).setValue(a);
		(*temp).setNext(first);
		if (size != 0) first->setPrevious(temp);
		else temp->setPrevious(0);
		first = temp;
		if (size == 0) last = temp;
		size++;
	}
	
	void addRear(int a){
		SNode * temp;
		temp = new SNode;
		(*temp).setValue(a);
		(*temp).setNext(0);
		/*
		SNode * temp2 = first;
		if (first == 0){
			first = temp;
		}
		else { 
		while ((*temp2).getNext() != 0){
			temp2 = (*temp2).getNext();
			}
			(*temp2).setNext(temp);
		}
		*/
		if (size == 0) {
			first = temp;
			temp->setPrevious(0);
		} else {
			last->setNext(temp);
			temp->setPrevious(last);
		}
		last = temp;
		size++;
		
		
		
	}
	void sequenceList(){		
		SNode * temp = first;
		for (int i = 0;i<size;i++){
			temp->setPosition(i+1);
			temp = (*temp).getNext();
		}
	}
	void print(){
		cout<< "--print sequence beginning<<" << endl;
		if (size != 0) {
		sequenceList();
		SNode * temp = first;
		for (int i = 0;i<size;i++){
			cout << temp->getPosition() << ". " << (*temp).getValue() << endl;
			temp = (*temp).getNext();
		}
		} else cout << "Your List is Currently Empty" << endl;
		cout<< ">>print sequence completed--" << endl;
	}
	void inversePrint(){
		cout<< "--reverse print sequence beginning<<" << endl;
		if (size != 0) {
		sequenceList();
		SNode * temp = last;
		for (int i = 0;i<size;i++){
			cout << temp->getPosition() << ". " << (*temp).getValue() << endl;
			temp = (*temp).getPrevious();
		}
		} else cout << "Your List is Currently Empty" << endl;
		cout<< ">>reverse print sequence completed--" << endl;
	}
	void removeLast(){
		if (first != 0){
		SNode * temp2 = first;
		SNode * temp;
		while ((*temp2).getNext() != 0){	//if the list hasn't terminated:
			temp = (*temp2).getNext();		//access the next node,
			if ((*temp).getNext() == 0){	// and determine if this node is the end and
				if (size == 1) {
					first = 0;
					last = 0;
				} else {
				(*temp2).setNext(0);		// unlink and clear its information.
				(*temp).setValue(0);
				delete temp;
				last = temp2;
				}
				size--;
			}
			else {
				temp2 = (*temp2).getNext();	// if the end wasn't found, advance to the next node.
			}
			}
		}
	
	}
	void addAfter(int a, int b){
		SNode * temp;						     // define a pointer,
		temp = new SNode;	                     // create a container 
		(*temp).setValue(b);				     // and set its value,
		if (size != 0) {
		SNode * temp2 = first; 					 // starting from the beginning,
		while ((*temp2).getNext() != 0){  	     // begin iterating through the list.
		if ((*temp2).getValue() == a){			// if a node matching the first parameter is found
			(*temp).setNext((*temp2).getNext()); // set the newly created node's "next" to the
			SNode* temp3 = temp2->getNext();
			temp3->setPrevious(temp);
			break;								 // matching node's "next", and exit the while loop.
		} else {
			temp2 = (*temp2).getNext();
		}
		}
		temp->setPrevious(temp2);
		(*temp2).setNext(temp); //regardless of whether a matching node is found, 
		}else if (size == 0) {
		first = last = temp;
		}
								
		size++;
	}
	
	void removeFirst(){
		if (size !=0) {
			if (size == 1) {
				delete first;
				first = last = 0;
				size--;
			} else {
				SNode* temp = first;
				first = first->getNext();
				first->setPrevious(0);
				delete temp;
				size--;
			}
		}
	}
	
	SNode * getfirst(){
		return first;
	}
	void setfirst(SNode * a){
		first = a;
	}
	SNode	* getlast(){
		return last;
	}
	void setlast(SNode * a){
		last = a;
	}
	int getsize(){
		return size;
	}
	void setsize(int a){
		size = a;
	}
	SList(){
		first = 0;
		last = 0;
		size = 0;
	}
};

main (){
	SList obj1;
	
	/*
	obj1.addFront(10);
	obj1.addRear(100);
	obj1.addFront(20);
	obj1.addRear(90);
	obj1.print(); // expected: 20,10,100,90
	obj1.removeLast();
	obj1.print(); // expected: 20,10,100
	obj1.addAfter(10,50);
	obj1.print(); // expected: 20,10,50,100
	obj1.removeFirst();
	obj1.print(); // expected: 10,50,100
	obj1.inversePrint(); // expected: 100,50,10
	*/
	
	obj1.addFront(10);
	obj1.addRear(100);
	obj1.addFront(20);
	obj1.addRear(90);
	obj1.addFront(30);
	obj1.addRear(80);
	obj1.print(); // 30 20 10 100 90 80
	obj1.inversePrint(); // 80 90 100 10 20 30
	obj1.addAfter(10, 50);
	obj1.print(); // 30 20 10 50 100 90 80
	obj1.inversePrint(); // 80 90 100 50 10 20 30
	obj1.removeLast();
	obj1.removeFirst();
	obj1.print(); //  20 10 50 100 90 
	obj1.inversePrint(); //  90 100 50 10 20 
	
	return 0;
}
