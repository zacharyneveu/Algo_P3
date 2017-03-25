//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Main function for the word search algorithm containing
//global functions findMatches(), search(), and their respective supporting
//functions.
//

//Includes
#include<iostream>		//standard i/o
#include"d_matrix.h"	//matrix class for grid
#include<string>		//basic c++ strings
#include"grid.h"		//grid class for storing wordsearch grid
#include"dictionary.h"	//dictionary class to store dictionary
#include<time.h>		//used to measure runtimes

#define MINLENGTH 5 //Minimum length of words

using namespace std;  //standard name space

//prototypes
void findMatches(const dictionary &list, const grid &matrix);
void search();
void searchGrid(const dictionary &d, const grid &matrix, int row, int col,
                int modx, int mody);
int shift(const int &base, const int &shift, const int &maxSize);

//Main function
//TODO: Remove clocks, those are there to graph runtimes
int main()
{
    search();	//initializes dictionary, asks for grid name and solves

    //system pause to keep visual studio terminal open
    system("pause");
    return 0;
}//end main function


//the search function searches the grid and finds all words in the grid
void findMatches(const dictionary &d, const grid &matrix)
{
    string currWord;
    int rows = matrix.getGrid().rows();
    int cols = matrix.getGrid().cols();

    //for each grid square
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            //search the current grid square in all 8 directions
            searchGrid(d, matrix, row, col, 1, 0);
            searchGrid(d, matrix, row, col, 1, 1);
            searchGrid(d, matrix, row, col, -1, 0);
            searchGrid(d, matrix, row, col, -1, -1);
            searchGrid(d, matrix, row, col, 0, 1);
            searchGrid(d, matrix, row, col, 0, -1);
            searchGrid(d, matrix, row, col, 1, -1);
            searchGrid(d, matrix, row, col, -1, 1);
        }//end column loop
    }//end row loop
}//End function

//findMatches function uses the search function to match words in the dictionary
//with words found in the grid and prints all found matches
void search()
{
    string dictionaryString = "dictionary.txt"; //dictionary to use

    //inform user of dictionary that will be used.
    cout << "Currently using dictionary: " << dictionaryString << endl;

    //use hard-coded dictionary
    dictionary d(dictionaryString);

    //clocks used to measure runtime of sort
    clock_t t1, t2;

    bool incheck = false; //checks if valid input is entered

    while (incheck == false)
    {
        cout << "Enter 0 for selection sort, 1 for quicksort, or 2 for heapsort: ";
        int select = 3; // any number not 0, 1, or 2
        cin >> select;

        //clocks used to measure runtime
        t1 = clock(); //start clock after input received

        //maxindex used to start quicksort at the right place
        int maxindex = d.getDictionary().size() - 1;

        //switch picks which type of sort user would like
        switch (select)
        {
        case 0:
            d.selectionSort();
            incheck = true;
            break;

        case 1:
            d.quicksort(0, maxindex);
            incheck = true;
            break;

        case 2:
            d.heapsort();
            incheck = true;
            break;

        default:
            cout << "Invalid input" << endl;
        }
    }


    //clocks used to measure runtime of sort
    t2 = clock();
    float diff((float)t2 - (float)t1);
    float seconds = diff / CLOCKS_PER_SEC;


    cout << "Dictionary sorted!\n\n";
    //cout<<d<<endl;

    cout << "Sorting Runtime: " << seconds << endl;

    //Get grid name from user
    string gridName;
    cout << "Enter the file name of the word grid: ";
    cin >> gridName;

    //read grid from file
    grid g(gridName);

    //search the grid for matches
    findMatches(d, g);

}//End function

//searches an x,y position in the grid (row, col) in a given direction, given
//by modx, mody will create a query string and search each against the
//dictionary until it wraps around, or the query substring is not found
//in the dictionary.
void searchGrid(const dictionary &d, const grid &matrix, int row, int col,
                int modx, int mody)
{
    string query = "";
    int index;
    const int initialRow = row;
    const int initialCol = col;
    int size = matrix.getGrid().rows();

    //build the minimum size word
    while (query.length() < MINLENGTH)
    {
        query += matrix.getGrid()[row][col];
        row = shift(row, modx, size);
        col = shift(col, mody, size);
    }

    //while the query length is less than the maximum query size
    while (query.length() <= size)
    {
        //do the binary search and switch over the enum result
        switch (d.binarySearch(query, index))
        {
        //If found, print out the word and information.
        case FOUND:
            printf("Word: %s Row: %d Col: %d Index: %d\n",
                   query.c_str(), initialRow, initialCol, index);

        //fall through
        //If found or not found, add the next letter to the query
        case NOT_FOUND:
            query += matrix.getGrid()[row][col];
            row = shift(row, modx, size);
            col = shift(col, mody, size);
            break;

        //the query string is not a substring of any item in the dictionary,
        //end search in this direction.
        case NO_SUBSTRING:
            return;

        default:
            //cant reach
            return;
        }//end switch statement
    }//end while loop for size

    return;
}//end searchGrid() function

//shifts the row or column by a factor, if it goes above the maxSize or below
//zero shift accordingly. Does not use the mod operator (slightly faster)
int shift(const int &base, const int &shift, const int &maxSize)
{
    //shift the base number
    int result = base + shift;

    //if it falls out of the array range, loop around to other side of grid
    if (result < 0)
    {
        result += maxSize;
    }
    else if (result == maxSize)
    {
        result -= maxSize;
    }

    return result;
}//end shift() function
