/**
 * @file simplesim_main.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 9
 * @date 11-09-2022
 */

#include "simplesim.h"
#include "sml.h"

int main()
{
    simplesim s;

    if (s.load_program())
        s.execute_program();

    s.dump();

    return 0;
}