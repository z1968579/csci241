#ifndef RECTANGLE_H
#define RECTANGLE_H

/**
 * @file rectangle.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include "shape.h"

class rectangle : public shape
{
private:
    int height;
    int width;
public:
    rectangle() = default;
    rectangle(const string &color, int height, int width);

    virtual double get_area() const;
    virtual void print() const;
};


 #endif