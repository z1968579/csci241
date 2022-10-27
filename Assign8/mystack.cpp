/**
 * @file mystack.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 8
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
 * @brief: Copy Constructor; For the mystack class should initialize a new
 *         mystack object to the same string as the existing mystack object x.
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
 * @brief: The destructor; Deletes the dynamic member of the mystack class when called
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
 * @brief: This member function clears the stack size back to 0. 
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
 * @brief: This member function returns the value in the top node of the stack.
 *
 * @return stk_top->value: A node pointer data member of the mystack class that points 
 *                         to the top value of the stack
 **/
const int& mystack::top() const
{
    return stk_top->value;
}

/**
 * Method: void push(int);
 *
 * @brief: This member function pushes the integer value onto the top of the stack..
 * 
 * @param value: An integer variable that holds a numeric value assigned to a node
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
 * @brief: This member function pops the top item off 
 *         of the stack and delete the node that contained it.
 *
 **/
void mystack::pop()
{
    node* delete_node = stk_top;

    stk_top = stk_top->next;
    
    delete delete_node;
    
    stk_size--;
}

/**
 * Method: void clone(const mystack&);
 *
 * @brief: Copies the linked list from the stack x to 'this' object.
 *
 * @param x: Is a reference to a constant mystack object
 *
 **/
void mystack::clone(const mystack& x)
{
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
