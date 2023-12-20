#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int GetSumOfTree(vector<vector<int>> grid, int row, int col, int selectedRow, int selectedCol)
{
	int sum = 0;

	for (int i = row; i < selectedRow+row; i++)
	{
		for (int j = col; j < selectedCol+col; j++)
		{
			sum += grid[i][j];
		}
	}

	return sum;
}

void solution50()
{

	int gridRow, gridCol, territoryRow, territoryCol;
	int maxCount = 0;
		
	cin >> gridRow;
	cin >> gridCol;

	vector<vector<int>> grid(gridRow, vector<int>(gridCol, 0));

	for (int i = 0; i < gridRow; i++)
	{
		for (int j = 0; j < gridCol; j++)
		{
			int tmp = 0;
			cin >> tmp;
			grid[i][j] = tmp;
		}
	}

	cin >> territoryRow;
	cin >> territoryCol;

	for (int i = 0; i <= gridRow - territoryRow; i++)
	{
		for (int j = 0; j <= gridCol - territoryCol; j++)
		{
			int sum = GetSumOfTree(grid, i, j, territoryRow, territoryCol);
			if (maxCount < sum)
				maxCount = sum;
		}
	}

	cout << maxCount;
}