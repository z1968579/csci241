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
    int i = 0;
    while(infix[i] != '\0')
    {
        // if operand add to the postfix expression
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))          
        {
            postfix += infix[i];
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i] == ')')
        {
            while(s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.empty() && precedence(infix[i]) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
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