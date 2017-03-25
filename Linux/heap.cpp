//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Implementations for the functions used by the heap class.
//This class builds and maintains a MaxHeap used to sort the stored elements.
//

//Includes
#include"heap.h"	//declarations of all functions in this file
#include<vector>	//class uses vector for implementation

template<class T>

//returns parent of object at index passed
T heap::parent(int index)
{
	//parent stored at floor of index/2
	return heapvector[(index/2)];
}

//returns left child of object at index passed
T heap::left(int index)
{
	//left child stored at 2*parent
	return heapvector[(index*2)];
}

//returns right child of object at index passed
T right(int index)
{
	//right child stored at 2*parent+1
	return heapvector[(index*2+1)]
}


//returns item at index passed
T getItem(int index)
{
	return heapvector[index];
}

//copies given vector into the heap
void initializeMaxHeap(vector<T> data)
{
	heapvector = data;
}


//arranges array to meet maxHeap property
void buildMaxHeap()
{
	for (int i=data.size()/2; i>0; i--)
	{
		maxHeapify(i);
	}
}


//maxHeapify ensures that the maxHeap property is upheld at the node
//specified by the index passed
void maxHeapify(int index)
{
	string l = left(index);
	string r = right(index);
	string temp;
	if(l<=(data.size()-1) && data[index]>l)
		largest = l;
	else
		largest = i;
	if(r<= (data.size()-1) && data[index]>r)
		largest = r;
	if(largest != i)
	{
		//swap data[i] and data[largest]
		temp = data[i];
		data[i]=data[largest];
		data[largest] = temp;
		maxHeapify(i);
	}
}

