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
bool isConnected(int n1, int n2, DisjSets &ds);

// main function
int main()
{
    //srand(time(NULL));

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

    int last_cell = (maze1.getCol() * maze1.getRow()) - 1;

    DisjSets ds(last_cell + 1);

    while(!isConnected(0, last_cell, ds))
    {
        // get two random ints with max as the last cell
        int rand1;
        int rand2;
        twoRandom(rand1, rand2, last_cell);

        // if the ints are not connected and they are neighbors, smash wall
        if (!isConnected(rand1, rand2, ds) && maze1.neighbors(rand1, rand2))
        {
            maze1.smashWall(rand1, rand2);
            ds.unionSets(ds.find(rand1), ds.find(rand2));

            // if the user wants to see the iterations, print out maze
            if (see_iterations == "y")
            {
                cout << "Neighbors " << rand1 << ", " << rand2 << " wall smashed below\n";
                maze1.printMaze(); 
            }
        }
    }

    if (see_iterations != "y")
    {
        maze1.printMaze();
    }

    return 0;
}


// generates two different random numbers in range of maxN and sets them to n1 and n2
void twoRandom(int &n1, int &n2, int maxN)
{
    n1 = rand() % (maxN + 1);
    n2 = rand() % (maxN + 1);
}

bool isConnected(int n1, int n2, DisjSets &ds)
{
    const int f1 = ds.find(n1);
    const int f2 = ds.find(n2);
    
    if (f1 == f2)
    {
        return true;
    }

    else
    {
        return false;
    }
}
