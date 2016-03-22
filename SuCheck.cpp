/*Sudoku Checker Implementation File
**Michael Lewis and Matt Yates
**Problem 6.14 - Elements of Programming Interviews */

#include "SuCheck.hpp"

/****************************************************************************
*                       SuCheck Constructor                                 *
* Default constructor that takes a pointer to constant int as its single    *
* parameter. Initializes all class member boolean variables to 0. Copies    *
* the array pointed to by parameter into the class member array.            *
*****************************************************************************/
SuCheck::SuCheck(const int* arrayCopy)
{
    // Initializes all bools to 0 (false)
    rowCheck = columnCheck = subBoardCheck = boardCheck = 0;

    int counter = 0; // For incrementing contents of arrayCopy
    
    // Copies the array whose starting address is passed into the function
    // into the member array.
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            suBoard[row][col] = *(arrayCopy + counter);
            counter++;
        }
    }
}
