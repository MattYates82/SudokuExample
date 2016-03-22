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
    // Initializes all bools to false (0)
    /*Yates: I always like to set my bools equal to true or false for readability
    Could we do that?  Other than that, I don't have any issues with what you've
    done here.  I will be adding my implementation of checkRows and checkColumns below*/
    
    /*Lewis: Yes, definitely. That sounds like a good idea, I'm still learning the best
    practices and conventions, and that makes sense to me. I've made the change.
    
    Thanks for adding checkRows and checkColumns, looks good to me, I think just what
    might be two minor errors:
    1. In the checkColumns function, the header is currently "checkRows()" instead of
    "checkColumns".
    2. In the outer for loop for the checkColumns function, it has "row++" but I think
    it just needs to be changed to "col++".
    
    I'd make the changes but I'm not sure yet what the best practice is--if I were to
    make them, would I make the changes and then commit directly to the current branch or
    create a new branch? Let me know what you think.*/
    
    rowCheck = columnCheck = subBoardCheck = boardCheck = false;

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
/*****************************************************************************
*                       SuCheck::checkRows                                   *
* Function which iterates through each row of the member 2D array suBoard,   *
* verifying that each element is in [1,9], aside from blanks represented by  *
* 0. Additionally, the function determines if any elements in [1,9] are      *
* repeated.  Returns true if all non-zero elements are in [1,9] with no      *
* repeates.                                                                  *
*****************************************************************************/
bool SuCheck::checkRows()
{
    rowCheck = true;
    for (int row = 0; row < 9; row ++)
        {
            for (int col = 0; col < 9; col++)
                {
                    //Determine if there are any elements not in [0,9]
                    if (suBoard[row][col] < 0 || suBoard[row][col] > 9)
                        rowCheck = false;
                    //Determine if any elements are repeated in current row
                    for (int i = col+1; i < 9; i ++)
                    {
                        if (suBoard[row][col] == suBoard[row][i])
                            rowCheck = false;
                    }
                }
    }
    return rowCheck;
}

/*****************************************************************************
*                       SuCheck::checkColumns                                *
* Function which iterates through each column of the member 2D array suBoard,*
* verifying that each element is in [1,9], aside from blanks represented by  *
* 0. Additionally, the function determines if any elements in [1,9] are      *
* repeated. Returns true if all non-zero elements are in [1,9] with no       *
* repeats.                                                                   *
*****************************************************************************/
bool SuCheck::checkRows()
{
    columnCheck = true;
    for (int col = 0; col < 9; row++)
        {
            for (int row = 0; row < 9; row++)
                {
                    //Determine if there are any elements not in [0,9]
                    if (suBoard[row][col] < 0 || suBoard[row][col] > 9)
                        columnCheck = false;
                    //Determine if any elements are repeated in current row
                    for (int i = row + 1; i < 9; i++)
                    {
                        if (suBoard[row][col] == suBoard[i][col] && suBoard[row][col] != 0)
                            columnCheck = false;
                    }
                }
        }
    return columnCheck;
}
