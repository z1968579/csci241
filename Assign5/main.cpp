/**
 * @file main.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 5
 * @date 2022-10-06
 */

#include <iostream>
#include "book.h"
using std::cout;
using std::endl;

int main()
{
    int test;
    book b;

    b.print();

    test = b.fullfill_order(-3);

    b.print();
    cout << "shipped is " << test << endl;

    test = b.fullfill_order(3);

    b.print();
    cout << "shipped is " << test << endl;
    
    test = b.fullfill_order(11);

    b.print();
    cout << "shipped is " << test << endl;   
    return 0;
}

