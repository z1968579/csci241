/**
 * @file triangle.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include <iostream>
#include "triangle.h"

using std::cout;
using std::endl;

/**
 * @brief Construct a new triangle::triangle object
 * 
 * @param color color of the triangle
 * @param height height of the triangle
 * @param base base 
 */
triangle::triangle(const string &color, int height, int base) : shape(color)
{
    this->height = height;
    this->base = base;
}

/**
 * @brief Returns the area of the triangle
 * 
 * @return area 
 */
double triangle::get_area() const
{
    double area = (height * base) / 2.0;
    return area;
}

/**
 * @brief Prints out the triangle
 * 
 */
void triangle::print() const
{
    shape::print();
    cout << " triangle, height " << height << ", base " << base << ", area " << get_area() << endl;
}