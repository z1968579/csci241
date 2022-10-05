/**
 * @file book.cpp
 * @author Jacob Rudawski (z1968579)
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

char* book::get_isbn()
{
    return ISBN;
}

double book::get_price()
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
        quantity =- book_order;

        return num_shipped;
    }

    num_shipped = quantity;

    quantity = 0;

    return num_shipped;
}

void book::print() const
{
    cout << left << setw << get_isbn() << setw(44) << title << right << setw(5) 
         << fixed << setprecision(2) << price << setw(6) << quantity << endl;
}