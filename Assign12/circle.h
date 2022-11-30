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
    //Data Members
    private:
        int radius;

    //Member Functions
    public:
        //Constructor
        circle(const string&, int);

        //Accessors
        void set_radius(int);
        int get_radius() const;

        virtual void print() const;
        virtual double get_area() const;


};

#endif