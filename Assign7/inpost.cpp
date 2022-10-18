/**
 * @file inpost.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 2022-20-22
 */

#include <iostream>
#include <string>
#include "inpost.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

/**
 * Method: bool isOperator(char operatr);
 * 
 * @brief: 
 * 
 * @param operator
 * 
 * @return true 
 * @return false 
 **/
bool isOperator(char operatr)
{
    if(operatr == '+' || operatr == '-' || operatr == '*' || operatr == '/' || operatr == '~' || operatr == '^')
    {
        return true;
    }

    else
    {
        return false;
    }
}

/**
 * Method: int precedence(char operatr);
 * 
 * @brief: 
 * 
 * @return int 
 **/
int precedence(char operatr)
{
    int operatr_amount;

    if(operatr == '~' || operatr == '^')
    {
        operatr_amount = 20;
    }

    else if(operatr == '*' || operatr == '/')
    {
        operatr_amount = 15;
    }

    else if(operatr == '+' || operatr == '-')
    {
        operatr_amount = 10;
    }

    else
    {
        operatr_amount = 5;
    }

    return operatr_amount;
}