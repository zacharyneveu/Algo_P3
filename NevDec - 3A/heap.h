#ifndef HEAP_H
#define HEAP_H

///Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Definitions for the heap template class which stores data
//in a vector and includes functions to build and maintain a maxHeap in the
//vector.  Additionally, this class contains a function to implement heapsort,
//returning the sorted vector.
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

    //int to store size of heap, which may be different than size of vector
    int heapsize;

    //returns parent of object at index passed
    int parent(const int &index);

    //returns left child of object at index passed
    int left(const int &index);

    //returns right child of object at index passed
    int right(const int &index);

    //maxHeapify ensures that the maxHeap property is upheld at the node
    //specified by the index passed
    void maxHeapify(const int &index);

public:
    //returns item at index passed
    T getItem(const int &index);

    //copies given vector into the heap
    void initializeMaxHeap(const vector<T> &dictionary);

    //arranges vector to meet maxHeap property
    void buildMaxHeap();

    //maxHeapSort empties the heap into a sorted vector which it returns
    vector<T> maxHeapSort();

    //overloaded << operator to print contents of heap while debugging
    friend ostream& operator<<(ostream& ostr, heap toPrint)
    {
        int max = toPrint.heapsize;

        for (int i = 0; i < max; i++)
        {
            ostr << "Heap Node " << i << ": " << toPrint.getItem(i) << endl;
        }

        return ostr;
    }
};

#endif
