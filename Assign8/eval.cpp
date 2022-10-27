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
 * @brief returns arithmitic from operator
 * 
 * @param left number
 * @param op operator
 * @param right number
 * @return int value of arithmitic
 */
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
            result = pow(left, right);
            break;
        default:
            break;
    }
    return result;
}

int evaluate(const string& postfix)
{
    mystack s;
    int num, left, right;
    char var;
    string op;
    stringstream ss(postfix);

    while (ss >> op)
    {
        if(isdigit(op[0]))
        {
            stringstream nn(op);
            if(nn >> num) 
            {
                s.push(num);
            }
        }
        else if((op[0] >= 'a' && op[0] <= 'z'))
        {
            var = op[0];
            num = var - 'a';
            s.push(num);
        }
        else if(op[0] == '~')
        {
            num = s.top() * -1;
            s.pop();
            s.push(num);
        }
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
