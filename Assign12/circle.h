#ifndef CIRCLE_H
#define CIRCLE_H

/**
 * @file circle.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include "shape.h"

class circle : public shape
{
private:
    int radius;
public:
    circle() = default;
    circle(const string &color, int radius);

    virtual void print() const;
    virtual double get_area() const;
};

 #endif