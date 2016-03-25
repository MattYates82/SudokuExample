#include <iostream>
#include "SuCheck.hpp"

using std::cout;
using std::endl;

int main(){

//The board below is valid
int firstSudoku[9][9] =  {{5, 3, 0, 0, 7, 0, 0, 0, 0},
			  {6, 0, 0, 1, 9, 5, 0, 0, 0},
			  {0, 9, 8, 0, 0, 0, 0, 6, 0},
			  {8, 0, 0, 0, 6, 0, 0, 0, 3},
			  {4, 0, 0, 8, 0, 3, 0, 0, 1},
			  {7, 0, 0, 0, 2, 0, 0, 0, 6},
			  {0, 6, 0, 0, 0, 0, 2, 8, 0},
			  {0, 0, 0, 4, 1, 9, 0, 0, 5},
			  {0, 0, 0, 0, 8, 0, 0, 7, 9}};
//This board contains a duplicate '7' in the first row

int secondSudoku[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 7},
                          {6, 0, 0, 1, 9, 5, 0, 0, 0},
                          {0, 9, 8, 0, 0, 0, 0, 6, 0},
                          {8, 0, 0, 0, 6, 0, 0, 0, 3},
                          {4, 0, 0, 8, 0, 3, 0, 0, 1},
                          {7, 0, 0, 0, 2, 0, 0, 0, 6},
                          {0, 6, 0, 0, 0, 0, 2, 8, 0},
                          {0, 0, 0, 4, 1, 9, 0, 0, 5},
                          {0, 0, 0, 0, 8, 0, 0, 7, 9}};

SuCheck validate(firstSudoku);
bool check = validate.checkBoard();

if (check==false)
	cout << "The board is not valid. Try again." << endl;
else
	cout << "The board is valid." << endl;


SuCheck secondValidate(secondSudoku);
bool checkTwo = secondValidate.checkBoard();

if (checkTwo==false)
        cout << "The board is not valid. Try again." << endl;
else
        cout << "The board is valid." << endl;

return 0;


}
