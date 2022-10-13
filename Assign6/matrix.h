#ifndef MATRIX_H
#define MATRIX_H
/**
 * @file book.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 330 Assignment 6
 * @date 2022-10-13
 */

class matrix
{
    int matrix_array[2][2];

    public:
        //Constructors
        identify_matrix();
        array_intialization(int[][]);

        //Methods

        /////////////
        // The Key ////////////////  
        /////////////       //  //

        // a "reference" is the "&" symbol, "matrix" is a class object,
        // "const methods or functons" are declared with a "const" at end of the prototype,
        // "overloaded operators" are established by typing "operator" followed by whatever 
        // operator symbol you want to overload(+, <<, *, etc.)

        int determinant() const;
        matrix operator+(const matrix&) const;
        matrix operator*(const int&) const;//reference to int "argument"& in this one
        matrix operator*(const matrix&) const;//reference to matrix_object "argument"& in this one
        bool operator==(const matrix&) const;
        bool operator!=(const matrix&) const;
        friend ostream& operator<<(ostream&, const matrix&);
        friend matrix operator*(const int&, const matrix&);
};
#endif