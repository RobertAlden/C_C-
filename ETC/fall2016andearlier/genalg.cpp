#include <iostream>
#include <cstdlib>
using namespace std;

class SNode {
        private:
        int value;
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
};

class SList {
        private:
        SNode * p1;
        public:
        void addFront(int a){
                SNode * temp;
                temp = new SNode;
                (*temp).setValue(a);
                (*temp).setNext(p1);
                p1 = temp;
        }
        void addRear(int a){
                SNode * temp;
                temp = new SNode;
                (*temp).setValue(a);
                (*temp).setNext(0);
				 SNode * temp2 = p1;
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
                SNode * temp = p1;
                while (temp != 0){
                        cout << (*temp).getValue() << endl;
                        temp = (*temp).getNext();
                }
                cout<< "--print sequence completed--" << endl;

        }
		void removeLast(){
                if (p1 != 0){
                SNode * temp2 = p1;
                SNode * temp;
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
		void removeAll(){
			while (p1->getNext() != 0)
			{
				removeLast();
			}
		}
		void addAfter(int a, int b){
                SNode * temp;
                temp = new SNode;
                (*temp).setValue(b);
                SNode * temp2 = p1;
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
		void removeNode(int x){					         	
			SNode * temp2 = p1; 
			SNode * temp = p1;
			while (temp2 != NULL){
			if (temp2->getValue() == x){
				temp->setNext(temp2->getNext());
				delete temp2;
				break;
			} else {
				temp = temp2;
				temp2 = temp2->getNext();
			}
			}
		}
		SNode * getP1(){
                return p1;
        }
        void setP1(SNode * a){
                p1 = a;
        }
        SList(){
                p1 = 0;
        }
};

class MultiList {
	private:
		int numlist;
		SList** handle;
	
	public:
	MultiList(int x = 4){
		numlist = x;
		handle = new SList*[numlist];
		for (int i = 0; i < numlist;i++){
			handle[i] = new SList;
		}
	}
	void setNumList(int x){numlist = x;}
	int getNumList(){return numlist;}
	void setHandle(SList** x){handle = x;}
	SList** getHandle(){return handle;}
	void addElement(int x){
		if (x < 100){
			handle[0]->addRear(x);
		} else if (x < 300){
			handle[1]->addRear(x);
		} else if (x < 500){
			handle[2]->addRear(x);
		}else {
			handle[3]->addRear(x);
		}
	}
	void removeElement(int x){
		if (x < 100){
			handle[0]->removeNode(x);
		} else if (x < 300){
			handle[1]->removeNode(x);
		} else if (x < 500){
			handle[2]->removeNode(x);
		}else {
			handle[3]->removeNode(x);
		}
	};
	void removeAllLists(){
		handle[0]->removeAll();
		handle[1]->removeAll();
		handle[2]->removeAll();
		handle[3]->removeAll();
	}
	void print(){
		for (int i = 0;i < numlist;i++){
		cout << "The values in box " << i+1 << " are: " << endl;
		handle[i]->print();
		}
	}
};

int main(){
	MultiList obj;
	for (int i=0;i<20;i++){
		obj.addElement(1+rand()%1000);
	}
	obj.print();
	obj.addElement(465);
	obj.print();
	obj.removeElement(465);
	obj.print();
	obj.removeAllLists();
	obj.print();
	return 0;
}
