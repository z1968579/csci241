//***************************************************************************
//
//  hanoi.cpp
//  CSCI 241 Assignment 2
//
//  Created by Jacob Rudawski z1968579
//
//***************************************************************************

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>


using namespace std;

void move (int, int, int, int ); //prototype


int main(int argc, char* argv[])
{
    int n_disks; // # of disks

    if (argc == 1)
    {
        cout << "Missing argument\n"
             << "Usage: hanoi number-of-disks\n";
        exit(1);
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            cout << "Arguement must be a number\n"
                 << "Usage: hanoi number-of-disks\n";
            exit(1);
        }
    }

    n_disks = stoi(argv[1]); //stores into int

    move(n_disks, 1, 2, 3); // calls function

    return 0;

}

/*
move function moves the disks to pegs
@param n_disks is the number of disks
@param src_peg is the source/starting peg
@param dest_peg is the destination peg or peg 2
@param temp_peg is the temp peg or peg 3
*/
void move(int n_disks, int src_peg, int dest_peg, int temp_peg)
{
    if (n_disks >= 1)
    {
        move(n_disks - 1, src_peg, temp_peg, dest_peg);
        cout << n_disks << " " << src_peg << "->" << dest_peg << endl;
        move(n_disks - 1, temp_peg, dest_peg , src_peg);
    }
}
 