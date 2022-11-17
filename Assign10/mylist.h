#ifndef MYLIST_H
#define MYLIST_H
/**
* @file mylist.h
* @author Jacob Rudawski (z1968579)&  Jacob Kurbis (z1945650)
* @brief CSCI 241 Assignment 10
* @date 11-16-2022
*/

#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class mylist;

template <class T>
struct node
{
    // data members
    node<T>* next;
    node<T>* previous;
    T value;

    // constructor
    node<T> (const T& value = T(), node<T>* next = nullptr, node<T>* previous = nullptr)
    {
        this->next = next;
        this->value = value;
        this->previous = previous;
    }
};

template <class T>
std::ostream& operator<<(std::ostream&, const mylist<T>&);


template <class T>
class mylist
{
    friend std::ostream& operator<<<>(std::ostream&, const mylist<T>&);

    private:
        size_t l_size = 0;
        node<T>* l_back = nullptr;
        node<T>* l_front = nullptr;
        void clone(const mylist<T>& x);

    public:
        mylist() = default;
        mylist(const mylist<T>& x);
        ~mylist();

        mylist<T>& operator=(const mylist<T>& x);
        bool operator==(const mylist<T>& rhs) const;
        bool operator<(const mylist<T>& rhs) const;

        void clear();
        size_t size() const;
        bool empty() const;

        const T& front() const;
        const T& back() const;
        T& front();
        T& back();

        void push_front(const T& value);
        void pop_front();

        void push_back(const T& value);
        void pop_back();
};

/**
 * Constructs a myqueue with a copy of the elements of another myqueue.
 *
 * @param x Another myqueue object whose contents are copied.
 */
template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
    clear();
    clone(x);
}

/**
 * @brief: Destroys the myqueue object.
 */
template <class T>
mylist<T>::~mylist()
{
    clear();
}

/**
 * @brief: Sets a myqueue back to empty, without deleting its dynamic storage.
 */
template <class T>
void mylist<T>::clear()
{
    while (l_size != 0)
    {
        pop_back();
    }
}

/**
 * Returns whether the myqueue is empty: i.e., whether its size is 0.
 *
 * @return true if the size is 0, false otherwise.
 */
template <class T>
bool mylist<T>::empty() const
{
    return (l_size == 0);
}

/**
 * Returns the size of the myqueue.
 *
 * @return The number of values stored in the myqueue.
 */
template <class T>
size_t mylist<T>::size() const
{
    return l_size;
}

template <class T>
void mylist<T>::clone(const mylist<T>& x)
{
    for (node<T>* ptr = x.l_front; ptr != nullptr; ptr = ptr->next)
    {
        push_back(ptr->value);
    }
}


template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{
    if (this !=& x)
    {
        clear();
        clone(x);
    }
    return* this;
}


template <class T>
const T& mylist<T>::front() const
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to front()");
    }
    return l_front->value;
}

template <class T>
T& mylist<T>::front()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to front()");
    }
    return l_front->value;
}

template <class T>
const T& mylist<T>::back() const
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to back()");
    }
    return l_back->value;
}


template <class T>
T& mylist<T>::back()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to back()");
    }
    return l_back->value;
}

/**
 * Inserts a value at the back of the myqueue.
 *
 * @param value An integer value to insert.
 */
template <class T>
void mylist<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value);

    new_node->previous = l_back;

    if (empty())
        l_front = new_node;
    else
        l_back->next = new_node;

    // step 3
    l_back = new_node;

    l_size++;
}

/**
 * Inserts a value at the front of the myqueue.
 *
 * @param value An integer value to insert.
 */
template <class T>
void mylist<T>::push_front(const T& value)
{
    node<T>* new_node = new node<T>(value);

    //Step 1
    new_node->next = l_front;

    //step 2
    if (empty())
        l_back = new_node;
    else
        l_front->previous = new_node;

    // step 3
    l_front = new_node;

    l_size++;
}

/**
 * Removes the value at the back of the myqueue.
 */
template <class T>
void mylist<T>::pop_back()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to pop_back()");
    }

    node<T>* delete_node = l_back;
    l_back = delete_node->previous;

    if (l_back == nullptr)
    {
        l_front = nullptr;
    }
    else
    {
        l_back->next = nullptr;
    }

    delete delete_node;
    l_size--;
}

/**
 * Removes the value at the front of the myqueue.
 */
template <class T>
void mylist<T>::pop_front()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to pop_front()");
    }

    node<T>* delete_node = l_front;
    l_front = delete_node->next;

    if (l_front == nullptr)
    {
        l_back = nullptr;
    }
    else
    {
        l_front->previous = nullptr;
    }

    delete delete_node;
    l_size--;
}


template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
    // First check the size
    if (rhs.l_size != l_size)
    {
        return false;
    }

    // if sizes are equal loop through and compare the values in each
    node<T>* ptr = l_front;
    node<T>* rptr = rhs.l_front;
    while (ptr != nullptr && rptr != nullptr)
    {
        // anything different return false 
        if (ptr->value != rptr->value)
        {
            return false;
        }
        ptr = ptr->next;
        rptr = rptr->next;
    }
    return true;
}


template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{
    node<T>* rptr = rhs.l_front;
    node<T>* ptr = l_front; 

    // Loop through the list together 
    while (ptr != nullptr && rptr != nullptr)
    {
        if (ptr->value < rptr->value)
        {
            return true;
        }
        else if (ptr->value > rptr->value)
        {
            return false;
        }

        // move on to the next element (front to back)
        rptr = rptr->next;
        ptr = ptr->next;
    }

    return (l_size < rhs.l_size) ? true : false;
}


template <class T>
std::ostream& operator<<(std::ostream& os, const mylist<T>& obj)
{
    // Loop through the obj mylist passed and print each element followed by a space
    for (node<T>* ptr = obj.l_front; ptr != nullptr; ptr = ptr->next)
    {
        os << ptr->value << " ";
    }
    return os;
}

#endif