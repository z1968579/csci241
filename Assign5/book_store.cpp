/**
 * @file book_store.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 5
 * @date 2022-10-06
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "book_store.h"

using std::cout;
using std::endl;
using std::setw;
using std::ifstream;
using std::ios;
using std::left;
using std::string;
using std::right;
using std::cerr;

book_store::book_store()
{
    array_len = 0;
}

void book_store::read_book_data(const char* file_name)
{
    ifstream file;

    file.open(file_name, ios::binary);

    file.read((char*) this, sizeof(book_store));
    file.close();
    sort();
}

void book_store::print() const
{
    cout << "Book Inventory Listing\n\n";

    cout << setw(14) << left << "ISBN" << setw(44) << "Title" << setw(5) <<right << "Price    Qty." << endl;

    for (int i = 0; i <= array_len - 1; i++)
    {
        array[i].print();
    }
}
void book_store::process_orders(const string& file_name)
{
    ifstream file(file_name);
    char order_num[11];
    char order_isbn[7];
    double order_amount;

    cout << endl << "Order Listing" << endl;
    
    //file.open(file_name, ios::binary);

    if (!file)
    {
        std::cerr << "File failed to open" << endl;
        exit (-1);
    }
    //print transaction.
    while (file >> order_num)
    {
        file >> order_isbn;
        file >> order_amount;

        int index = binary_search(order_isbn);
        if (index == -1)
        {
            cerr << "Search failed" << endl;
        }
        else
        {
            cout << "Search succeeded: " << " is the book to order";
        }
    }

    file.close();
}

void book_store::sort()
{
    int j;
    int min_index;
    book temp;

    for(int i = 0; i <= array_len - 1; i++)
    {
        min_index = i;
        j = i + 1;
        while(j < array_len)
        {
            if(strcmp(array[j].get_isbn(), array[min_index].get_isbn()) < 0)
            {
                min_index = j;
            }
        j++;
        }

        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

/**
 * @brief binarySearch
 * 
 * @return int 
 */
int book_store::binary_search(const char* ISBN)
{
   /* int low = 0,
        high = array_len - 1;
    
    

    while(low <= high) 
    {
        int mid = (low + high) / 2;

        if(strcmp(ISBN[low].get_isbn(), ISBN[mid].get_isbn()) == 0)
        {
            return mid;
        }
        
        if(low < ISBN[mid].get_isbn())
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
        
    }
    */
    return 1;
}