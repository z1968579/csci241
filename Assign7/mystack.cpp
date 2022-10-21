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
 * @brief: Default Constructor; Initializes a new mystack object to an empty stack.
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
 * @brief: Copy constructor; Initializes a new mystack object to the same values for 
 *         all of its data members as the existing mystack object x.
 * 
 * @param x: Is a reference to a constant mystack object
 **/
mystack::mystack(const mystack& x)
{
    //Copying over the object x's capcity and size values
    stk_capacity = x.stk_capacity;
    stk_size = x.stk_size;

    //Checking if there is any dynamic storage for x object
    if (stk_capacity > 0)
        stk_array = new char[stk_capacity];
    else
        stk_array = nullptr;

    //Copying the contents of the x object's storage to the new object
    for (size_t i = 0; i < stk_size; i++)
        stk_array[i] = x.stk_array[i];
}


/**
 * Method: ~mystack();
 *
 * @brief: The destructor; Deletes the stack array.
 *
 **/
mystack::~mystack()
{
    delete[] stk_array;
}


/**
 * Method: mystack& operator=(const mystack&);
 *
 * @brief: An overloaded copy assignment operator that assigns one mystack object to another.
 *
 * @param s: Is a reference to a constant mystack object
 *
 * @return *this
 **/
mystack& mystack::operator=(const mystack& x)//might need to be something other than x
{
     if (stk_array != x.stk_array)
   {

      stk_capacity = x.stk_capacity;
      stk_size = x.stk_size;
   
      if (stk_capacity == 0)
         stk_array = nullptr;
      else
         stk_array = new char [stk_capacity];

   //Copying the contents of the s object's storage to the new object
      for (unsigned int i = 0; i < stk_size; i++)
         stk_array[i] = x.stk_array[i];
   }
      
   return *this;
}


/**
 * Method: size_t capacity() const;
 *
 * @brief: This conmstant member function returns the stack capacity.
 *
 * @return stk_capacity: A size_t data member of the mystack class that holds the capacity of the stack 
 **/
size_t mystack::capacity() const
{
    return stk_capacity;
}


/**
 * Method: size_t size() const;
 *
 * @brief: This constant member function returns the stack size.
 *
 * @return stk_size: A size_t data member of the mystack class that holds the size of the stack 
 **/
size_t mystack::size() const
{
    return stk_size;
}


/**
 * Method: bool empty() const;
 *
 * @brief: This constant member function returns true if the stack size is 0. Otherwise, it returns false.
 *
 * @return true: A boolean value representing true
 * @return false: A boolean value representing false
 **/
bool mystack::empty() const
{
    return (stk_size == 0)? true : false;
}


/**
 * Method: void clear();
 *
 * @brief: This member function should set the stack size back to 0. 
 *
 **/
void mystack::clear()
{
    stk_size = 0;
}


/**
 * Method: void reserve(ssize_t);
 *
 * @brief: This member function modifies an object's stack capacity without 
 *         changing the stack size or the contents of the stack array.
 *
 * @param n: A size_t integer representing the stk_size data member of the mystack class
 **/
void mystack::reserve(size_t n)
{
    if (n > stk_capacity)
    {
        //Set the stack capacity to n.
        stk_capacity = n;

        //Declare a temporary array pointer (a pointer to an char).
        char * temp_ptr;
        
        //Copy the contents of the stack array into the temporary array.
        if (stk_capacity != 0)
        {
            temp_ptr = new char[n];
    
            for(unsigned int i = 0; i < stk_size; i++)
            {
                temp_ptr[i] = stk_array[i];
            }

            stk_capacity = n;
            delete[] stk_array;//Delete the stack array.
            stk_array = temp_ptr;//Set the stack array pointer to the temporary array pointer.
    
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
 * @brief: This constant member function returns the top item in the stack.
 *
 * @return stk_array[stk_size - 1]: A char pointer data member of the mystack class that points 
 *         to the top of the stack
 **/
const char& mystack::top() const
{
    return stk_array[stk_size - 1];
}

/**
 * Method: void push(char);
 *
 * @brief: This member function pushes the character value onto the top of the stack.
 * 
 * @param value: A char variable that holds a single character to be put on top of the stack
 *   
 **/
void mystack::push(char value)
{
    if (stk_size == stk_capacity)
    {
        if (stk_capacity == 0)
        {
            reserve(1);//Increase stack capacity by 1
        }
    
        else
        {
            reserve(stk_capacity * 2);//Double stack capacity
        }
    }
   
   stk_array[stk_size] = value;//Copy value into the stack array as the new top item in the stack.
   stk_size++;//Increase the stack size by 1
}

/**
 * Method: void pop();
 *
 * @brief: This member function pops the top item off of the stack by decreasing the stack size by 1
 *
 **/
void mystack::pop()
{
    stk_size--;
}
