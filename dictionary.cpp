
//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Implementations of member functions of the dictionary
//class as defined in dictionary.h
//

//Includes
#include<iostream>
#include<string>
#include<vector>
#include"dictionary.h"

//Standard Name Space
using namespace std; //standard name space

ostream& operator<< (ostream& ostr, const dictionary& dictionary)
{
	//iterate over all elements in dictionary
	for (int i=0; i<dictionary.dictionary.size(); i++)
	{
		//print the word in the dictionary followed by a new line
		ostr << dictionary.dictionary.at(i) << endl;
	}
	//return the ostream object for multiple uses in a line
	return ostr;
}
