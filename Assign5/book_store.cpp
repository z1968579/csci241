/**
 * @file book_store.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 5
 * @date 2022-10-06
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "book_store.h"

using std::cout;
using std::endl;
using std::setw;
using std::ifstream;
using std::ios;

book_store::book_store()
{
    array_len = 0;
}

void book_store::read_book_data(const char* name)
{
    ifstream input_file;

    input_file.open(name, ios::binary);

    input_file.read((char*) this, sizeof(book_store));
    input_file.close();
    sort();
}

void book_store::print() const
{
    cout << "Book Inventory Listing" << endl;

    cout << "ISBN           Title               Price Qty." << endl;

    for (int i = 0; i <= array_len - 1; i++)
    {
        array[i].print();
    }

}

void book_store::sort()
{
   // int j, min_index;
   // book temp;
}