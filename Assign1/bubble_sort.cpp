//***************************************************************************
//
//  bubble_sort.cpp
//  CSCI 241 Assignment 1
//
//  Created by Jacob Rudawski z1968579
//
//***************************************************************************

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
  int last_swap;
  int num = 0; 
  int t; //temp
  vector<int> vec;//vector for storing data

  while (cin >> num) //stores data
  {
    vec.push_back(num);
  }
  
  do //Bubble sort do while algorithm 
  {
    last_swap = 0;
    for (size_t i = 1; vec.size() > i; i++)
    {
        if (vec[i -1] > vec[i])
        {
        t = vec[i];
        vec[i] = vec[i - 1];
        vec[i - 1] = t;
        last_swap = i;
        }
    }
    num = last_swap;
  } while (num > 1);


    for (size_t i = 0; i < vec.size(); i++) //prints out sorted data
    { 
      cout << setw(8) << vec[i];

      if ((i + 1) % 8 == 0 || i == vec.size() - 1)
        cout << endl;
    }
    return 0;
}