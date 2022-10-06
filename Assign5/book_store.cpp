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

void book_store::read_book_data(const char* file_name)
{
    ifstream file;

    file.open(name, ios::binary);

    file.read((char*) this, sizeof(book_store));
    file.close();
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

    void book_store::process_orders(const char* file_name)
    {
        ifstream file;
        int order_num;
        char isbn_num;
        int amount_order;

        cout << "Order Listing" << endl;
        
        file.open(file_name);
        if (!input_file)
        {
            std::cerr << "File failed to open" << endl;
            exit (-1);
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
int book_store::binarySearch(char* ISBN)
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