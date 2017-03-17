
///Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Definition of the dictionary class used for reading a list
//of words from a dictionary file and storing them in a vector.
//

//Includes
#include<iostream>
#include<string>
#include<vector>
#include"heap.h"

//standard namespace
using namespace std;

typedef enum result
{
    FOUND, NOT_FOUND, NO_SUBSTRING
} Result;

class dictionary
{
private:
    vector<string> dict;

	//partition function used by quicksort to divide and conquer
	int partition(int left, int right);

	//swap function used by quicksort to swap positions of words
	void swap(int index1, int index2);

public:    //constructor
    dictionary() {}

    //constructor with a given dictionary file
    dictionary(string input) : dictionary()
    {
        read(input);
    }

    //read function reads from file into the dictionary vector
    void read(string filepath);

    //Sort function sorts words in dictionary vector using selectionsort
    void selectionSort();

	//Quicksort function sorts dictionary vector faster than selection sort did
	void quicksort(int left, int right);

	//Heapsort uses the heap class to sort dictionary vector quickly
	void heapsort();

    //lookup function uses binary search to determine if a word is in the
    //dictionary, using binary search
    Result binarySearch(const string &query, int &index) const;

    //overloaded << operator prints the word list
    friend ostream& operator<< (ostream& ostr, const dictionary &dictionary);

    //return the dictionary
    vector<string> getDictionary() const;
};
