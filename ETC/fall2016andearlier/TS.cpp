#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class TNode{
	int value;
	TNode * left;
	TNode * right;
	public:
	TNode(int x = 0){
		value = x;
		left = NULL;
		right = NULL;
	}
	int getValue(){return value;}
	void setValue(int x){value = x;}
	TNode* getLeft(){return left;}
	void setLeft(TNode* x){left = x;}
	TNode* getRight(){return right;}
	void setRight(TNode* x){right = x;}
};

class Tree {
	TNode * root;
	int size;
	public:
	TNode* search(int x){
		TNode * temp;
		return temp;
	}
	
	void addElement(int x){
		TNode * temp;
		temp = new TNode;
		temp->setValue(x);
		if (size == 0){
			root = temp;
		} else {
			TNode * temp2 = root;
			while (true) {
				if (x > temp2->getValue()){
					if (temp2->getRight() != NULL) {
						temp2 = temp2->getRight();
					} else{
						temp2->setRight(temp);
						break;
					}
				} else {
					if (temp2->getLeft() != NULL) {
						temp2 = temp2->getLeft();
					} else{
						temp2->setLeft(temp);
						break;
					}
				}
			}
		}
		
		size++;
	}
	
	void print(TNode* x){
		if (x!=NULL){
			print(x->getLeft());
			cout << x->getValue() << " ";
			print(x->getRight());		
			
		}
	}
	
	TNode* getRoot(){return root;}
	void setRoot(TNode* x){root = x;}
	
	int getSize(){return size;}
	void setSize(int x){size = x;}
};

main(){
	srand(time(NULL));
	Tree obj;
	/*
	obj.addElement(10);
	obj.addElement(100);
	obj.addElement(5); 
	obj.addElement(7);
	obj.addElement(200);
	obj.addElement(150);
	obj.addElement(20);	
	*/
	for (int i = 0;i < 10; i++){
		obj.addElement(5);
	}
	obj.print(obj.getRoot());
	cout << endl;

	
//	cout << obj.search(5)->getValue() << endl;
	return 0;
}
