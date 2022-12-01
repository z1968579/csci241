/**
 * @file circle.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */


#include <iostream>
#include <string>
#include <math.h>
#include "circle.h"

using std::cout;
using std::endl;

/**
 * @brief Constructor; Initializes Circle radius
 * 
 * @param col: reference to a const string that contains a shapes color
 * @param rad: circle's radius
 *
 */
circle::circle(const string& col, int rad) : shape(col)
{
    set_radius(rad);
}


/**
 * @brief Sets the circle's radius, if it's less than zero return 0 or the radius  
 * 
 * @param rad: An integer that holds circle's radius 
 */
void circle::set_radius(int rad)
{
    radius = (rad < 0) ? 0 : rad;
}


/**
 * @brief Returns the circle's radius 
 * 
 * @return The data member containing the circle's radius
 *
 */
int circle::get_radius() const
{
    return radius;
}


/**
 * @brief Calculates radius of the circle
 * 
 * @return A double that holds the circle's area
 */
double circle::get_area() const
{
    return  M_PI*(pow(radius,2));
}

/**
 * @brief Calls print method then prints circle radius and area
 * 
 */
void circle::print() const
{
    shape::print();
    cout << " circle, radius " << radius << ", area " << get_area() << endl;
}