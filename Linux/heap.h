
///Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes:
//

#include<iostream>
#include<vector>

using namespace std;

template<class T>

class heap
{
private:
	//array data member to store heap
	vector<T> data;

	//returns parent of object at index passed
	T parent(int index);

	//returns left child of object at index passed
	T left(int index);

	//returns right child of object at index passed
	T right(int index);

	//returns item at index passed
	T getItem(int index);

	//maxHeapify ensures that the maxHeap property is upheld at the node
	//specified by the index passed
	void maxHeapify(int index);

public:
	//copies given vector into the heap
	void initializeMaxHeap(vector<T> data);

	//arranges vector to meet maxHeap property
	void buildMaxHeap();
};
