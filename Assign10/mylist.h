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
        size_t list_size = 0;
        node<T>* list_back = nullptr;
        node<T>* list_front = nullptr;
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
 * Constructs a mylist with a copy of the elements of another mylist.
 *
 * @param x Another mylist object whose contents are copied.
 */
template <class T>
mylist<T>::mylist(const mylist<T>& x)
{
    clear();
    clone(x);
}

/**
 * @brief: Destroys the mylist object.
 */
template <class T>
mylist<T>::~mylist()
{
    clear();
}

/**
 * @brief: Sets a mylist back to empty, without deleting its dynamic storage.
 */
template <class T>
void mylist<T>::clear()
{
    while (list_size != 0)
    {
        pop_back();
    }
}

/**
 * Returns whether the mylist is empty: i.e., whether its size is 0.
 *
 * @return true if the size is 0, false otherwise.
 */
template <class T>
bool mylist<T>::empty() const
{
    return (list_size == 0);
}

/**
 * Returns the size of the mylist.
 *
 * @return The number of values stored in the mylist.
 */
template <class T>
size_t mylist<T>::size() const
{
    return list_size;
}

/**
 * Makes a copy of a mylist object's linked list.
 *
 * @param x Another mylist object whose linked list is copied.
 */
template <class T>
void mylist<T>::clone(const mylist<T>& x)
{
    for (node<T>* ptr = x.list_front; ptr != nullptr; ptr = ptr->next)
    {
        push_back(ptr->value);
    }
}


template <class T>
const T& mylist<T>::front() const
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to front()");
    }
    return list_front->value;
}

template <class T>
T& mylist<T>::front()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to front()");
    }
    return list_front->value;
}

/**
 * Inserts a value at the front of the mylist.
 *
 * @param value An integer value to insert.
 */
template <class T>
void mylist<T>::push_front(const T& value)
{
    node<T>* new_node = new node<T>(value);
    new_node->next = list_front;

    if (empty())
    {
        list_back = new_node;
    }
    else
    {
        list_front->previous = new_node;
    }

    list_front = new_node;
    list_size++;
}

template <class T>
const T& mylist<T>::back() const
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to back()");
    }
    return list_back->value;
}


template <class T>
T& mylist<T>::back()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to back()");
    }
    return list_back->value;
}

/**
 * Inserts a value at the back of the mylist.
 *
 * @param value An integer value to insert.
 */
template <class T>
void mylist<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value);
    new_node->previous = list_back;

    if (empty())
    {
        list_front = new_node;
    }
    else
    {
        list_back->next = new_node;
    }

    list_back = new_node;
    list_size++;
}


/**
 * Removes the value at the back of the mylist.
 */
template <class T>
void mylist<T>::pop_back()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to pop_back()");
    }

    node<T>* delete_node = list_back;
    list_back = delete_node->previous;

    if (list_back == nullptr)
    {
        list_front = nullptr;
    }
    else
    {
        list_back->next = nullptr;
    }

    delete delete_node;
    list_size--;
}

/**
 * Removes the value at the front of the mylist.
 */
template <class T>
void mylist<T>::pop_front()
{
    if (empty())
    {
        throw underflow_error("underflow exception on call to pop_front()");
    }

    node<T>* delete_node = list_front;
    list_front = delete_node->next;

    if (list_front == nullptr)
    {
        list_back = nullptr;
    }
    else
    {
        list_front->previous = nullptr;
    }

    delete delete_node;
    list_size--;
}


template <class T>
bool mylist<T>::operator==(const mylist<T>& rhs) const
{
    if (rhs.list_size != list_size)
    {
        return false;
    }

    node<T>* ptr = list_front;
    node<T>* lptr = rhs.list_front;
    while (ptr != nullptr && lptr != nullptr)
    {
        if (ptr->value != lptr->value)
        {
            return false;
        }
        ptr = ptr->next;
        lptr = lptr->next;
    }
    return true;
}

/**
 * Assigns new contents to a mylist.
 *
 * @param x A mylist object whose contents are copied.
 *
 * @return The value of the modified left operand.
 */
template <class T>
mylist<T>& mylist<T>::operator=(const mylist<T>& x)
{
    if (this != &x)
    {
        clear();
        clone(x);
    }
    return *this;
}

template <class T>
bool mylist<T>::operator<(const mylist<T>& rhs) const
{
    node<T>* lptr = rhs.list_front;
    node<T>* ptr = list_front; 

    while (ptr != nullptr && lptr != nullptr)
    {
        if (ptr->value < lptr->value)
        {
            return true;
        }
        else if (ptr->value > lptr->value)
        {
            return false;
        }

        lptr = lptr->next;
        ptr = ptr->next;
    }
    return (list_size < rhs.list_size) ? true : false;
}

/**
 * Inserts the elements of the mylist into an output stream.
 *
 * @param out The output stream.
 * @param obj A mylist object to insert into the stream.
 *
 * @return The output stream.
 */
template <class T>
std::ostream& operator<<(std::ostream& out, const mylist<T>& obj)
{
    for (node<T>* ptr = obj.list_front; ptr != nullptr; ptr = ptr->next)
    {
        out << ptr->value << " ";
    }
    return out;
}

#endif