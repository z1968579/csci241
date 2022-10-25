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


struct node
{
    node* next;
    int value;
    
    node(int value, node* next = nullptr)
    {
        this->value = value;
        this->next = next
    }
};

class mystack
{
    private:

        //Data Members:
        node* stk_top;
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
        size_t size() const;
        bool empty() const;
        void clear();
        const int& top() const;
        void push(int);
        void pop();
        void clone(const &);
};

#endif