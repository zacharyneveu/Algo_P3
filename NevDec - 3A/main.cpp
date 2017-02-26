
//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Main function for the word search algorithm containing
//global functions findMatches() and search()
//

//Includes
#include<iostream>
#include<vector>
#include"d_matrix.h"
#include<string>
#include"grid.h"
#include"dictionary.h"

//Standard Name Space
using namespace std; //standard name space
vector<string> search(dictionary list, grid matrix);
void findMatches(dictionary list, grid matrix);

//Main function
int main()
{
	//dictionary d;
	//d.read("Dictionary.txt");
	grid g("input15.txt");
	cout<<g<<endl;
	//get grid file, find words, find matches and print them
	//findMatches();
	system("pause");
	return 0;
}


//TODO: What do search and findMatches do? Current understanding: search finds
//all words in square, findMatches calls search and prints out the words which
//are matches.  But why is findMatches passed the grid and dictionary then??



//the search function searches the grid and finds all words in the grid
vector<string> search(dictionary list, grid matrix)
{
	string currWord;
	vector<string> allWords;
	int modx = 0;
	int mody = 0;
	int rows = matrix.getGrid().rows();
	int cols = matrix.getGrid().cols();
	for (int row = 0; row<rows; row++)
	{
		for (int col = 0; col<cols; col++)
		{
			for (int length = 5; length<cols; length++)
			{
				for (int k = 0; k<length; k++)
				{
					currWord = "";	//Reset currWord each time
					for (int direction = 0; direction<8; direction++)
					{
						switch (direction)
						{
						case 0:		//Right
							modx = (col + k) % cols;
							mody = row;
						case 1:		//up right diagonal
							modx = (col + k) % cols;
							mody = (row + k) % rows;
						case 2:		//up
							modx = col;
							mody = (row + k) % rows;
						case 3:		//up left diagonal
							modx = (col - k) % cols;
							mody = (row + k) % rows;
						case 4:		//left
							modx = (col - k) % cols;
							mody = row;
						case 5:		//left down diagonal
							modx = (col - k) % cols;
							mody = (row - k) % rows;
						case 6:		//down
							modx = col;
							mody = (row - k) % rows;
						case 7:		//down right diagonal
							modx = (col + k) % cols;
							mody = (row - k) % rows;
						}
						currWord += matrix.getGrid()[mody][modx];
						allWords.push_back(currWord);
					}//end direction loop
				}//end k loop
			}//end length loop
		}//End columns loop
	}//End rows loop
	return allWords;
}//End function

//findMatches function uses the search function to match words in the dictionary
//with words found in the grid and prints all found matches
void findMatches(dictionary list, grid matrix)
{
	vector<string> gridWords = search(list, matrix);
	list.selectionSort();
	int found = gridWords.size();
	for (int i=0; i<found; i++)
	{
		if (list.binarySearch(gridWords.at(i)))
		{
			cout<<gridWords.at(i)<<endl;
		}
	}
}


