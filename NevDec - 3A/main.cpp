
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

#define MINLENGTH 2 //Minimum length of words

//Standard Name Space
using namespace std; //standard name space
vector<string> search(dictionary list, grid matrix);
void findMatches(dictionary list, grid matrix);
int mod(int a, int b);

//Main function
int main()
{
	dictionary d;
	d.read("testDictionary.txt");
	cout<<d<<endl;

	grid g("testGrid.txt");
	cout<<g<<endl;

	vector<string> results;
	//search dictionary and grid for matches
	results = search(d,g);
	for (int i=0; i<results.size(); i++)
	{
		cout<<results.at(i)<<endl;
	}
	system("pause");
	return 0;
}


//the search function searches the grid and finds all words in the grid
vector<string> search(dictionary list, grid matrix)
{
	string currWord;
	vector<string> allWords;
	int modx = 0;
	int mody = 0;
	int rows = matrix.getGrid().rows();
	int cols = matrix.getGrid().cols();
	int counter = 0;
	for (int row = 0; row<rows; row++)
	{
		for (int col = 0; col<cols; col++)
		{
			for (int length = MINLENGTH; length<=cols; length++)
			{
				for (int direction = 0; direction<8; direction++)
				{
					currWord = "";	//Reset currWord each time
					for (int k = 0; k<length; k++)
					{
						switch (direction)
						{
						case 0:		//Right
							modx = mod((col + k), cols);
							mody = row;
							break;
						case 1:		//up right diagonal
							modx = mod((col + k), cols);
							mody = mod((row + k), rows);
							break;
						case 2:		//up
							modx = col;
							mody = mod((row + k), rows);
							break;
						case 3:		//up left diagonal
							modx = mod((col - k), cols);
							mody = mod((row + k), rows);
							break;
						case 4:		//left
							modx = mod((col - k), cols);
							mody = row;
							break;
						case 5:		//left down diagonal
							modx = mod((col - k), cols);
							mody = mod((row - k), rows);
							break;
						case 6:		//down
							modx = col;
							mody = mod((row - k), rows);
							break;
						case 7:		//down right diagonal
							modx = mod((col + k), cols);
							mody = mod((row - k), rows);
							break;
						}
						currWord += matrix.getGrid()[mody][modx];
					}//end k loop
					if (list.binarySearch(currWord))
					{
						allWords.push_back(currWord);
						cout<<"Found: "<<currWord<<endl;
						cout<<"Direction "<<direction<<endl;
						cout<<"Col "<<col<<endl;
						cout<<"Row "<<row<<endl;
						cout<<"Length "<<length<<endl;
					}
					else
					{
						continue;
					}
					//cout<<"k = "<<k<<endl;
					//cout<<"Direction = "<<direction<<endl;
				}//end direction loop
				cout<<"Length = "<<length<<endl;
			}//end length loop
			cout<<"Col = "<<col<<endl;
		}//End columns loop
		cout<<"Row = "<<row<<endl;
	}//End rows loop
	return allWords;
}//End function

int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

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


