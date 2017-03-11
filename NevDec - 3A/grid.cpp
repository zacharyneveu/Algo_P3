
//Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Implementations for the member functions of the grid class
//as defined in grid.h
//

//Includes
#include<string>	//Included for string operations
#include<iostream>	//standard I/O
#include"grid.h" 	//corresponding header file
#include"d_matrix.h"//Included for matrix operations
#include<fstream> 	//Included for file operations

//Standard Name Space
using namespace std; //standard name space

matrix<string> grid::getGrid() const
{
    return letterGrid;
}

grid::grid(string filepath)
{
    int gridSize; //Stores n for nxn grid
    ifstream fin; //ifstream object declaration
    fin.open(filepath.c_str()); //open specified file

    if (!fin) //if file not opened
    {
        cout << "Sorry File Could Not Be Opened" << endl;
    }

    string x; //used to store string to be added to grid

    for (int i = 0; i < 2; i++)	//Iterates over first two dimensions in file
    {
        fin >> gridSize;
    }

    //resize letterGrid to size specified in file
    letterGrid.resize(gridSize, gridSize);

    //iterate over rows of grid
    for (int j = 0; j < gridSize; j++)
    {
        //iterate over columns of grid
        for (int k = 0; k < gridSize; k++)
        {
            //get file input into string x
            fin >> x;
            //add file input to grid
            letterGrid[j][k] = x;
        }
    }

    //close file before function ends
    fin.close();
}

ostream& operator<< (ostream& ostr, grid& matrix)
{
    string toPrint;	//Holds string to be printed

    //Iterates over all rows of grid
    for (int i = 0; i < matrix.getGrid().rows(); i++)
    {
        //iterates over columns of grid
        for (int j = 0; j < matrix.getGrid().cols(); j++)
        {
            toPrint = matrix.getGrid()[i][j];
            //adds current cell to ostr with formatting
            ostr << toPrint << " ";
        }

        ostr << endl;
    }

    //return ostr to end function
    return ostr;
}
