/*Sudoku Checker Specification File
**Michael Lewis and Matt Yates
**Problem 6.14 - Elements of Programming Interviews */

#include <iostream>
#ifndef SUCHECK_HPP
#define SUCHECK_HPP

class SuCheck
{

private:

	bool rowCheck, columnCheck, subBoardCheck;
	bool boardCheck;
	int suBoard[9][9];
	bool checkRows();
	bool checkColumns();
	bool checkSubBoards();

public:

	SuCheck(int array[9][9]);
	bool checkBoard();

};
#endif
