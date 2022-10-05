//***************************************************************************
//
//  queens.cpp
//  CSCI 241 Assignment 2
//
//  Created by Jacob Rudawski z1968579
//
//***************************************************************************

#include <iostream>

using namespace std;

#define N 8

class queen_solver
{
private:

    bool board[N][N] = {{false}};

public:

    queen_solver() = default;
    bool place_queens();
    bool place_queen_in_row(int);
    bool is_safe(int, int) const;
    void print_solution() const;
};


int main()
{
    queen_solver q;

    if (q.place_queens())
        q.print_solution();
    else
        cout << "Error - no solution found\n";

    return 0;
}

bool queen_solver::place_queens()
{
    return place_queen_in_row(0);
}

bool queen_solver::place_queen_in_row(int row)
{
    // Base case #1 - All queens have been placed successfully.
    if (row >= 8)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (is_safe(row, col))
        {
            // Put a queen at board[row][col]
            board[row][col] = true;

            if (place_queen_in_row(row + 1))
                return true;

            // Remove the queen at board[row][col]
            board[row][col] = false;
        }
    }
    
    // Base case #3 - We were not able to place a queen anywhere in 
    // this row.
    return false;
}

bool queen_solver::is_safe(int row, int col) const
{
    // Check the rows above this column. col stays the same, row varies
    // from row - 1 down to 0.
    int i;
    int j;
    for (i = row - 1; i >= 0; i--)
    {
	    if (board[i][col])
	    {
		    return false;
	    }
    }

    // Check the left diagonal above this row. col varies from col - 1
    // down to 0, row varies from row - 1 down to 0.
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0 ; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // Check the right diagonal above this row. col varies from col + 1
    // up to 7, row varies from row - 1 down to 0.
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if(board[i][j])
        {
            return false;
        }
    }
    return true;
}

void queen_solver::print_solution() const // prints solution
{
    for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j])
			{
				cout << "1 ";
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << endl;
	}
}