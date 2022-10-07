#ifndef BOOK_STORE_H
#define BOOK_STORE_H
/**
 * @file book_store.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 5
 * @date 2022-10-06
 */
#include "book.h"

class book_store
{
    book books[30]; // array called books with book objects
    int array_len;
    
    public:
        book_store();
        void read_book_data(const char*);
        void process_orders(const char*);
        void print() const;
        void sort();
        int binary_search(const char*);
};
#endif