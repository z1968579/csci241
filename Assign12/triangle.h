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
    //Data Members
        int height;
        int base;

    //Member Functions
    public:
        //Constructors
        triangle() = default;
        triangle(const string &color, int height, int base);

        //Accessors
        virtual double get_area() const;
        virtual void print() const;
};


 #endif