/**
 * @file matrix.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 330 Assignment 6
 * @date 2022-10-13
 * 
 */

#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;


int matrix::determinant() const
{
}


matrix matrix::operator+(const matrix&) const
{
}


matrix matrix::operator*(const int&) const//reference to int "argument"& in this one
{
}


matrix matrix::operator*(const matrix&) const//reference to matrix_object "argument"& in this one
{
}


bool matrix::operator==(const matrix&) const
{
    
}


bool matrix::operator!=(const matrix&) const
{
}


friend matrix::ostream& operator<<(ostream &, const matrix&)
{
}


friend matrix::matrix operator*(const int&, const matrix&)
{
}