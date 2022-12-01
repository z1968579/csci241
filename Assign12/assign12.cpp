/**
 * @file assign12.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 12
 * @date 11-30-2022
 */


#include <iostream>
#include <vector>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

int main()
{

    //Declare either an shape or a standard library vector of pointers to shape objects.
    vector<shape*> shape;

    shape.push_back(new circle("green", 10));
	shape.push_back(new rectangle("red", 8, 6));
	shape.push_back(new triangle("yellow", 8, 4));
	shape.push_back(new triangle("black", 4, 10));
	shape.push_back(new circle("orange", 5));
	shape.push_back(new rectangle("blue", 3, 7));

    cout << "Printing all shapes...\n\n";

    //Loop through the shape or vector of shape pointers and call the print() method for each of them.
    for (size_t i = 0; i < shape.size(); i++)
    {
        shape[i]->print();
    }

    cout << "\nPrinting only circles...\n\n";

    //Prints circles
    for (size_t i = 0; i< shape.size(); i++)
    {
        circle* circ = dynamic_cast<circle*>(shape[i]);
        if (circ != nullptr)
        {
            circ->print();
        }
    }

    //Deconstructs each shape object
    for (size_t i = 0; i < shape.size(); i++)
    {
        shape.pop_back();
    }
}