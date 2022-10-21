/**
 * @file inpost.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 7
 * @date 2022-20-22
 */

#include <iostream>
#include <string>
#include <cctype>
#include "mystack.h"
#include "inpost.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

string convert(const string& infix)
{
    string postfix;
    mystack s;
    size_t i = 0;
    while(i < infix.length())
    {
        if((infix[i] >= 'a' && infix[i] <= 'z'))          
        {
            postfix += infix[i];
            postfix += ' ';
            i++;
        }
        else if(isdigit(infix[i]))
        {
            postfix += infix[i];
            i++; 
            if(infix[i] == ' ' or !isdigit(infix[i]))
            {
                postfix += " ";
            }
        }
        else if(infix[i] == ' ')
        {
            i++;
        }
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }
        else if(infix[i] == ')')
        {
            while(s.top() != '(')
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
            i++;
        }
        else if(isOperator(infix[i]))        
        {
            while(!s.empty() && precedence(infix[i]) <= precedence(s.top()))
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
    postfix.pop_back();
    return postfix;
}

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