#ifndef MYSTACK_H
#define MYSTACK_H
/**
 * @file mystack.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 10-27-2022
 */

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>

class mystack
{
    private:

        //Data Members:
        NODE *stk_top;//May or may not be correctly declared
        size_t stk_size;


    public:
        //Methods:

        //Constructors:
        mystack();//Default Constructor
        mystack(const mystack&);//Copy Constructor

        //Destructor:
        ~mystack();

        //Other Methods
        mystack& operator=(const mystack&);
        size_t capacity() const;
        size_t size() const;
        bool empty() const;
        void clear();
        void reserve(size_t);
        const char& top() const;
        void push(char);
        void pop();
};

#endif