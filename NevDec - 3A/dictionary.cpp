
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

//Standard Name Space
using namespace std; //standard name space

vector<string> dictionary::getDictionary() const
{
    return dict;
}

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
        printf("Could not open file!\n");
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
        if (i % 50 == 0)
        {
            printf("%d items sorted\n", i);
        }

        min = i;//set min to the current index of array

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

//improvedBinarySearch() uses binary search to determine if a word is in the
//dictionary, using binary search.
//
//This function contains a third option for when the query substring is not
//contained in the dictionary.
Result dictionary::improvedBinarySearch(const string &query, int &index) const
{
    int low = 0,             // First array element
        high = dict.size() - 1,       // Last array element
        middle;

    //while there are still terms to search for
    //(last element is handled differntly in this version)
    while (low < high)
    {
        middle = (low + high) / 2;     // Calculate mid point

        if (dict[middle].compare(query) == 0)      // If value is found at mid
        {
            index = middle;
            return FOUND;
        }
        else if (dict[middle].compare(query) > 0)  // If value is in lower half
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;    // If value is in upper half
        }
    } //end while(low<high)

    //do the final compare
    middle = (low + high) / 2;

    if (dict[middle].compare(query) == 0)      // If value is found at mid
    {
        index = middle;
        return FOUND;
    }

    //If the query was not found, iterate up the dictionary, and see if any
    //terms contain the substring of the query.
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
    //iterate over all elements in dictionary
    for (int i = 0; i < dictionary.getDictionary().size(); i++)
    {
        //print the word in the dictionary followed by a new line
        ostr << dictionary.getDictionary().at(i) << endl;
    }

    //return the ostream object for multiple uses in a line
    return ostr;
}//end overloaded << operator
