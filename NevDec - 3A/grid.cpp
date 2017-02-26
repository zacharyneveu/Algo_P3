
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
#include"d_matrix.h"

//Standard Name Space
using namespace std; //standard name space

matrix<string> grid::getGrid()
{
	return letterGrid;
}

grid::grid(string filepath)
{
	int gridSize;
	ifstream fin;
	fin.open(filepath.c_str());
	if(!fin)
	{
		cout<<"Sorry File Could Not Be Opened"<<endl;
	}
	string x = "";
	for (int i=0; i<2; i++)
	{
		fin>>gridSize;
	}
	for (int j=0; j<gridSize; j++)
	{
		for (int k=0; k<gridSize; k++)
		{
			fin>>x;
			letterGrid[j][k]=x;
		}
	}
	fin.close();
}

ostream& operator<< (ostream& ostr, grid& matrix)
{
	for (int i=0; i<matrix.getGrid().rows(); i++)
	{
		for (int j=0; j<matrix.getGrid().cols(); j++)
		{
			ostr<<matrix.getGrid()[i][j]<<" ";
		}
		ostr<<endl;
	}
	return ostr;
}
