/**
 * @file book_store.cpp
 * @author Jacob Rudawski (z1968579)
 * @brief CSCI 241 Assignment 5
 * @date 2022-10-06
 */

#include <iomanip>
#include <iostream>
#include "book_store.h"

using std::cout;
using std::endl;
using std::setw;

book_store::book_store()
{
    array_len = 0;
}

void book_store::read_book_data(const char*)
{

}

void book_store::print() const
{
    cout << "Book Inventory Listing" << endl;

    cout << "ISBN           Title               Price Qty." << endl;

    for (int = 0; i <= array_len - 1; i++)
    {
        array[i].print();
    }

}