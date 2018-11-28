// Alycia Riese
// maze.cpp

// C++ includes
#include <iostream>
#include <cmath>
#include <vector>

// my includes
#include "maze.h"
#include "mazeCell.h"

//using statements
using std::cout;
using std::vector;


// constructor
maze::maze(int r, int c)
{
    row = r;
    col = c;

    // gets total number of cells in the maze
    int num_cells = row * col;

    for (int p = 0; p < 100; p++)
    {
        cout << p << " ";
    }

    for(int i = 0; i < num_cells; i++)
    {
        //cout << i;
        mazeCell cell;

        // this is first cell, we dont want to print left or top for first cell
        if (i = 0)
        {
            cell.setLeft(false);
            cell.setTop(false);
        }

        // this is last cell, we dont want to print right or bot for last cell
        if (i == (num_cells - 1))
        {
            cell.setRight(false);
            cell.setBot(false);
        }

        // put cell onto the maze
        theMaze.push_back(cell);
        //cout << i;
    }

}

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const
{
    bool neighbors;

    // if the two cells are in the same column
    if (getCellCol(cell) == getCellCol(neigh))
    {
        // determine the difference between the rows
        int row_diff = abs(getCellRow(cell) - getCellRow(neigh));

        // if the difference is 1, this means they are right next to each other
        if (row_diff == 1)
        {
            neighbors = true;
        }

        else
        {
            neighbors = false;
        }
    }

    // if the two cells are in the same row
    if (getCellRow(cell) == getCellRow(neigh))
    {
        // determine the difference between the columns
        int col_diff = abs(getCellCol(cell) - getCellCol(neigh));

        // if the difference is 1, this means they are right next to each other
        if (col_diff == 1)
        {
            neighbors = true;
        }

        else
        {
            neighbors = false;
        }
    }

    return neighbors;
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall (int cell, int neigh)
{
    // determine where the cell is
    int cell_col = getCellCol(cell);
    int cell_row = getCellRow(cell);

    // determine where the neigh is
    int neigh_col = getCellCol(neigh);
    int neigh_row = getCellRow(neigh);

    // get differences between columns and rows
    int col_diff = cell_col - neigh_col;
    int row_diff = cell_row - neigh_row;

    mazeCell &cell_cell = theMaze[cell];
    mazeCell &neigh_cell = theMaze[neigh];

    // the neighbor is to the left
    if (col_diff == 1 && row_diff == 0)
    {
        cell_cell.setLeft(false);
        neigh_cell.setRight(false);
    }

    // the neighbor is to the right
    if (col_diff == -1 && row_diff == 0)
    {
        cell_cell.setRight(false);
        neigh_cell.setLeft(false);
    }

    // the neighbor is above
    if (col_diff == 0 && row_diff == 1)
    {
        cell_cell.setTop(false);
        neigh_cell.setBot(false);
    }

    // the neighbor is below
    if (col_diff == 0 && row_diff == -1)
    {
        cell_cell.setBot(false);
        neigh_cell.setTop(false);
    }

}

//print the maze
void maze::printMaze()
{
    for(int i = 0; i < getCol(); i++)
    {
        if (i == 0)
        {
            cout << " ";
        }
        else
        {
            cout << "_";
        }
    }

    cout << "\n";

    int num_cells = getCol() * getRow();

    for (vector<mazeCell>::iterator iter = theMaze.begin(); iter != theMaze.end(); iter++)
    {
        int i = iter - theMaze.begin();
        mazeCell cell = *iter;

        // this is the right side
        if ((i + 1) % getCol() == 0)
        {
            if (cell.getLeft())
            {
                cout << "|";
            }
            else
            {
                cout << " ";
            }
            
            if (cell.getBot())
            {
                cout << "_";
            }
            else
            {
                cout << " ";
            }

            if (i == num_cells - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "|";
            }
            
            cout << "\n";
        }

        // its the left side
        else if (i % getCol() == 0)
        {
            if (i == 0)
            {
                cout << " ";
            }
            else
            {
                cout << "|";
            }

            if (cell.getBot())
            {
                cout << "_";
            }
            else
            {
                cout << " ";
            }
        }

        // middle cell
        else
        {
            if (cell.getLeft())
            {
                cout << "|";
            }
            else
            {
                cout << " ";
            }
            
            if (cell.getBot())
            {
                cout << "_";
            }
            else
            {
                cout << " ";
            }

        }
    }

    cout << "\n";
}
