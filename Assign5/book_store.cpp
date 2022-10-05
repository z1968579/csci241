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
    //Number 1:

    //Added this sort function
    //Will need to change up like everything else ---> ie variable names, the selection sort algorithm, etc. from you know who's code ;)
    //Also changed in book.cpp line 69 the first setw did not have the amount in it, I added 14 according to pdf "setw(14)"

    //Number 2:
    //When running everything looks fine, may need to add some endl statements in the print function to space out, also is the
    //executable file supposed to be "assign5"?, regardless it still works.

    //Number 3:
    //The bookdata file doesn't have a file type btw, Im assuming its
    //supposed to be text.

    //HMU if you have any questions :J

    int j;
    int min_index;
    book temp;

    for(int i = 0; i <= array_len; i++)
    {
        min_index = 1;
        j = i + 1;
    
        while(j < array_len)
        {
            if(strcmp(array[j].get_isbn(), array[min_index].get_isbn()) < 0)
            {
                min_index = j;
            }

        j++;
    
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
        }
    }
}