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

    mystack s;
    s.reserve(10);
    s.push('(');

    string postfix = "";
    int len = infix.length();



    for(int i = 0; i < len; i++)
    {
        char inf = infix[i];
        if(isalnum(inf))
        {
            postfix = postfix + inf;
            postfix = postfix + ' ';
        }
        else if(inf =='(')
        {
            s.push('(');
        }
        else if(inf == ')')
        {
            while(s.top()!='(')
            {
                postfix = postfix + s.top();
                postfix = postfix + ' ';
                s.pop();
            }
            s.pop();
        }
        else
        {
            int p1 = precedence(inf);
            int p2 = precedence(s.top());

            while(p1 <= p2)
            {
                postfix = postfix + s.top();
                postfix = postfix + ' ';
                s.pop();
                p2 = precedence(s.top());
            }
            s.push(inf);
        }
    }

    while(s.top()!='(')
    {
        postfix = postfix + s.top();
        postfix = postfix + ' ';
        s.pop();
    }
    postfix.pop_back();
    return postfix;
}

   
/**
 * Method: bool isOperator(infix[i]ar operatr);
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
 * Method: int precedence(infix[i]ar operatr);
 * 
 * @brief: 
 * 
 * @return int 
 **/
/*
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
}*/
int precedence(char x)
{
   switch(x)
   {
       case '(':
           return 0;

       case '+':
       case '-':
           return 1;

       case '*':
       case '/':
           return 2;

       case '^':
case '~':
           return 3;

       default : return 999;
   }
}