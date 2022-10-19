/**
 * @file mystack.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 2022-20-22
 */

#include <iostream>
#include <string>
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
mystack::mystack(const mystack& x)
{
    // Step 1
    stk_capacity = x.stk_capacity;
    stk_size = x.stk_size;

    // Step 2
    if (stk_capacity > 0)
        stk_array = new char[stk_capacity];//Not sure if an int is fine here or need to change it to the char* type
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
 */
mystack::~mystack()
{
    delete[] stk_array;//place name of 
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
mystack& mystack::operator=(const mystack& x)//might need to be something other than x
{
     if (stk_array != x.stk_array)
   {
      stk_capacity = other.stkCap;
      stk_size = x.stk_size;
   
      if (stk_capacity == 0)
         stk_array = nullptr;
      else
         stk_array = new int[stk_capacity];
      
      for (unsigned int i = 0; i < stk_size; i++)
         stk_array[i] = x.stk_array[i];
   }
      
   return *this;
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
    return stk_capacity;
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
    return stk_size;
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
    return (stk_size == 0)? true : false;
}


/**
 * Method: void clear();
 *
 * @brief: 
 *
 **/
void mystack::clear()
{
    stk_size = 0;
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
    if (n > stk_capacity)
    {
        stk_capacity = n;
        int * tempPtr;
        /*
        in the steps, it said:
        If the stack capacity is 0, 
        set the temporary array pointer to nullptr.
    
        this comes after:
        Set the stack capacity to n.
    
        the only case where stkCap will = 0 after being set to n
        is when stkCap was originally less than zero, which is not
        possible for size_t or unsigned int...
    
        The code is added in anyways with an if statement
        */
        if (stk_capacity != 0)
        {
            tempPtr = new int[n];
    
            for(unsigned int i = 0; i < stk_size; i++)
            tempPtr[i] = stk_array[i];
    
            stk_capacity = n;
            delete[] stk_array;
            stk_array = tempPtr;
    
        }

        else
        {
            stk_array = nullptr; 
        }
        
    }
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
 * @brief 
 * 
 * @param value 
 *   
 */
void mystack::push(char value)
{
    if (stk_size == stk_capacity)
   {
      if (stk_capacity == 0)
      {
        reserve(1);
      }
    
      else
      {
        reserve (stk_capacity * 2); 
      }
   }
   
   stk_array[stk_size] = value;
   stk_size++;
}

/**
 * Method: void pop();
 *
 * @brief: 
 *
 **/
void mystack::pop()
{
    stk_size--;
}
