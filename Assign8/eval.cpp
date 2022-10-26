#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <sstream>
#include <iterator>
#include "inpost.h"
#include "mystack.h"
#include "eval.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

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
            if(right == 0 || left == 0)
            {
                std::cerr << "*** Division by 0 ***" << endl;
                exit(1);
            }
            result = left / right;
            break;
        case '^':
            while(right > 0)
            {
                result *= left;
                right--;
            }
            break;
        default:
            break;
    }
    return result;
}

int evaluate(const string& postfix)
{

    mystack s;
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
    //return 0;
}
 