#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int GetAccumulatedElement(vector<vector<int>> accGrid, int curr, int row, int col)
{
	int prevRow = row - 1;
	int prevCol = col - 1;	

	return curr + accGrid[prevRow][col] + accGrid[row][prevCol] - accGrid[prevRow][prevCol];
}

int GetSumOfSelected(vector<vector<int>> accGrid, int row, int col, int selectedRow, int selectedCol)
{
	int diffCol = col - selectedCol;
	int diffRow = row - selectedRow;
	
	return accGrid[row][col] - accGrid[row][diffCol] - accGrid[diffRow][col] + accGrid[diffRow][diffCol];
}

void solution51()
{
	int gridRow, gridCol, selectedRow, selectedCol;
	int maxCount = 0;

	cin >> gridRow;
	cin >> gridCol;

	int size = gridRow + 1;
	vector<vector<int>> accGrid(size, vector<int>(size, 0));

	for (int i = 1; i <= gridRow; i++)
	{
		for (int j = 1; j <= gridCol; j++)
		{
			int tmp = 0;
			cin >> tmp;
			accGrid[i][j] = GetAccumulatedElement(accGrid, tmp, i, j);			
		}
	}

	cin >> selectedRow;
	cin >> selectedCol;

	for (int i = selectedRow; i <= gridRow; i++)
	{
		for (int j = selectedCol; j <= gridCol; j++)
		{
			int sumOfSelected = GetSumOfSelected(accGrid, i, j, selectedRow, selectedCol);			

			if (maxCount < sumOfSelected)
				maxCount = sumOfSelected;		
		}
	}

	cout << maxCount;
}