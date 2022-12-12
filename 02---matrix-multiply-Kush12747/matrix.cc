/*  Kush Gandhi
*   z1968933
*   CSCI 340-PE1
*   Assignment 2
*   9/12/2022
* 
*   I certify that this is my own work and where appropiate an extension
*   of the starter code provided for the assignment.
*/

#include "matrix.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;


/**
*   @brief This function initialize a new object for the matrix class
*   and untilizes the resize method to intiliaze the size of the
*   matrix.
* 
*   @param rows: rows for the matrix
*   @param cols: columns for the matrix
*/
matrix::matrix(unsigned int rows, unsigned int cols)
{
    resize(rows, cols);
}

/**
*   @brief: Resize the mat vector to have rows elements and then resize
*   each of the elements to have the cols elements.
* 
*   @param rows: rows for the matrix
*   @param cols: columns for the matrix
*/
void matrix::resize(unsigned int rows, unsigned int cols)
{
    mat.resize(rows); // calls the resize function

    for (unsigned int i = 0; i < rows; i++) // loop through the rows of mat
    {
        mat[i].resize(cols);
    }
}

/**
*   @brief: Reads the input values given from the input stream is
*   and store them into the 2-dimensional matrix(mat) by using matrix::at()
*   accessor. Also, the number of columns and rows comes from the beginning
*   of the data file and then it will use the resize() method to properly make
*   the dimensions of the matrix by the correct number of rows & columns. Then
*   it will set the values of the matrix by using the extraction operator >> and
*   the matrix::all() accessor.
* 
*   @param is: reads in the input values.
*/
void matrix::load(istream& is)
{
    unsigned int row;
    unsigned int col;

    //read in row and col values
    is >> row;
    is >> col;

    resize(row, col); // call the function to get the matrix dimensions

    for (unsigned int i = 0; i < row; i++) // loops through the rows of mat
    {
        for (unsigned int j = 0; j < col; j++) // loops through the columns of mat
        {
            is >> at(i, j); // uses the accessor to set the values
        }
    }
}

/**
*   @brief: This method prints the the matrix to the console. We can change some
*   elements in here but not all of them will.
* 
*   @param colWidth: how wide the value boxes are printed in the table
*   
*   @bug: If colWidth is set to 11 then the box prints perfect. However, 
*   if you set colWidth to 6 then the box header and footer are not the
*   correct size. But it's still a functional
*   program.
*/
void matrix::print(int colWidth) const
{
    
    // setting the column width
    // can be changed for different size
    colWidth = 11;

    cout << getRows() << "  " << getCols() << "\n\n";

    // loop to print out the dashed header depending on # of columns
    for (unsigned int i = 0; i < getCols(); i++)
    {
        cout << "-------------"; // dashes to complete table
    }
    cout << "-\n"; // needed for making the box format  perfect

    // for loop to iterate through rows  to set up matrix
    for (unsigned int i = 0; i < getRows(); i++)
    {
        // for loop to iterate through columns
	for (unsigned int j = 0; j < getCols(); j++)
        {
            // statement to format the (|) to seperate the numbers
            cout << "|" << setw(colWidth) << at(i, j) << " ";
        }
        cout << "|\n"; // needed for formatting
    }

    // for loop to print the footer from the # of columns
    for (unsigned int i = 0; i < getCols(); i++)
    {
        cout << "-------------"; // same thing from above print statement
    }
    cout << "-\n"; // needed for formatting
}

/**
*   @brief: Implements the matrix mulriplication by using the
*   overloaded operator*
* 
*   @param rhs: right-hand-side of the operator 
*   @return: returns the matrix
*/
matrix matrix::operator*(const matrix& rhs) const
{
    /* We use these pointer varables to obtain the values
    * that we need for the lhs. But the rhs comes from the
    * operator *.
    * - lhs = left hand side 
    * - rhs = right had side
    */
    unsigned int rhs_col = rhs.getCols();
    unsigned int rhs_row = rhs.getRows();
    unsigned int lhs_col = (*this).getCols();
    unsigned int lhs_row = (*this).getRows();
    
    assert(lhs_col == rhs_row); // checks for the dimensions for multiplication

    matrix result(lhs_row, rhs_col); // store the results of the lhs and rhs matrix

    // for loops to iterate through the lhs and rhs
    for (unsigned int i = 0; i < lhs_row; i++) // loop through lhs
    {
        for (unsigned int j = 0; j < rhs_col; j++) // loop through rhs
        {
            for (unsigned int k = 0; k < lhs_col; k++) // loop through lhs
            {
                /* uses this formula C.at(i, j) += A.at(i, k) * B.at(k, j)
                   by the accessor to store the results from the result fuction
                */
                result.at(i, j) += (*this).at(i, k) * rhs.at(k, j);
            }
        }
    }
    return result;
}
