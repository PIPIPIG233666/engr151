// A Backtracking program in C++ to solve Sudoku problem  
//#include <bits/stdc++.h> 
#include<iostream>
#include <fstream>
using namespace std;


/* TODO: Declare helpter functions if needed, optional*/



/* TODO: implement the function that takes in a 9 by 9 array of ints, 
modifies the grid so that it is filled with no 0s,
and returns whether it is solvable or not */
bool SolveSudoku(int (&grid)[9][9])
{
	/* implement your function here!*/
	return false; 
}


/* A utility function to print grid */
void printGrid(int grid[9][9])
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
	cout << endl;
}


int main()
{
	
	//start out with easy grid!
	int easy[9][9] = { { 1, 2, 3, 0, 5, 6 ,7 ,8, 9 },
	{0, 5, 6, 7, 8, 9, 1, 2, 3},
	{7, 8, 0, 1, 2, 3, 4, 5, 6},
	{2, 1, 4, 3, 6, 5, 0, 9 ,7},
	{3, 0, 5, 8, 9, 7, 2, 1,4},
	{8, 9, 7, 2, 1, 4, 3, 6, 0},
	{5, 3, 1, 6, 4, 2, 9, 0, 8},
	{6 ,4 ,2, 9, 0, 8, 5, 3, 1},
	{9, 7, 8, 0, 3, 1, 6, 4, 2} };

	if (SolveSudoku(easy) == true)
		printGrid(easy);
	else
		cout << "No solution exists" << endl << endl;

	
	//this grid's solution is in the spec for reference
	int A[9][9] = { {1, 0, 0, 3, 0, 0, 0, 8, 0},
				  {3, 0, 0, 9, 0, 0, 6, 0, 0},
				  {0, 0, 0, 7, 4, 8, 1, 0, 5},
				  {4, 2, 6, 0, 0, 0, 7, 0, 0},
				  {0, 7, 8, 4, 0, 9, 3, 6, 0},
				  {0, 0, 3, 0, 0, 0, 4, 5, 8},
				  {2, 0, 1, 8, 9, 4, 0, 0, 0},
				  {0, 0, 4, 0, 0, 6, 0, 0, 9},
				  {0, 3, 0, 0, 0, 5, 0, 0, 6} };
	if (SolveSudoku(A) == true)
		printGrid(A);
	else
		cout << "No solution exists" << endl << endl;

	int B[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
					  {5, 2, 0, 0, 0, 0, 0, 0, 0},
					  {0, 8, 7, 0, 0, 0, 0, 3, 1},
					  {0, 0, 3, 0, 1, 0, 0, 8, 0},
					  {9, 0, 0, 8, 6, 3, 0, 0, 5},
					  {0, 5, 0, 0, 9, 0, 6, 0, 0},
					  {1, 3, 0, 0, 0, 0, 2, 5, 0},
					  {0, 0, 0, 0, 0, 0, 0, 7, 4},
					  {0, 0, 5, 2, 0, 6, 3, 0, 0} };
	if (SolveSudoku(B) == true)
		printGrid(B);
	else
		cout << "No solution exists" << endl << endl;





	int C[9][9] = { {0, 0, 6, 0, 3, 0, 8, 5, 0},
			  {0, 5, 0, 0, 0, 0, 0, 0, 2},
			  {3, 4, 0, 5, 0, 0, 0, 0, 0},
			  {0, 0, 0, 1, 4, 0, 0, 0, 0},
			  {4, 9, 1, 0, 0, 0, 6, 7, 5},
			  {0, 0, 0, 0, 5, 6, 0, 0, 0},
			  {0, 0, 0, 0, 0, 5, 0, 6, 4},
			  {6, 0, 0, 0, 0, 0, 0, 8, 0},
			  {0, 7, 5, 0, 1, 0, 3, 0, 0} };
	if (SolveSudoku(C) == true)
		printGrid(C);
	else
		cout << "No solution exists" << endl << endl;

	
	
	return 0;
}
