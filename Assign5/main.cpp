/**
 * @file main.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 5
 * @date 2022-10-06
 */

#include "book.h"
#include "book_store.h"

int main()
{
    book_store s;

    s.read_book_data("bookdata");
    s.print();

    s.read_book_data("bookdata");
    s.process_orders("orders.txt");
    s.print();
    
    return 0;
}

