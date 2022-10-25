#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "mystack.h"
#include "eval.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int extra(int left, char op, int right)
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
    }
    return result;
}

int evaluate(const string& postfix)
{
    // Create a stack of capacity equal to expression size
    mystack s;
    int i;
 
    // Scan all characters one by one
    for (i = 0; postfix[i]; ++i)
    {
        //if the character is blank space then continue
        if(exp[i] == ' ')continue;
         
        // If the scanned character is an
        // operand (number here),extract the full number
        // Push it to the stack.
        else if (isdigit(postfix[i]))
        {
            int num=0;
             
            //extract full number
            while(isdigit(postfix[i]))
            {
            num = num * 10 + (int)(postfix[i] - '0');
                i++;
            }
            i--;
             
            //push the element in the stack
            push(stack,num);
        }
         
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
             
            switch (postfix[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
             
            }
        }
    }
    return pop(stack);
}
 