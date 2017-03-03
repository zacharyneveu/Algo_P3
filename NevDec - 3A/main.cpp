
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
void findMatches(dictionary list, grid matrix);
void search();
int mod(int a, int b);

//Main function
int main()
{


	search();
	system("pause");
	return 0;
}


//the search function searches the grid and finds all words in the grid
void findMatches(dictionary list, grid matrix)
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
			for (int direction = 0; direction<8; direction++)
			{
				for (int length = MINLENGTH; length<=cols; length++)
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

					//Debugging lines
					//cout<<"CurrWord: "<<currWord<<endl;
					//cout<<list.binarySearch(currWord)<<endl;

					int index = 0; //variable to be returned by binary search
					switch(list.improvedBinarySearch(currWord,index))
					{
						case FOUND:
							cout<<list.getDictionary()[index]<<" ";
							cout<<"col: "<<col<<" ";
							cout<<"row: "<<row<<" ";
							cout<<index<<" ";
							cout<<endl;
							break;
						case NOT_FOUND:
							continue;
							break;
						case NO_SUBSTRING:
							goto exit_length_loop;
							break;
					}

					//cout<<"k = "<<k<<endl;
					//cout<<"Direction = "<<direction<<endl;
				}//end length loop
				exit_length_loop: ;
				//cout<<"Length = "<<length<<endl;
			}//end direction loop
			//cout<<"Col = "<<col<<endl;
		}//End columns loop
		//cout<<"Row = "<<row<<endl;
	}//End rows loop
}//End function


//Simple mod function used to calculate modulus, not remainder
int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

//findMatches function uses the search function to match words in the dictionary
//with words found in the grid and prints all found matches
void search()
{
	//Get grid name from user
	string gridName;
	cout<<"Enter the file name of the word grid: ";
	cin>>gridName;
	grid g(gridName);
	//cout<<g<<endl;

	//usee hard-coded dictionary
	dictionary d;
	d.read("testDictionary.txt");
	//cout<<d<<endl;

	d.selectionSort();
	findMatches(d, g);
}//End function
