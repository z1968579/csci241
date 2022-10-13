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
            {
				matrix_array[row][col] = 1;
            }
            else
            { 
				matrix_array[row][col] = 0;
            }
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

matrix operator*(const int& left, const matrix& right)
{
	//Declare and initialize Matrix object using values of constructor
	matrix result;
	
	//Outloop to loop through rows	
    for (int row = 0; row < 2; row++)
        {
            //Innerloop to loop through columns
            for (int col = 0; col < 2; col++)
            {
                //Calculates product of scalar multiplication of matrix and integer
                result.matrix_array[row][col] = right.matrix_array[row][col] * left;
            }
        }
	return result;

}

int matrix::determinant() const
{
    int x = matrix_array[0][0] * matrix_array[1][1] - matrix_array[0][1] * matrix_array[1][0];
	return x;
}


matrix matrix::operator+(const matrix& right) const
{
    matrix sum = *this;
	
	//Loop through matrices
	//Outerloop to loop through rows
	for (int row = 0; row < 2; row++)
	{
		//Innerloop to loop through columns
		for (int col = 0; col < 2; col++)
		{
			//Calculates and assigns sum of element matrices to sum object
			sum.matrix_array[row][col] = this -> matrix_array[row][col] + right.matrix_array[row][col];
		}
	}
	return sum;
}


matrix matrix::operator*(const int& right) const//reference to int "argument"& in this one
{
    matrix result = *this;
	
	//Outerloop to loop through rows
	for (int row = 0; row < 2; row++)
	{
		//Innerloop to loop through columns
		for (int col = 0; col < 2; col++)
		{
			//Calculates and assigns multiplication of element by integer to result object
			result.matrix_array[row][col] *= right;
		}
	}
	return result;
}



matrix matrix::operator*(const matrix& right) const//reference to matrix_object "argument"& in this one
{
    matrix result;

	//Calculates product of matrices and assigns result to object
	result.matrix_array[0][0] = (this->matrix_array[0][0] * right.matrix_array[0][0]) + (this->matrix_array[0][1] * right.matrix_array[1][0]);
	result.matrix_array[0][1] = (this->matrix_array[0][0] * right.matrix_array[0][1]) + (this->matrix_array[0][1] * right.matrix_array[1][1]);
	result.matrix_array[1][0] = (this->matrix_array[1][0] * right.matrix_array[0][0]) + (this->matrix_array[1][1] * right.matrix_array[1][0]);
	result.matrix_array[1][1] = (this->matrix_array[1][0] * right.matrix_array[0][1]) + (this->matrix_array[1][1] * right.matrix_array[1][1]);

	return result; 
}


bool matrix::operator==(const matrix& right) const
{
    	if(this->matrix_array[0][0] == right.matrix_array[0][0] &&
	   this->matrix_array[0][1] == right.matrix_array[0][1] &&
	   this->matrix_array[1][0] == right.matrix_array[1][0] &&
	   this->matrix_array[1][1] == right.matrix_array[1][1])
		return true;
	else
		return false;
}



bool matrix::operator!=(const matrix& right) const
{
    for (int row = 0; row < 2; row++)
	{
		//Innerloop to loop through columns
		for (int col = 0; col < 2; col++)
		{
			//Checks if element of each matrix is the same
			if (this->matrix_array[row][col] == right.matrix_array[row][col])
				return false;
		}
	}	
	return true;
}
