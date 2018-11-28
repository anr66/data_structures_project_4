// Alycia Riese
// buildMaze.cpp

// C++ includes
#include <iostream>
#include <string>
#include <limits>
#include <ctime>

// my includes
#include "mazeCell.h"
#include "maze.h"
#include "DisjSets.h"

// using statements
using std::cin;
using std::cout;
using std::numeric_limits;
using std::streamsize;
using std::string;

// function prototypes
void twoRandom(int &n1, int &n2, int maxN);


// main function
int main()
{
    srand(time(NULL));

    int rows = 0;
    int columns = 0;
    string see_iterations;

    cout << "Please enter number of rows greater than 1:\n";
    cin >> rows;

    // Check to see if user entered an integer
    while (!cin.good() || rows < 1)
    {
        // Clear the buffer
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        // Try again
        cout << "Error: Input is invalid, try again\n";
        cin >> rows;
    }

    cout << "Please enter number of columns greater than 1:\n";
    cin >> columns;

    // Check to see if user entered and integer
    while (!cin.good() || columns < 1)
    {
        // Clear the buffer
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        // Try again
        cout << "Error: Input is invalid, try again\n";
        cin >> columns;
    }

    cout << "Would you like to see each iteration of the maze? y or n\n";
    cin >> see_iterations;

    // Check to see if user entered valid input
    while (!cin.good() || (see_iterations.compare("y") != 0 && see_iterations.compare("n") != 0))
    {
        // Clear the buffer
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        // Try again
        cout << "Error: Input is invalid, please enter either 'y' or 'n'\n";
        cin >> see_iterations;
    }
    
    maze maze1(rows, columns);

    maze1.printMaze();


    return 0;
}


// generates two different random numbers in range of maxN and sets them to n1 and n2
void twoRandom(int &n1, int &n2, int maxN)
{
    n1 = rand() % (maxN + 1);
    n2 = rand() % (maxN + 1);
}
