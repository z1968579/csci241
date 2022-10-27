/**
 * @file eval.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 8
 * @date 10-27-22
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stack>
#include <sstream>
#include "inpost.h"
#include "mystack.h"
#include "eval.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::stringstream;

/**
 * Function: int operation(int, char, int);
 *
 * @brief: The function should return an integer the result of the arithmetic operation.
 * 
 * @param left: An integer that holds the left operand of the arithmetic operation
 * @param op: A char variable that holds the arithmetic operator
 * @param right: An integer that holds the right operand of the arithmetic operation
 *
 * @return result: An integer that holds the value of the arithmetic operator
 **/
int operation(int left, char op, int right)
{
    int result;
    switch(op)
    {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;        
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            if(right == 0)
            {
                cout << "*** Division by 0 ***" << endl;
                result = 0;
                break;
            }
            result = left / right;
            break;
        case '^':
            result = 1;
            for (int i = 0; i < right; i++)
            {
                result *= left;
            }
            break;
        default:
            break;
    }
    return result;
}


/**
 * Function: int evaluate(const string&);
 *
 * @brief: This function evaluates the postfix expression passed to it
 *         and returns the calculated value.
 * 
 * @param postfix: A reference to a constant string; the postfix expression
 *
 * @return num: An integer value that is the result of the postfix operand expression
 **/
int evaluate(const string& postfix)
{
    mystack s;
    int num, left, right;
    char var;
    string op;
    stringstream ss(postfix);

    while (ss >> op)
    {
        //Checks for integer operand
        if(isdigit(op[0]))
        {
            stringstream nn(op);
            if(nn >> num) 
            {
                s.push(num);
            }
        }
        //Checks for alphabetical operand
        else if((op[0] >= 'a' && op[0] <= 'z'))
        {
            var = op[0];
            num = var - 'a';
            s.push(num);
        }
        //Checks for '~' operand
        else if(op[0] == '~')
        {
            num = s.top() * -1;
            s.pop();
            s.push(num);
        }
        //Checks for any binary operators
        else
        {
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            num = operation(left, op[0], right);
            s.push(num);
        }
    }
    num = s.top();
    s.pop();
    return num;
}

