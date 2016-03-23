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
    
    rowCheck = columnCheck = subBoardCheck = boardCheck = false;

    int counter = false; // For incrementing contents of arrayCopy
    
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
bool SuCheck::checkColumns()
{
    columnCheck = true;
    for (int col = 0; col < 9; col++)
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

/*****************************************************************************
*                       SuCheck::checkSubBoards                              *
* Function which iterates through each 3 x 3 subBoard of the member 2D array *
* suBoard, verifying that each element is in [1,9], aside from blanks        *
* represented by 0. Additionally, the function determines if any elements in *
* [1,9] are repeated. Returns true if all non-zero elements are in [1,9]     *
* with no repeats.                                                           *
*****************************************************************************/
bool SuCheck::checkSubBoards()
{
    subBoardCheck = true;
    // The rowOffset results in incrementing the subBoard by 3 rows
    // vertically after every 3 arrays are incremented horizontally
    // by the colOffset
    for (int rowOffset = 0; rowOffset < 7; rowOffset += 3)
    {
        // The colOffset results in incrementing each subBoard to the
        // next subBoard to the right (by three columns), and for
        // every 3rd subBoard, back to the subBoard in the first
        // column (and down by 3 rows per the rowOffset.
        for (int colOffset = 0; colOffset < 7; colOffset += 3)
        {
            // Adding the rowOffset to the initialization and test
            // expressions of this for loop will allow for proper
            // incrementing of the subBoard by row.
            for (int row = (0 + rowOffset); row < (3 + rowOffset); row++)
            {
                // Adding the rowOffset to the initialization and test
                // expressions of this for loop will allow for proper
                // incrementing of the subBoard by row.
                for (int col = (0 + colOffset); col < (3 + rowOffset); col++)
                {
                    // Determine if there are any elements not in [0,9]
                    if (suBoard[row][col] < 0 || suBoard[row][col] > 9)
                    {
                        subBoardCheck = false;
                    }
                    // Increment by each row of subBoard.
                    for (int i = (row + rowOffset); i < (3 + rowOffset); i++)
                    {
                        // Increment through each column of each row of subBoard. 
                        for (int j = (col + colOffset); j < (3 + colOffset); j++)
                        {
                            // Testing value "!= 1" instead of 0 because we must be able to
                            // loop back to the first column of the subBoard for each of its
                            // rows, therefore we are not using "i + 1" in the for loop and
                            // therefore the subBoard check will match exactly for its 
                            // starting value.
                            if (suBoard[row][col] == (suBoard[i][j] && suBoard[row][col] != 1))
                            {
                                subBoardCheck = false;
                            }
                        }
                    }
                }
            }
        }
    }
    return subBoardCheck;
}
