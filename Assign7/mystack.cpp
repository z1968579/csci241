/**
 * @file mystack.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 2022-20-22
 */

#include <iostream>
#include <string>
#include <cstdef>
#include <cstdlib>
#include "mystack.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;


/**
 * Method: mystack();
 *
 * @brief: Default Constructor; constructs a new mystack object
 *
 **/
mystack::mystack()
{
    stk_array = nullptr;
    stk_capacity = 0;
    stk_size = 0;
}


/**
 * Method: mystackcopy(const mystack&);
 *
 * @brief: Construct a new mystackcopy object
 * 
 * @param: x:
 **/
mystack::mystackcopy(const mystack& x)
{
    // Step 1
    stk_capacity = x.stk_capacity;
    stk_size = x.stk_size;

    // Step 2
    if (stk_capacity > 0)
        stk_array = new int[stk_capacity];//Not sure if an int is fine here or need to change it to the char* type
    else
        stk_array = nullptr;

    // Step 3
    for (size_t i = 0; i < stk_size; i++)
        stk_array[i] = x.stk_array[i];
}


/**
 * Method: ~mystack();
 *
 * @brief: Destroy the mystack object
 *
 **/
mystack::~mystack()
{
    delete[]//place name of 
}


/**
 * Method: mystack& operator=(const mystack&);
 *
 * @brief: 
 *
 * @param mystack&
 *
 * @return: mystack& 
 **/
mystack& mystack::operator=(const mystack&)
{

}


/**
 * Method: size_t capacity() const;
 *
 * @brief: 
 *
 * @return: size_t 
 **/
size_t mystack::capacity() const
{

}


/**
 * Method: size_t size() const;
 *
 * @brief: 
 *
 * @return: size_t 
 **/
size_t mystack::size() const
{

}


/**
 * Method: bool empty() const;
 *
 * @brief: 
 *
 * @return true 
 * @return false 
 **/
bool mystack::empty() const
{

}


/**
 * Method: void clear();
 *
 * @brief: 
 *
 **/
void mystack::clear()
{

}


/**
 * Method: void reserve(ssize_t);
 *
 * @brief: 
 *
 * @param: size_t
 **/
void mystack::reserve(size_t)
{

}


/**
 * Method: const char& top() const;
 *
 * @brief: 
 *
 * @return: const char&
 **/
const char& mystack::top() const
{
    return stk_array[stk_size - 1];
}


/**
 * Method: void pop();
 *
 * @brief: 
 *
 **/
void mystack::pop()
{
    stk_size = stk_size - 1;
}