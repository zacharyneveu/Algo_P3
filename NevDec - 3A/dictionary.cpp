
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
void dictionary::slectionSort() {
	int dictLength = dict.size();
	string temp;
	for (int i = 0; i < dictLength - 1; i++) {
		for (int j = i + 1; j < dictLength; j++)

			if (dict[i].compare(dict[j]) >= 0)
			{
				temp = dict[i];
				dict[i] = dict[j];
				dict[j] = temp;
			}
	}
	return;
}

//lookup function uses binary search to determine if a word is in the
//dictionary, using binary search
bool dictionary::binarySearch(string query) {
	int low = 0,             // First array element
		high = dict.size() - 1,       // Last array element
		middle;
	while (low <= high)
	{
		middle = (low + high) / 2;     // Calculate mid point
		if (dict[middle].compare(query) == 0)      // If value is found at mid
		{
			return true;
		}
		else if (dict[middle].compare(query) > 0)  // If value is in lower half
			high = middle - 1;
		else
			low = middle + 1;           // If value is in upper half
	}
	return false;
}

//Overloaded << overator for printing
ostream& operator<< (ostream& ostr, const dictionary& dictionary)
{
	//iterate over all elements in dictionary
	for (int i = 0; i < dictionary.dict.size(); i++)
	{
		//print the word in the dictionary followed by a new line
		ostr << dictionary.dict.at(i) << endl;
	}
	//return the ostream object for multiple uses in a line
	return ostr;
}
