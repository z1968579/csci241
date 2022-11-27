/**
 * @file assign12.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{

    // Declare either an array or a standard library vector of pointers to shape objects.
    vector<shape*> array;

    // Dynamically create some circles, rectangles, and triangles (at least two of each). After creating each object, add it to the array or vector.
    rectangle* rect1 = new rectangle("red", 8, 6);
    rectangle* rect2 = new rectangle("blue", 3, 7);
    array.push_back(rect1);
    array.push_back(rect2);

    //Output of the circles is getting printed out twice, not sure why
    circle* circ1 = new circle("green", 10);
    circle* circ2 = new circle("orange", 5);
    array.push_back(circ1);
    array.push_back(circ2);

    triangle* tri1 = new triangle("yellow", 8, 4);
    triangle* tri2 = new triangle("black", 4, 10);
    array.push_back(tri1);
    array.push_back(tri2);

    // Loop through the array or vector of shape pointers and call the print() method for each of them.
    for (size_t i = 0; i < array.size(); i++)
    {
        array[i]->print();
    }

    // Loop through the array or vector of shape pointers again and call the print() method for each of the circle objects in the array or vector.
    for (size_t i = 0; i< array.size(); i++)
    {
        circle* cir = dynamic_cast<circle*>(array[i]);
        if (cir != nullptr)
        {
            cir->print();
        }
    }

    // Loop through the list of shape pointers one more time and delete each object.
    for (size_t i = 0; i < array.size(); i++)
    {
        array.pop_back();
    }
}