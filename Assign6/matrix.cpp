/**
 * @file matrix.cpp
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 6
 * @date 2022-10-13
 * 
 */
#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;
using std::ostream;

/**
 * Method: matrix::matrix()
 *
 * @brief Default constructor; Set the elements of the matrix array to 
 *        the "identity matrix", such that all the elements on the main 
 *	      diagonal are equal to 1 and all other elements are equal to 0, e.g.:
 *
 * @param //Nothing
 *
 * @return Nothing
 **/
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


/**
 * Method: matrix(int [2][2])
 *
 * @brief Array initialization constructor; Set the elements of the matrix array to 
 *        the corresponding elements in the array passed into the constructor.
 *
 * @param inMatrix: A 2D array of integers with two rows and two columns
 *
 * @return Nothing
 **/
matrix::matrix(int inMatrix[2][2])
{
	//Initializing the two by two 2D Array
	for(int row = 0; row < 2; row++)
    {
		for(int col = 0; col < 2; col++)
        {
			matrix_array[row][col] = inMatrix[row][col];			
        }
    }   
}


/**
 * Method: friend std::ostream& operator<<(std::ostream&, const matrix&)
 *
 * @brief: Prints the elements of the matrix separated by commas. Using square brackets
 *         around each row of the matrix and around the matrix as a whole.
 *
 * @param output: Is a reference to an ostream object, representing the left operand of the stream insertion expression.
 * @param new_matrix: Is a reference to a constant matrix object, representing the right operand of the expression.
 *
 * @return output: A reference to an ostream object (i.e., the first parameter).
 **/
ostream& operator<<(ostream& output, const matrix& new_matrix)
{
    	//Creates output in specified format and stores in ostream object
	output << "[[" << new_matrix.matrix_array[0][0] << ", " << new_matrix.matrix_array[0][1] << "], ["
		   << new_matrix.matrix_array[1][0] << ", " << new_matrix.matrix_array[1][1] << "]]";

	return output;	//Returns ostream object
}


/**
 * Method: friend matrix operator*(const int&, const matrix&)
 *
 * @brief: This method finds the product cA of a number c (also called a scalar in the parlance of abstract algebra)
 *         and a matrix A is computed by multiplying every entry of A by c: (cA)i,j = c · Ai,j.
 *
 * @param left: An integer representing the left operand of the scalar multiplication
 * @param right: A reference to a constant matrix object, representing the right operand of the scalar multiplication.
 *
 * @return result: The result of multiplying the elements of the matrix right operand by the integer left operand (a new matrix object).
 **/
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


/**
 * Method: int determinant() const
 *
 * @brief: To find the dterminant of the two by two 2D array matrix
 *
 * @param //Nothing
 *
 * @return x: The integer determinant of the matrix object.
 **/
int matrix::determinant() const
{
    int x = matrix_array[0][0] * matrix_array[1][1] - matrix_array[0][1] * matrix_array[1][0];
	return x;
}


/**
 * Method: matrix operator+(const matrix&) const;
 *
 * @brief: This method finds the sum of A+B of two 2-by-2 matrices. 
 *         A and B is calculated entrywise: (A + B)i,j = Ai,j + Bi,j, where 1 ≤ i ≤ 2 and 1 ≤ j ≤ 2
 *
 * @param right: A reference to a constant matrix object, representing the right operand of the matrix addition expression.
 *
 * @return sum: The result of the matrix addition of the left and right operands (a new matrix object).
 **/
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


/**
 * Method: matrix operator*(const int&) const
 *
 * @brief: This method finds the product Ac of a matrix A and a number c 
 *         (also called a scalar in the parlance of abstract algebra) 
 *         computed by multiplying every entry of A by c: (Ac)i,j = Ai,j · c.
 *
 * @param right: An integer representing the right operand of the scalar multiplication.
 *
 * @return result: The result of multiplying the elements of the matrix left operand by the integer right operand (a new matrix object).
 **/
matrix matrix::operator*(const int& right) const
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


/**
 * Method: matrix operator*(const matrix&) const
 *
 * @brief: This method finds the product of two 2-by-2 matrices
 *
 * @param right: A reference to a constant matrix object, representing the right operand of the matrix multiplication expression
 *
 * @return result: The result of multiplying the elements of the matrix left operand by the matrix right operand (a new matrix object).
 **/
matrix matrix::operator*(const matrix& right) const
{
    matrix result;

	//Calculates product of matrices and assigns result to object
	result.matrix_array[0][0] = (this->matrix_array[0][0] * right.matrix_array[0][0]) + (this->matrix_array[0][1] * right.matrix_array[1][0]);
	result.matrix_array[0][1] = (this->matrix_array[0][0] * right.matrix_array[0][1]) + (this->matrix_array[0][1] * right.matrix_array[1][1]);
	result.matrix_array[1][0] = (this->matrix_array[1][0] * right.matrix_array[0][0]) + (this->matrix_array[1][1] * right.matrix_array[1][0]);
	result.matrix_array[1][1] = (this->matrix_array[1][0] * right.matrix_array[0][1]) + (this->matrix_array[1][1] * right.matrix_array[1][1]);

	return result; 
}


/**
 * Method: bool operator==(const matrix&) const
 *
 * @brief: This method returns true if all elements of the left operand are equal to the corresponding elements of 
 *         the right operand. Otherwise, the member function will return false.
 *
 * @param right: A reference to a constant matrix object, representing the right operand of the relational expression
 *
 * @return true: A boolean value representing true
 * @return false: A boolean value representing false
 **/
bool matrix::operator==(const matrix& right) const
{
	//Testing each left operand and right operand equivalency
        if(this->matrix_array[0][0] == right.matrix_array[0][0] &&
	   this->matrix_array[0][1] == right.matrix_array[0][1] &&
	   this->matrix_array[1][0] == right.matrix_array[1][0] &&
	   this->matrix_array[1][1] == right.matrix_array[1][1])
		return true;
	else
		return false;
}


/**
 * Method: bool operator!=(const matrix&) const
 *
 * @brief: This method will return false if the left operand equals the right operand.
 *         Otherwise, the member function will return true.
 *
 * @param right: A reference to a constant matrix object, representing the right operand of the relational expression
 *
 * @return false: A boolean value that is returned if element of each matrix is the same
 * @return true: A boolean value that is returned if element of each matrix is not the same
 **/
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