
//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Implementations of member functions of the dictionary
//class as defined in dictionary.h
//

//Includes
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"dictionary.h"
#include"heap.h"

using namespace std; //standard name space

//Returns the vector containing all the works in the dictionary
vector<string> dictionary::getDictionary() const
{
    return dict;
}

//Reads all values from a text file to populate a dictionary
void dictionary::read(string input)
{
    ifstream iFile(input);
    string x;

    //if the file is valid
    if (iFile)
    {
        string x;
        int count = 0;

        while (iFile >> x)
        {
            dict.push_back(x);
            count++;
        }

        printf("Read %d items in dictionary.\n", count);
    }//end ifile if
    else
    {
        printf("Could not open dictionary file, exiting...\n");
        system("pause");
        exit(1);
    }
}//end read function

//Sort function sorts words in dictionary vector using selectionsort
void dictionary::selectionSort()
{
    int dictLength = dict.size();
    int min;
    string temp;

    //For the dictionary length
    for (int i = 0; i < dictLength - 1; i++)
    {
        //set min to the current index of array
        min = i;

        //for all unsorted items
        for (int j = i + 1; j < dictLength; j++)
        {
            //If the current term is less than the new term,
            //Set the minimum
            if (dict[j] < dict[min])
            {
                min = j;
            }
        }

        //if min no longer equals i than a smaller value must have been found,
        //swap.
        if (min != i)
        {
            temp = dict[i];
            dict[i] = dict[min];
            dict[min] = temp;
        }
    }//end for loop over dictionary
}//end selection sort function

//Quicksort function sorts dictionary vector faster than selection sort did
void dictionary::quicksort(int left, int right)
{
    int s;

    //break recursion when left==right
    if (left < right)
    {
        //call partition to get pivot index
        s = partition(left, right);
        //call quicksort on low half
        quicksort(left, s - 1);
        //call quicksort on high half
        quicksort(s + 1, right);
    }//endif
}//end function

//partition function used by quicksort.  This function divides the dictionary
//into two parts: the left side is all smaller than a certain value, the right
//side is all bigger than a certain value.  The center item (pivot) has this
//exact value.  The function returns the index of the pivot.
int dictionary::partition(int left, int right)
{
    //start assuming pivot is left value
    int p = left;
    //store value of pivot so it doesn't have to be searched repeatedly
    string pival = dict[left];

    //iterate over all elements in section passed
    for (int i = left + 1; i <= right; i++)
    {
        if (dict[i] <= pival) //if dict[i] is smaller than left side (pivot)
        {
            p++; //increment p
            swap(i, p); //swap dict[i] and dict[p]
        }//end if
    }//end for

    swap(p, left); //swap final p with pivot

    return p; //index of pivot
}//end function

//Heapsort uses the heap class to sort dictionary vector quickly
void dictionary::heapsort()
{
    //construct a heap
    heap<string> sortingHeap;

    //initialize the heap with dictionary values
    sortingHeap.initializeMaxHeap(dict);

    //make heap meet maxHeap property
    sortingHeap.buildMaxHeap();

    //sort heap, and copy back into dictionary
    dict = sortingHeap.maxHeapSort();
}//end function


//simple swap function used by quicksort (partition)
void dictionary::swap(int index1, int index2)
{
    string temp = dict[index1];
    dict[index1] = dict[index2];
    dict[index2] = temp;
}

//improvedBinarySearch() uses binary search to determine if a word is in the
//dictionary, using binary search.
//
//This function contains a third option for when the query substring is not
//contained in the dictionary. This is accomplished by comparing the substring
//of the query to the dictionary words after the traditional binary search is
//complete. If there is a substring match with the beginning of the dictionary
//word, then it will return not found. If the substring of query is not found
//in the dictionary at all it will return that no substring is found, and that
//there is no likelihood that adding additional letters to query will return any dictionary matches.
Result dictionary::binarySearch(const string &query, int &index) const
{
    int low = 0,             // First array element
        high = dict.size() - 1,       // Last array element
        middle;

    //while there are still terms to search for
    //(last element is handled differntly in this version)
    while (low < high)
    {
        // Calculate mid point
        middle = (low + high) / 2;

        // If value is found at mid
        if (dict[middle].compare(query) == 0)
        {
            index = middle;
            return FOUND;
        }
        // If value is in lower half
        else if (dict[middle].compare(query) > 0)
        {
            high = middle - 1;
        }
        // If value is in upper half
        else
        {
            low = middle + 1;
        }
    } //end while(low<high)

    //do the final compare
    middle = (low + high) / 2;

    // If value is found at mid
    if (dict[middle].compare(query) == 0)
    {
        index = middle;
        return FOUND;
    }

    //If the query was not found, iterate up the dictionary, and see if any
    //terms contain the substring of the query. Until the query is greater than
    //dictionary entry
    do
    {
        //If a dictionary entry is found that starts with the query string
        if (dict[middle].substr(0, query.length()).compare(query) == 0)
        {
            //set the index to less than 1
            index = -1;
            return NOT_FOUND;
        }
        //If the dictionary runs out of items.
        else if (middle == dict.size() - 1)
        {
            index = -2;
            return NO_SUBSTRING;
        }

        //continue while the query registers less than the dictionary entry
    }
    while (dict[middle++].compare(query) < 0);

    //Else the substring of the query does not exist in the dictionary
    index = -2;
    return NO_SUBSTRING;
}//end improvedBinarySearch()

//Overloaded << operator for printing
ostream& operator<< (ostream& ostr, const dictionary& dictionary)
{
    int max = dictionary.getDictionary().size();

    //iterate over all elements in dictionary
    for (int i = 0; i < max; i++)
    {
        //print the word in the dictionary followed by a new line
        ostr << dictionary.getDictionary().at(i) << endl;
    }

    //return the ostream object for multiple uses in a line
    return ostr;
}//end overloaded << operator
