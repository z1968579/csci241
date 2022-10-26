/**
 * @file mystack.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 10-27-22
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
    stk_top = nullptr;
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
  stk_top = nullptr;

  stk_size = x.stk_size;

  clone(x);
}


/**
 * Method: ~mystack();
 *
 * @brief: The destructor; Deletes the stack array.
 *
 **/
mystack::~mystack()
{
    clear();
}


/**
 * Method: mystack& operator=(const mystack&);
 *
 * @brief: An overloaded copy assignment operator that assigns one mystack object to another.
 *
 * @param x: Is a reference to a constant mystack object
 *
 * @return *this
 **/
mystack& mystack::operator=(const mystack& x)
{
    if(this != &x)
    {
        // Make the left stack object empty
        clear();
        
        // Copy the other stack's size
        stk_size = x.stk_size;

        // Copy the other stack's linked list
        clone(x);
    }
        
    return *this;
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
    while(!empty())
    {
        pop();
    }
}


/**
 * Method: const char& top() const;
 *
 * @brief: This constant member function returns the top item in the stack.
 *
 * @return stk_top[stk_size - 1]: A char pointer data member of the mystack class that points 
 *         to the top of the stack
 **/
const int& mystack::top() const
{
    return stk_top->value;
}

/**
 * Method: void push(char);
 *
 * @brief: This member function pushes the character value onto the top of the stack.
 * 
 * @param value: A char variable that holds a single character to be put on top of the stack
 *   
 **/
void mystack::push(int value)
{
    node* new_node = new node(value, stk_top);

    stk_top = new_node;
    stk_size = stk_size + 1;
}

/**
 * Method: void pop();
 *
 * @brief: This member function pops the top item off of the stack by decreasing the stack size by 1
 *
 **/
void mystack::pop()
{
    node* delete_node = stk_top;

    stk_top = stk_top->next;
    
    delete delete_node;
    
    stk_size--;
}

void mystack::clone(const mystack& x)
{
    
   // node* new_node;
    node* last = nullptr;
    node* ptr = x.stk_top;
        
    while(ptr != nullptr)
    {
        node* new_node = new node(ptr->value);
            
        if(last == nullptr)
        {
            stk_top = new_node;
        }
        else
        {
            last->next = new_node;
        }
            
        last = new_node;
        ptr = ptr->next;
    }
}
