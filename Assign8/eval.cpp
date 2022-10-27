
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
                std::cerr << "*** Division by 0 ***" << endl;
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
    stringstream ss(postfix);     // Create a stringstream object from the postfix string.

    // You can now read from the stringstream as if it were standard input. The end of the
    // string will be treated as the end of input.
    while (ss >> op)
    {
        // op is a C++ string containing the next operator/operand in the postfix expression.
        if(isdigit(op[0]))
        {
            stringstream nn(op);
            if(nn >> num) 
            {
                s.push(num);
            }
            cout <<"The integer literal is " << num << endl;
        
            //cout << op << " is an integer literal" << endl;
        }
        else if((op[0] >= 'a' && op[0] <= 'z'))
        {
            var = op[0];
            num = var - 'a';
            s.push(num); //might be op intead
            cout << op[0] << " is equal to " << num << endl;
        }
        else if(op[0] == '~')
        {
            num = s.top() * -1;
            s.pop();
            s.push(num);
            cout << "unary negation results in " << num << endl;           
        }
        else
        {
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            num = operation(left, op[0], right);
            s.push(num);
            cout << left << " " << op[0] << " " << right << " = " << num << endl;           
        }
    }

    /*
    int num = 0, num1 = 0, num2 = 0;

    //string op;
    //stringstream ss(postfix);
    std::stringstream token_stream(postfix); // Parse words from postfix
    string token;

    while (token_stream >> token) 
    {
        // Check the first character of the token.  It is n operand, then use it
        //  You could move the size() check to the is_operand() function
        if (token.size() == 1 && isOperator(token[0])) 
        {
            char operand = token[0];
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();
            num = operation(num1, operand, num2);
            s.push(num);
        } 
        else 
        {
            std::stringstream number_stream(token);  // convert number tokens to floats

            if(number_stream >> num) 
            {
                s.push(num);
            }
        }
    }

    num = s.top();
    s.pop();
    return num;
    
   */
    return 0;
}
