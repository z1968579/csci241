//***************************************************************************
//
//  merge_sort.cpp
//  CSCI 241 Assignment 3
//
//  Created by Jacob Rudawski z1968579
//
//***************************************************************************
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void merge_sort(vector<int>& vec);
void merge (vector<int>& vec, vector<int>& start, vector<int>& end);
void print(vector<int>& vec);


int main()
{
    int num = 0;
    vector<int> vec;

    while (cin >> num) // input
    {
        vec.push_back(num);
    }

    merge_sort(vec);

    print(vec);
    return 0;
}

/* splits vectors and sends them to merge
@param vec is the vector with a referenced */

void merge_sort(vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    int mid = vec.size() / 2;
    vector<int> start(vec.begin(), vec.end() - mid);
    vector<int> end(vec.begin() + mid, vec.end());

    merge_sort(start);
    merge_sort(end);
    merge(vec, start, end);
    
}

/* merges vectors which sorts them
@param vec is the vector that is referenced
@param start is the first half of the vec
@param end is the last half of the vec */

void merge(vector<int>& vec, vector<int>& start, vector<int>& end)
{
    int istart = start.size();
    int iend = end.size();
    int i = 0;
    int j = 0;
    int k = 0;

    while (j < istart and k < iend) 
    {
        if (start[j] < end[k]) 
        {
            vec[i] = start[j];
            j++;
        }
        else 
        {
            vec[i] = end[k];
            k++;
        }
        i++;
    }
    while (j < istart) 
    {
        vec[i] = start[j];
        j++; 
        i++;
    }
    while (k < iend) 
    {
        vec[i] = end[k];
        k++; 
        i++;
    }

}

/* prints the output
@param vec is the sorted vector that is referenced */
void print(vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    { 
      cout << setw(8) << vec[i];

      if ((i + 1) % 8 == 0 || i == vec.size() - 1)
        cout << endl;
    }
}