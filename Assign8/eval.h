#ifndef EVAL_H
#define EVAL_H

#include <iostream>
#include <string>
#include <cctype>

using std::string;

int evaluate(const string& postfix);

int extra(int, char, int);

#endif