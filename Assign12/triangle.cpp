/**
 * @file triangle.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include "triangle.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************************************************************
 * Constructor for triangle
 * @param color color of the shape
 * @param height height of triangle
 * @param base base of triangle
******************************************************************************************************/
triangle::triangle(const string &color, int height, int base) : shape(color)
{
    this->height = height;
    this->base = base;
}

/******************************************************************************************************
 * Returns the area of a triangle object
 * @return double 
******************************************************************************************************/
double triangle::get_area() const
{
    return height * base / 2.0;
}

/******************************************************************************************************
 * Prints out the triangles information
******************************************************************************************************/
void triangle::print() const
{
    shape::print();
    cout << " triangle, height " << height << ", base " << base << ", area " << get_area() << endl;
}