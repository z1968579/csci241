//***************************************************************************
//
//  insertion_sort.cpp
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
  int j;
  int t;//temp
  vector<int> vec; //vector for storing data

  while (cin >> num) //stores data
  {
    vec.push_back(num);
  }

  for (size_t i = 1; i <= vec.size() - 1;i++) //insertion sort algorithm
  {
    t = vec[i];
     j = i;
        while (j > 0 and vec[j - 1] > t)
        {
          vec[j] = vec[j - 1];
            j--;
        }
    vec[j] = t;
  }
  
    for (size_t i = 0; i < vec.size(); i++)//prints out sorted data
    { 
      cout << setw(8) << vec[i];

      if ((i + 1) % 8 == 0 || i == vec.size() - 1)
        cout << endl;
    }
    return 0;
}