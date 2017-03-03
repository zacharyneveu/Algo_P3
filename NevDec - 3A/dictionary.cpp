
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

vector<string> dictionary::getDictionary() const{
	return dict;
}

void dictionary::read(string input) {
	ifstream iFile(input);
	string x;
	int count;	
	
	if (iFile) {
		string x;
		int count = 0;
		while (iFile >> x) {
			dict.push_back(x);
			count++;
		}
		printf("Read %d items in dictionary.\n", count);
	}
	else {
		printf("Could not open file!\n");
	}
}

//Sort function sorts words in dictionary vector using selectionsort
void dictionary::selectionSort() {
	int dictLength = dict.size();
	int min;
	string temp;
	for (int i = 0; i < dictLength - 1; i++)
	{
		if (i % 50 == 0) {
			printf("%d items sorted\n", i);
		}
		min = i;//set pos_min to the current index of array
		for (int j = i + 1; j < dictLength; j++)
		{

			if (dict[j] < dict[min])
				min = j;
			//pos_min will keep track of the index that min is in, this is needed when a swap happens
		}

		//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
		if (min != i)
		{
			temp = dict[i];
			dict[i] = dict[min];
			dict[min] = temp;
		}
	}
}

//lookup function uses binary search to determine if a word is in the
//dictionary, using binary search
int dictionary::binarySearch(string query) {
	int low = 0,             // First array element
		high = dict.size() - 1,       // Last array element
		middle;
	while (low <= high)
	{
		middle = (low + high) / 2;     // Calculate mid point
		if (dict[middle].compare(query) == 0)      // If value is found at mid
		{
			return middle;
		}
		else if (dict[middle].compare(query) > 0)  // If value is in lower half
			high = middle - 1;
		else
			low = middle + 1;           // If value is in upper half
	}
	return -1;
}

//lookup function uses binary search to determine if a word is in the
//dictionary, using binary search
Result dictionary::improvedBinarySearch(string query, int &index) {
	int low = 0,             // First array element
		high = dict.size() - 1,       // Last array element
		middle;
	while (low < high)
	{
		middle = (low + high) / 2;     // Calculate mid point
		if (dict[middle].compare(query) == 0)      // If value is found at mid
		{
			index = middle;
			return FOUND;
		}
		else if (dict[middle].compare(query) > 0)  // If value is in lower half
			high = middle - 1;
		else
			low = middle + 1;           // If value is in upper half
	} //end while

	//If the string has not been found and we are on the file compare.
	//DUBUG
	cout << dict[middle - 1] << endl;
	cout << dict[middle] << endl;
	cout << dict[middle + 1] << endl;

	//compare the dictionary entry of length query to see if query is a substring of the word
	if (dict[middle].substr(0, query.length() - 1).compare(query) == 0 ||
		dict[middle + 1].substr(0, query.length() - 1).compare(query) == 0 ||
		dict[middle - 1].substr(0, query.length() - 1).compare(query) == 0 ) {
		cout << "Not Found\n";
		//set the index to less than 1
		index = -2;
		return NOT_FOUND;
	}

	//Else the substring of the query does not exist in the dictionary
	return NO_SUBSTRING;
	cout << "No substring found, short circuiting\n";
}

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
}
