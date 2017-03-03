
///Zachary Neveu | neveu.z@husky.neu.edu
//Jake Dec | dec.j@husky.neu.edu
//
//This file includes: Definition of the grid class used to read letters from a
//word search grid and store them in a matrix

//Includes
#include<vector>
#include<string>
#include<iostream>

using namespace std;


class grid
{
private:
	vector<vector<char>> grid;
public:
	//Constructor takes file name and extracts contents to matrix
	grid(string filepath);
};
