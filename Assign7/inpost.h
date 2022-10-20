#ifndef INPOST_H
#define INPOST_H
/**
 * @file inpost.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 2022-10-20
 */

#include <string>

using std::string;

//Prototypes
string convert(const string&);
//Optional Prototypes
bool isOperator(char);
int precedence(char);

#endif