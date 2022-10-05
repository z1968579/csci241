//***************************************************************************
//
//  quick_sort.cpp
//  CSCI 241 Assignment 3
//
//  Created by Jacob Rudawski z1968579
//
//***************************************************************************
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void quick_sort(vector<int>& vec, int start, int end);
int partition(vector<int>& vec, int start, int end);
void print(vector<int>& vec);

int main()
{
    int num = 0;
    vector<int> vec;

    while (cin >> num) //input
    {
        vec.push_back(num);
    }

    quick_sort(vec, 0, vec.size() - 1);
    print(vec);
    
    return 0;
}

/* sorts the vector
@param vec is the vector with a referenced 
@param start is the start of the vec
@param end is the end of the vec*/
void quick_sort(vector<int>& vec, int start, int end )
{
	if (start < end)
    {
		int pivot_point = partition(vec, start, end);

		quick_sort(vec, start, pivot_point - 1);
		quick_sort(vec, pivot_point + 1, end);
	}
}

/* partitions vector to be sent back to sorting
@param vec is the vector that is referenced
@param start is the start of the vec
@param end is the end of the vec 
@return returns pivot_index to be sorted*/
int partition(vector<int>& vec, int start, int end)
{
	int mid = (start + end) / 2;

	swap(vec[start], vec[mid]);

    int pivot_index = start;
    int pivot_value = vec[start];

    for (int scan = start + 1; scan <= end; scan++)
    {
        if (vec[scan] < pivot_value)
        {
            pivot_index++;
            swap(vec[pivot_index], vec[scan]);
        }
    }

    swap(vec[start], vec[pivot_index]);
    return pivot_index;
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