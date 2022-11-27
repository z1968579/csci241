#ifndef SHAPE_H
#define SHAPE_H

/**
 * @file shape.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include <string>

using std::string;

class shape
{
private:
    string color;

public:
    shape() = default;
    shape(const string &color); // This will only be invoked through its children
    virtual ~shape();           // Needed for compiler, will give warning otherwise
    virtual void print() const;

    virtual double get_area() const = 0; // Pure virtual method
};

 #endif