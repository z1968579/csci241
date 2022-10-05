//***************************************************************************
//
//  selection_sort.cpp
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
  int num = 0; 
  int t; //temp
  vector<int> vec; //vector for storing data

  while (cin >> num) //stores data
  {
    vec.push_back(num);
  }

  for (size_t i = 0; i < vec.size() - 1; i++) //Selection sort algorithm
  {
    size_t min_index = i;
    for (size_t j = i + 1; j < vec.size(); j++)
      if (vec[j] < vec[min_index])
      {
        min_index = j;
      }             
        t = vec[i];
        vec[i] = vec[min_index];
        vec[min_index] = t;
  }

    for (size_t i = 0; i < vec.size(); i++) //prints out sorted data
    { 
      cout << setw(8) << vec[i];

      if ((i + 1) % 8 == 0 || i == vec.size() - 1)
        cout << endl;
    }
    return 0;
}
