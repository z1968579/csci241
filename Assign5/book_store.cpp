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
/**
 * @brief Construct a new book store::book store object
 * 
 */
book_store::book_store()
{
    array_len = 0;
}
/**
 * @brief Opens file bookdata and reads them
 * 
 * @param file_name bookdata
 */
void book_store::read_book_data(const char* file_name)
{
    ifstream file;

    file.open(file_name, ios::binary);
    if (!file)
    {
        std::cerr << "File failed to open" << endl;
        exit (-2);
    }
    file.read((char*) this, sizeof(book_store));
    file.close();
    sort();
}
/**
 * @brief Prints book
 * 
 */
void book_store::print() const
{
    cout << "Book Inventory Listing\n\n";

    cout << setw(14) << left << "ISBN" << setw(44) << "Title" << setw(5) <<right << "Price    Qty." << endl << endl;

    for (int i = 0; i <= array_len - 1; i++)
    {
        books[i].print();
    }
}
/**
 * @brief Opens and reads orders.txt then searches for all ISBN's
 * 
 * @param file_name orders.txt
 */
void book_store::process_orders(const char* file_name)
{
    ifstream file;
    char order_num[7];
    char order_isbn[11];
    int order_amount;
    int shipped; //amount shipped
    double total; //total price

    cout << endl << "Order Listing" << endl << endl;
    
    file.open(file_name);

    if (!file)
    {
        std::cerr << "File failed to open" << endl;
        exit (-1);
    }
    file >> order_num;
    while (file.good()) //checks until file is ended
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
            shipped = books[index].fullfill_order(order_amount);

            total = shipped * books[index].get_price();
            cout << "ISBN " << order_isbn << ", " << shipped << " of " << order_amount << " shipped, order total $" << total << endl;
        }
        file >> order_num;
    }
    cout << endl;
    file.close();
}
/**
 * @brief Selection sort for bookdata
 * 
 */
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
 * @brief searches for ISBN errors if it does not exist
 * 
 * @param search is order_amount
 * @return int -1 if error
 */
int book_store::binary_search(const char* search)
{
    int low = 0;
    int high = array_len - 1;

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