
//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Main function for the word search algorithm containing
//global functions findMatches() and search()
//

//Includes
#include<iostream>
#include<vector>
#include<string>
#include"grid.h"
#include"dictionary.h"

//Standard Name Space
using namespace std; //standard name space

//Main function
int main()
{
	//Get name of grid file to read in and find all words
	search();
}

//the search function searches the grid and finds all words in the grid
vector<string> search(dictionary list, grid matrix)
{


}

//findMatches function uses the search function to match words in the dictionary
//with words found in the grid and prints all found matches
void findMatches(dictionary list, grid matrix)
{
	vector<string> gridWords = search(list, matrix);
	list.sort();
	int found = gridWords.size();
	for (int i=0; i<found; i++)
	{
		if (list.lookup(gridWords.at(i)))
		{
			cout<<gridWords.at(i)<<endl;
		}
	}
}


