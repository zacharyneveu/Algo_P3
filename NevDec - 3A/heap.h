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
    }//end << operator overload
};//end class definition

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
}//end function


//arranges array to meet maxHeap property
template<class T>
void heap<T>::buildMaxHeap()
{

    for (int i = heapsize / 2; i > 0; i--)
    {
        maxHeapify(i);
    }
}//end function


//maxHeapify ensures that the maxHeap property is upheld at the node
//specified by the index passed
template<class T>
void heap<T>::maxHeapify(const int &index)
{
    int l = left(index);
    int r = right(index);
    int largest = 0;
    string temp;

    //if left child in range and greater than parent
    if (l <= heapsize && data[index] < data[l])
    {
        largest = l;
    }
    else
    {
        largest = index;
    }

    //if right child in range and bigger than parent and left child
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

        //recursively call until smallest data gets to bottom
        this->maxHeapify(largest);
    }//end if
}//end function

template<class T>
vector<T> heap<T>::maxHeapSort()
{
    string temp;

    //iterate from leaves to top level of heap.
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
    }//end iteration over sizeof heap

    return data;
}//end heapsort function


#endif
