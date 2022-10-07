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

    cout << setw(14) << left << "ISBN" << setw(44) << "Title" << setw(5) <<right << "Price    Qty." << endl << endl;

    for (int i = 0; i <= array_len - 1; i++)
    {
        books[i].print();
    }
}
void book_store::process_orders(const char* file_name)
{
    ifstream file;
    char order_num[7];
    char order_isbn[11];
    int order_amount;
    double total;
    int value;
    cout << endl << "Order Listing" << endl << endl;
    
    file.open(file_name);

    if (!file)
    {
        std::cerr << "File failed to open" << endl;
        exit (-1);
    }
    //print transaction.
    file >> order_num;
    while (file.good())
    {
        file >> order_isbn;
        file >> order_amount;

        cout << "Order #" << order_num <<": ";
        int index = binary_search(order_isbn);

        if (index == -1)
        {
            cout << "error - ISBN " << order_isbn << " does not exist" << endl;
        }
        else
        {
            value = books[index].fullfill_order(order_amount);

            total = value * books[index].get_price();
            cout << "ISBN " << order_isbn << ", " << value << " of " << order_amount << " shipped, order total $" << total << endl;
        }
        file >> order_num;
    }
    cout << endl;
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
            if(strcmp(books[j].get_isbn(), books[min_index].get_isbn()) < 0)
            {
                min_index = j;
            }
        j++;
        }
        temp = books[min_index];
        books[min_index] = books[i];
        books[i] = temp;
    }
}

/**
 * @brief binarySearch
 * 
 * @return int 
 */
int book_store::binary_search(const char* search)
{
    int low = 0,
    high = array_len - 1;

    while(low <= high) 
    {
        int mid = (low + high) / 2;

        if(strcmp(search, books[mid].get_isbn()) == 0)
        {
            return mid;
        }
        if(strcmp(search, books[mid].get_isbn()) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }   
    }   
    return -1;
}