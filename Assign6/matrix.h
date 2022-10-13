#ifndef MATRIX_H
#define MATRIX_H
/**
 * @file book.h
 * @author Jacob Rudawski (z1968579) & Jacob Kurbis (z1945650)
 * @brief CSCI 241 Assignment 6
 * @date 2022-10-13
 */
class matrix
{

    private:

        //Data Member(s) 
        int matrix_array[2][2];

    public:

        //Constructors
        matrix();
        matrix(int[2][2]);

        //Methods
        int determinant() const;
        matrix operator+(const matrix&) const;
        matrix operator*(const int&) const;
        matrix operator*(const matrix&) const;
        bool operator==(const matrix&) const;
        bool operator!=(const matrix&) const;
        friend std::ostream& operator<<(std::ostream&, const matrix&);
        friend matrix operator*(const int&, const matrix&);


};
#endif