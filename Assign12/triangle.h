#ifndef TRIANGLE_H
#define TRIANGLE_H

/**
 * @file triangle.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include "shape.h"

class triangle : public shape
{
private:
    int height;
    int base;
public:
    triangle() = default;
    triangle(const string &color, int height, int base);

    virtual double get_area() const;
    virtual void print() const;
};


 #endif