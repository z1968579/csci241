#ifndef BOOK_H
#define BOOK_H
/**
 * @file book.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 330 Assignment 5
 * @date 2022-10-06
 */
class book
{
    char ISBN[11]; //array of ISBN
    char title[41];

    double price;

    int quantity;

    public:
        book();
        const char* get_isbn() const;
        double get_price() const;
        int fullfill_order(int);
        void print() const;
};
#endif