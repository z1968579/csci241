/**
 * @file rectangle.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include <iostream>
#include "rectangle.h"

using std::cout;
using std::endl;


/**
 * @brief Construct a new rectangle
 * 
 * @param color color of shape
 * @param height height of the rectangle
 * @param width width of the rectangle
 */
rectangle::rectangle(const string &color, int height, int width) : shape(color)
{
    this->height = height;
    this->width = width;
}

/**
 * @brief Returns the area of the rectangle
 * 
 * @return area
 */
double rectangle::get_area() const
{
    double area = height * width;
    return area;
}

/**
 * @brief Prints out the rectangle
 * 
 */
void rectangle::print() const
{
    shape::print();
    cout << " rectangle, height " << height << ", width " << width << ", area " << get_area() << endl;
}