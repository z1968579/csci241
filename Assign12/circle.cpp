/**
 * @file circle.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include "circle.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

/******************************************************************************************************
 * Constructor for circle
 * @param color color of the shape
 * @param height height of circle
 * @param width width of circle
******************************************************************************************************/
circle::circle(const string &color, int radius) : shape(color)
{
    this->radius = radius;
}

/******************************************************************************************************
 * Returns the area of a circle object
 * @return double 
******************************************************************************************************/
double circle::get_area() const
{
    return M_PI * pow(radius, 2);
}

/******************************************************************************************************
 * Prints out the circles information
******************************************************************************************************/
void circle::print() const
{
    shape::print();
    cout << " circle, radius " << radius << ", area " << get_area() << endl;
}