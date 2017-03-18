
//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Implementations for all functions declared in the heap
//class located in heap.h
//

//Includes
#include<iostream>
#include<vector>
#include"heap.h"

//Standard Name Space
using namespace std; //standard name space

//returns parent of object at index passed
template<class T>
int heap<T>::parent(const int& index)
{
    //parent stored at floor of index/2
    return (index / 2);
}

//returns left child of object at index passed
template<class T>
int heap<T>::left(const int &index)
{
    //left child stored at 2*parent
    return (index * 2);
}

//returns right child of object at index passed
template<class T>
int heap<T>::right(const int &index)
{
    //right child stored at 2*parent+1
    return (index * 2 + 1);
}


//returns item at index passed
template<class T>
T heap<T>::getItem(const int &index)
{
    return data[index];
}

//copies given vector into the heap
template<class T>
void heap<T>::initializeMaxHeap(const vector<T> &dictionary)
{

    data = dictionary;;
    data.push_back(data[0]);
    data[0] = " ";

    //initialize heapsize
    this->heapsize = data.size() - 1;
}


//arranges array to meet maxHeap property
template<class T>
void heap<T>::buildMaxHeap()
{

    for (int i = heapsize / 2; i > 0; i--)
    {
        maxHeapify(i);
    }
}


//maxHeapify ensures that the maxHeap property is upheld at the node
//specified by the index passed
template<class T>
void heap<T>::maxHeapify(const int &index)
{
    int l = left(index);
    int r = right(index);
    int largest = 0;
    string temp;

    if (l <= heapsize && data[index] < data[l])
    {
        largest = l;
    }
    else
    {
        largest = index;
    }

    if (r <= heapsize && data[largest] < data[r])
    {
        largest = r;
    }

    //cout<<"largest: "<<data[largest]<<endl;
    if (largest != index)
    {
        //swap data[i] and data[largest];
        //cout<<"swapping: "<<data[index]<<"<->"<<data[largest]<<endl;
        temp = data[index];
        data[index] = data[largest];
        data[largest] = temp;
        this->maxHeapify(largest);
    }
}

template<class T>
vector<T> heap<T>::maxHeapSort()
{
    string temp;

    for (int i = heapsize; i > 1; i--)
    {

        //swap data[i] and data [1] (first and last elements)
        temp = data[i];
        data[i] = data[1];
        data[1] = temp;

        //decrement heap size to exclude sorted value
        heapsize--;

        //reorganize heap with new top value
        maxHeapify(1);
    }

    return data;
}


