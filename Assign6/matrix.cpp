/**
 * @file matrix.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 330 Assignment 6
 * @date 2022-10-13
 * 
 */
#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;
using std::ostream;

matrix::matrix()
{
	//Loop to initialize identity matrix. Main diagonal = 1
	//Outerloop to loop through rows
	for (int row = 0; row < 2; row++)
	{
		//Innerloop to loop through each column of row	
		for (int col = 0; col < 2; col++)
		{	
			//Sets element to one if in diagonal or zero if not.
			if (row == col)
				matrix_array[row][col] = 1;
			else 
				matrix_array[row][col] = 0;
		}
	}
}
matrix::matrix(int inMatrix[2][2])
{
	for(int row = 0; row < 2; row++)
    {
		for(int col = 0; col < 2; col++)
        {
			matrix_array[row][col] = inMatrix[row][col];			
        }
    }   
}
ostream& operator<<(ostream& output, const matrix& new_matrix)
{
    	//Creates output in specified format and stores in ostream object
	output << "[[" << new_matrix.matrix_array[0][0] << ", " << new_matrix.matrix_array[0][1] << "], ["
		   << new_matrix.matrix_array[1][0] << ", " << new_matrix.matrix_array[1][1] << "]]";

	return output;	//Returns ostream object
}

/*int matrix::determinant() const
{
    int x = matrixArray[0][0] * matrixArray[1][1] - matrixArray[0][1] * matrixArray[1][0];
	return x;
}


matrix matrix::operator+(const matrix&) const
{
}


matrix matrix::operator*(const int&) const//reference to int "argument"& in this one
{
}


matrix matrix::operator*(const matrix&) const//reference to matrix_object "argument"& in this one
{
}


bool matrix::operator==(const matrix&) const
{

}


bool matrix::operator!=(const matrix&) const
{
}





friend matrix::matrix operator*(const int&, const matrix&)
{
}*/