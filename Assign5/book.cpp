/**
 * @file book.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 5
 * @date 2022-10-06
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "book.h"

using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;

book::book()
{
    strcpy (ISBN, "None");
    strcpy (title, "None");
    price = 0.00;
    quantity = 0;
}

const char* book::get_isbn() const
{
    return ISBN;
}

double book::get_price() const
{
    return price;
}

int book::fullfill_order(int book_order)
{
    int num_shipped;
    if (book_order < 0)
    {
        num_shipped = 0;
        return num_shipped;        
    }
    if (book_order <= quantity)
    {
        num_shipped = book_order;
        quantity -= book_order;

        return num_shipped;
    }

    num_shipped = quantity;

    quantity = 0;

    return num_shipped;
}
/**
 * @brief printing out the ISBNs
 * 
 */
void book::print() const
{
    //I added 14 to the first setw according to pdf "setw(14)"
    cout << left << setw(14) << ISBN << setw(44) << title << right << setw(5) 
         << fixed << setprecision(2) << price << setw(6) << quantity << endl;
}