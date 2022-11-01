#include <iostream>
#include <cstdlib>
using namespace std;

class BNode{
	private:
		int data[4];
		BNode* link[5];
		int size;
	public:
		BNode(){
			size=0;
			for (int i=0; i<5; i++){
				link[i]=NULL;
			}
		}
		int getSize(){return size;}
		void setSize(int s){size=s;}
		int getData(int index){
			if (index<size){
				return data[index];
			}else{
				return -1;
			}
		}
		void setData(int index, int key){
			if (index<4){
				data[index]=key;
			}
		}
		BNode* getLink(int index){
			if (index<size+1){
                                return link[index];
                        }else{
                                return NULL;
                        }

		}
		void setLink(int index, BNode* ptr){
			if (index<5){
                                link[index]=ptr;
                        }

		}
};

class OurTree{
	private:
		BNode* root;
		int size;
	public:
		OurTree(){
			root=NULL;
			size=0;
		}
		BNode* getRoot(){return root;}
                void setRoot(BNode* r){root=r;}
                void setSize(int s){size=s;}
                int getSize(){return size;}
		BNode* search(int y, BNode* ptr){
			if (ptr!=NULL){
				BNode* temp=ptr;
				BNode* result;
				int temp1=temp->getSize();
				for (int i=0; i<temp1;i++){
					int temp2=temp->getData(i);
					if (y==temp2){
						result=temp;
						break;
					}else{
						if (y<temp2){
							result=search(y,temp->getLink(i));
							break;
						}else{
							if (i==temp1-1){
								result=search(y,temp->getLink(i+1));
								break;
							}else{
								
							}
							
						}
					}
				}
				return result;
			}else{
				return NULL;
			}
		}
		
		void addElement(int x)
		{
			if (root != NULL) // if the tree already has nodes
				addElementHelper(root, x); // call function for adding an element to the tree, which is not empty.
			else {
				root = new BNode; // initialize root node with value x
				root->setData(0,x);
				root->setSize(root->getSize()+1);
			}	
			size++; // increment size, we have added an element
		}

		void addElementHelper(BNode* currRoot, int x)
		{
			if (x < currRoot->getData(0)) // if x should be in the left subtree
			{
				if (currRoot->getLink(0) == NULL) // check if there is a left child
				{
					BNode* toInsert = new BNode;
					toInsert->setData(0,x);
					currRoot->setLink(0, toInsert); // initialize left child with new value
					toInsert->setSize(toInsert->getSize()+1);
				}
				else
					addElementHelper(currRoot->getLink(0), x); // call add element on the left subtree
			}
			else // if x should be in the right subtree
			{
				if (currRoot->getLink(1) == NULL) // check if there is the right child
				{
					BNode* toInsert = new BNode;
					toInsert->setData(0,x);
					currRoot->setLink(1, toInsert); // initialize right child with the new value
					toInsert->setSize(toInsert->getSize()+1);
				}
				else
					addElementHelper(currRoot->getLink(1), x); // call add element on the right subtree
			}
		}
		
		void removeElement(int x){
			
		}
		void dfprint(){
			if (root != NULL) dfprintHelper(root);
			cout << endl;
		}
		void dfprintHelper(BNode* ptr){
			for (int i = 0; i < 5; i++) {
				if (ptr->getLink(i) != NULL) {
					dfprintHelper(ptr->getLink(i));
				}
				if (ptr->getData(i)){
					int	output = ptr->getData(i);
					if (output != -1) {
					cout << output << " ";
					}
				}
				
			}
				
			
		}
		void bfprint(){
			if (root != NULL) {
				int depth = getDepth(root);		 
			
				for (int i = 0; i < depth; i++) {
					bfprintLevel(root, i);
				}
			}
			cout << endl;
		}
		void bfprintLevel(BNode* ptr, int level){
			if (ptr != NULL) {
				if (level == 0) {
					for (int i = 0; i < 4; i++) {
						if (ptr->getData(i)){
							int	output = ptr->getData(i);
							if (output != -1) {
								cout << output << " ";
							}
						}
					}
					return;
				}
				for (int i = 0; i < 5; i++) {
					if (ptr->getLink(i) != NULL) {
						bfprintLevel(ptr->getLink(i), level - 1);
					}
				}
			}
		}
		int getDepth(BNode* ptr){
			if (ptr == NULL){return 0;}
			else {
			int depth[5] = {0}; 
				for (int i = 0; i < 5; i++) {
					if (ptr->getLink(i) != NULL) {
						depth[i] = getDepth(ptr->getLink(i));
					}
				}
				int gDepth = 0;
				for (int i = 0; i < 5; i++) {
					if (gDepth < depth[i]) gDepth = depth[i];
				}
				return gDepth + 1;
			}
		}
};

int main(){
	OurTree obj;
	/*
	for (int i=0; i<15; i++){
		obj.addElement(rand()%400 +10);
	}
	*/
	obj.addElement(100);
	obj.addElement(150);
	obj.addElement(25);
	obj.addElement(120);
	obj.addElement(130);
	obj.addElement(50);
	obj.addElement(170);
	obj.addElement(200);
	obj.addElement(35);
	obj.dfprint(); //25 35 50 100 120 130 150 170 200
	obj.bfprint(); //100 25 150 50 120 170 35 130 200
	cout<<"Enter an element you want to search for: ";
	int key;
	cin>>key;
	BNode* ptr=obj.search(key, obj.getRoot());
	int size;
	if (ptr!=NULL){
		size=(*ptr).getSize();
		for (int j=0; j<size; j++){
			cout<<ptr->getData(j)<<"\t";
		}
		cout<<endl;
	}else{
		cout<<"The element is not in the tree"<<endl;
	}
	return 0;
}

