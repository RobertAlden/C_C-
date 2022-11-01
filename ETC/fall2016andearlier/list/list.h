const int LIMIT = 100;		// Maximum number of elements allowed for a list
class List
{
public:
 	List();		
 	// Default constructor; creates an empty list.

 	List(int length, int x);
 	// Explicit constructor; creates a list having the given length with all elements set to x.
 	void print();
 	// Prints the list surrounded by brackets. For example, [45 19 30 52], or [ ].
 	void insert(int element);
 	// Inserts the given element at the end of the list.
	void clear();
	// Makes the list empty.
	int first();
	// Returns the first element of the list. Assumes that the list is not empty.
	int last();
	// Returns the last element of the list. Assumes that the list is not empty.
 	int max();
 	// Returns the largest element in the list.
 	int min();
 	// Returns the smallest element in the list.
	int sum();
 	// Returns the sum of all elements of the list.
 	double average();
 	// Returns the average of all elements of the list.	 
 	bool empty();
 	// Returns true if the list is empty, and false otherwise.
 	bool isElement(int x);
 	// Returns true if x is an element of the list, and false otherwise.
	void reverse();
	// Reversed all elements of the list.
	void sort();
	// Sorts the list into increasing order.
private:
 	int array[LIMIT];		// Will hold all elements of the list.
 	int size;			// Number of elements currently in the list.
};

