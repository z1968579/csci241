/**
 * @file main.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 2022-20-22
 */

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "inpost.h"
#include "mystack.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

/**
 * Reads a series of infix strings from standard input, converts them
 * to postfix, and prints them.
 *
 * @return Returns 0 upon successful completion.
 ********************************************************************/
int main()
{
    string infix;
    string postfix;

    while (getline(cin, infix))
    {
        cout << "  infix: " << infix << endl;
        postfix = convert(infix);
        cout << "postfix: " << postfix << endl << endl;
    }
    
}