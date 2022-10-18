#ifndef INPOST_H
#define INPOST_H
/**
 * @file inpost.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 2022-10-20
 */

#include <iostream>
#include <string>

using std::string;

//Prototypes
string convert(const string&);
//Optional Prototypes(pg 1 in PDF before second step)
bool isOperator(char);
int precedence(char);

#endif