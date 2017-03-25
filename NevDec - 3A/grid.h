
///Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Definition of the grid class used to read letters from a
//word search grid and store them in a matrix

//Includes
#include<vector>
#include<string>
#include<iostream>
#include"d_matrix.h"
#include<fstream>

using namespace std;


class grid
{
private:
    matrix<string> letterGrid;
public:
    //Constructor takes file name and extracts contents to matrix
    grid(string filepath);

    //Function to return matrix out of grid object
    matrix<string> getGrid() const;

    //Overloaded << operator to test printing matrix
    friend ostream& operator<< (ostream& ostr, grid& matrix);
};
