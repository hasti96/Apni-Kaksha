#include <bits/stdc++.h>

using namespace std;

class Sudoku
{
public:
	using sudoku_mat = array<array<int, 9>, 9>;

	static bool isValidSudoku(sudoku_mat& sudoku)
	{
		//check row constraint
		for(int i = 0; i < sudoku.size(); i++)
		{
			if(hasDuplicate(sudoku, i, i+1, 0, sudoku.size()))
				return false;
		}
		
		//check col constraint
		for(int i = 0; i < sudoku.size(); i++)
		{
			if(hasDuplicate(sudoku, 0, sudoku.size(), i, i+1))
				return false;
		}
		
		//check grid constraint
		int region_size = sqrt(sudoku.size());

		for(int i=0; i < region_size; i++)
		{
			for(int j=0; j < region_size; j++)
			{
				if(hasDuplicate(sudoku, region_size * i, 
					region_size * (i+1), region_size * j, 
					region_size * (j+1)))
					return false;
			}
		}
		
		return true;
	}

	static bool hasDuplicate(sudoku_mat& sudoku, int row_start, int row_end, int col_start, int col_end)
	{
		array<bool, 9> is_present = {};
		is_present.fill(false);

		for(int i = row_start; i < row_end; i++)
		{
			for(int j= col_start; j < col_end; j++)
			{
				if(sudoku[i][j] != 0 and is_present[sudoku[i][j]])
					return true;
				is_present[sudoku[i][j]] = true;
			}
		}

		return false;
	}

	static bool solveSudoku(sudoku_mat& sudoku)
	{
		return solvePartialSudoku(0, 0, sudoku);
	}

	static bool solvePartialSudoku(int i, int j, sudoku_mat& sudoku)
	{
		if(i == sudoku.size())
		{
			i=0;
			if(j == sudoku.size())
				return true;
		}

		if(sudoku[i][j] != 0)
		{
			return solvePartialSudoku(i+1, j, sudoku);
		}

		for(int val = 0; val <= sudoku.size(); i++)
		{
			if(validToAddVal(i, j, sudoku, val))
			{
				sudoku[i][j] = val;

				if(solvePartialSudoku(i+1, j , sudoku))
				{
					return true;
				}
			}
		}

		sudoku[i][j] = 0;
		return false;
	}

	static bool validToAddVal(int i, int j,sudoku_mat& sudoku, int val)
	{
		//check row constraint
		for(int k = 0; k < sudoku.size(); k++)
		{
			if(sudoku[k][j] == val)
				return false;
		}

		//check col constraint
		for(int k = 0; k < sudoku.size(); k++)
		{
			if(sudoku[i][k] == val)
				return false;
		}

		//check grid constraint
		int region_size = sqrt(sudoku.size());
		int I = i/region_size; int J = j/region_size;

		for(int a=0; a < region_size; a++)
		{
			for(int b=0; b<region_size;b++)
			{
				int row = a + region_size * I;
				int col = b + region_size * J;

				if(sudoku[row][col] == val){
					return false;
				}
			}
		}
		return true;
	}

	static void printSudoku(sudoku_mat& sudoku)
	{
		for(auto i: sudoku)
		{
			for(auto j: i)
				printf("%d ", j);
			printf("\n");
		}
	}
};



int main()
{
	/*
	array<array<int,9>,9> mat = 
		{{
		{5,3,0, 0,7,0, 0,0,0},
		{6,0,0, 1,9,5, 0,0,0},
		{0,9,8, 0,0,0, 0,6,0},

		{8,0,0, 0,6,0, 0,0,3},
		{4,0,0, 8,0,3, 0,0,1},
		{7,0,0, 0,2,0, 0,0,6},

		{0,6,0, 0,0,0, 2,8,0},
		{0,0,0, 4,1,9, 0,0,5},
		{0,0,0, 0,8,0, 0,7,9}
	}};

	cout<< Sudoku::isValidSudoku(mat) <<endl;
	cout<< Sudoku::solveSudoku(mat) << endl;
	Sudoku::printSudoku(mat);

	*/

	int rs = 12.999;
	printf("%f\n", rs);
	return 0;
}