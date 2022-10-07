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
/**
 * @brief Construct a new book::book object
 * 
 */
book::book()
{
    strcpy (ISBN, "None");
    strcpy (title, "None");
    price = 0.00;
    quantity = 0;
}
/**
 * @brief Gets the ISBN from bookdata
 * 
 * @return const char* isbn
 */
const char* book::get_isbn() const
{
    return ISBN;
}
/**
 * @brief Gets the price of book
 * 
 * @return double price
 */
double book::get_price() const
{
    return price;
}
/**
 * @brief Fills order with the amount that can be shipped
 * 
 * @param book_order Order amount
 * @return int shipped
 */
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
 * @brief prints bookdata
 * 
 */
void book::print() const
{
    cout << left << setw(14) << ISBN << setw(44) << title << right << setw(5) 
         << fixed << setprecision(2) << price << setw(6) << quantity << endl;
}