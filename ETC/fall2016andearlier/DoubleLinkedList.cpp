#include <iostream>
#include <cstdlib>
using namespace std;

class DNode{
	private:
	int element;

	DNode *next;

	DNode *prev;

	public:
	DNode(int x=0,DNode *p1=NULL,DNode *p2=NULL){
		element=x;
		next=p1;
		prev=p2;
	}
	void setElement(int x){element=x;}
	
	int getElement(){return element;}
	
	void setNext(DNode *x){next=x;}
	
	DNode* getNext(){return next;}
	
	void setPrev(DNode *x){prev=x;}
	
	DNode* getPrev(){return prev;}
};
class DList{
	private:
	DNode *head;
	DNode *tail;
	int size;
	public:
	DList(){
	head=NULL;
	tail=NULL;
	size=0;
	}
	void setHead(DNode*x){
		head = x;
	}
	DNode*getHead(){
		return head;
	}
	void setTail(DNode*x){
		tail = x;
	}
	DNode*getTail(){
		return tail;
	}
	void setSize(int x){
		size = x;
	}
	int getSize(){
		return size;
	}
	
	void addFront(int x){
		DNode * temp;
		temp = new DNode;
		(*temp).setElement(x);
		(*temp).setNext(head);
		if (size != 0) head->setPrev(temp);
		else temp->setPrev(0);
		head = temp;
		if (size == 0) tail = temp;
		size++;
	}
	void addAfter(int pos, int val){
		DNode * temp;					
		temp = new DNode;	            
		(*temp).setElement(val);			
		if (size != 0) {
			DNode * temp2 = head; 				
			while ((*temp2).getNext() != 0){  	    
				if ((*temp2).getElement() == pos){			
					(*temp).setNext((*temp2).getNext());
					DNode* temp3 = temp2->getNext();
					temp3->setPrev(temp);
					break;				
				} else {
					temp2 = (*temp2).getNext();
				}
			}
			temp->setPrev(temp2);
			(*temp2).setNext(temp); 
		}else if (size == 0) {
			head = tail = temp;
		}							
		size++;
	}
	void addRear(int x){
		DNode * temp;
		temp = new DNode;
		(*temp).setElement(x);
		(*temp).setNext(0);
		if (size == 0) {
			head = temp;
			temp->setPrev(0);
		} else {
			tail->setNext(temp);
			temp->setPrev(tail);
		}
		tail = temp;
		size++;	
	}
	void removeFront(){
		if (size !=0) {
			if (size == 1) {
				delete head;
				head = tail = 0;
				size--;
			} else {
				DNode* temp = head;
				head = head->getNext();
				head->setPrev(0);
				delete temp;
				size--;
			}
		}
	}
	void removeRear(){
		if (head != 0){
			DNode * temp2 = head;
			DNode * temp;
			while ((*temp2).getNext() != 0){	//if the list hasn't terminated:
				temp = (*temp2).getNext();		//access the next node,
				if ((*temp).getNext() == 0){	// and determine if this node is the end and
					if (size == 1) {
						head = 0;
						tail = 0;
					} else {
						(*temp2).setNext(0);		// unlink and clear its information.
						(*temp).setElement(0);
						delete temp;
						tail = temp2;
					}
				size--;
				}else {
				temp2 = (*temp2).getNext();	// if the end wasn't found, advance to the next node.
				}
			}
		}
	}
	void removeNode(int x){					         	
		if (size != 0) {
			DNode * temp2 = head; 				
			while ((*temp2).getElement() != x){
				if (temp2->getNext() != NULL) {
					temp2 = (*temp2).getNext();
				} else {break;}
			}
			DNode * temp = temp2->getPrev();
			temp->setNext(temp2->getNext());
			delete temp2;
		} 							
		size--;
	}
	
	void print(){
		if (size != 0) {
		DNode * temp = head;
		for (int i = 0;i<size;i++){
			cout << (*temp).getElement() << "   ";
			temp = (*temp).getNext();
		}
		cout << endl;
		
		} else cout << "Your List is Currently Empty" << endl;
	}

};
int main(){
	DList obj;
	obj.addFront(5);
	obj.addFront(10);
	obj.addFront(20);
	obj.print(); // 20 10 5
	obj.addRear(200);
	obj.print(); // 20 10 5 200
	obj.removeNode(5);
	obj.print(); // 20 10 200
	for (int i=0; i<5;i++){
		obj.addFront(1000*(i+1));
		obj.addRear(1050*(i+1));
	}
	obj.removeFront();
	obj.print(); // 4000 3000 2000 1000 20 10 200 1050 2100 3150 4200 5250 
	obj.removeRear();
	obj.print(); // 4000 3000 2000 1000 20 10 200 1050 2100 3150 4200
return 0;
}

