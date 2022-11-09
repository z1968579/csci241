/**
 * @file inpost.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 9
 * @date 11-09-2022
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

/**
 * Function: string convert(const string&);
 * 
 * @brief: This function converts the infix expression passed to it as a C++ string 
 *         into an equivalent postfix expression stored in a string object.
 * 
 * @param infix: A string that may contain unnecessary whitespace and/or parentheses
 *               that will be converted into a postfix string stored in a mystring object.
 * 
 * @return postfix: A string of constant characters 
 **/
string convert(const string& infix)
{
    //Variables:
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
 * Function: bool isOperator(char operatr);
 * 
 * @brief: This function tests whether a character is an arithmetic operator or not.
 * 
 * @param operatr: A char variable that holds in the passed in operator symbol
 * 
 * @return true: A boolean value representing true
 * @return false: A boolean value representing false
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
 * Function: int precedence(char operatr);
 * 
 * @brief: This function returns the precedence of an arithmetic operator, 
 *         the higher the amount returned, the higher the precendence. 
 * 
 * @return operatr_amount: An integer that holds a value based on the passed in operator symbol
 **/
int precedence(char operatr)
{
    //Variable(s)
    int operatr_amount;
    
    //The higher the precendence of the operator the higher the returned amount
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