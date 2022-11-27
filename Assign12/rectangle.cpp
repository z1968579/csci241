/**
 * @file rectangle.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include "rectangle.h"
#include <iostream>

using std::cout;
using std::endl;

/******************************************************************************************************
 * Constructor for Rectangle
 * @param color color of the shape
 * @param height height of rectangle
 * @param width width of rectangle
******************************************************************************************************/
rectangle::rectangle(const string &color, int height, int width) : shape(color)
{
    this->height = height;
    this->width = width;
}

/******************************************************************************************************
 * Returns the area of a rectangle object
 * @return double 
******************************************************************************************************/
double rectangle::get_area() const
{
    return height * width;
}

/******************************************************************************************************
 * Prints out the rectangles information
******************************************************************************************************/
void rectangle::print() const
{
    shape::print();
    cout << " rectangle, height " << height << ", width " << width << ", area " << get_area() << endl;
}