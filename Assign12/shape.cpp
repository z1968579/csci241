/**
 * @file shape.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include <string>
#include <iostream>
#include "shape.h"

using std::cout;

/**
 * @brief Construct a new shape
 * 
 * @param color color of the shape
 */
shape::shape(const string &color)
{
    this->color = color;
}


/**
 * @brief Prints shape color
 * 
 */
void shape::print() const
{
    cout << color;
}

/**
 * @brief Destroy the shape. Does nothing
 * 
 */
shape::~shape() 
{
}