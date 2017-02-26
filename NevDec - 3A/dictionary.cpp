
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
	while (iFile >> x) {
		dict.push_back(x);
		count++;
	}
	printf("Read %d items in dictionary", count);
}

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
