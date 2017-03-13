Zachary Neveu | neveu.z@husky.neu.edu
Jake Dec | dec.j@husky.neu.edu

ABOUT:
This project implements a word search algorithm which will search through a grid
of n by n letters in a file looking through a dictionary of k words to find
matches in all 8 directions in all positions of the grid.  Words can wrap around
edges, and must be between 5 characters long and the size of the grid.

USAGE:
Build and run this program from the visual studio project.  When prompted, enter
the name of a grid file located in the same directory as the source files.  The
program prints each word found, its starting column and row, and its index in
the dictionary.

ALGORITHM DETAILS:
The algorithm used begins at each square of the grid.  It begins by searching in
all eight directions, building strings of the minimum word length (5 chars).
Each of these strings is looked up in the dictionary.  If the string is a
substring of a word or a complete word, one character is added to the string and
the search is repeated.  Every time a string is found to be a full word, the
word is printed to the console.  If the string is not a substring of anything,
no subsequent searches are made to save time.  The length of strings can be
extended until the string is equal to the size of the grid.

BINARY
