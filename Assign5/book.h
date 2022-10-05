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
    char ISBN[11];
    char title[41];

    double price;

    int quantity;

    public:
        book();
        char* get_isbn();
        double get_price();
        int fullfill_order(int);
        void print() const;
};
#endif