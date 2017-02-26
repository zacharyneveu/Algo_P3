
//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Implementations for the member functions of the grid class
//as defined in grid.h
//

//Includes
#include<vector>
#include<string>
#include<iostream>
#include"grid.h"
#include<fstream> //included for file operations

//Standard Name Space
using namespace std; //standard name space

grid::grid(string filepath)
{
	ifstream fin;
	fin.open(filepath.c_str());
	if(!fin)
	{
		cout<<"Sorry, File not Opened"<<endl;
	}

	char x;
	int outsideCtr=0;
	int insideCtr=0;	//counters
	while(fin>>x)
	{
		while(x!='\n')//While not at end of line
		{
			lettergrid[outsideCtr][insideCtr]=x;
			insideCtr++;
		}
		outsideCtr++;
	}
	fin.close();
}
