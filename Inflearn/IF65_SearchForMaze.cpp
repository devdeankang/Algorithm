#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct MazeData
{
	int way;	// 0:±æ, 1:º®
	bool visited;
};

int size_65 = 10, count_65 = 0;
vector<vector<MazeData>> mazeGrid(size_65, vector<MazeData>(size_65));


void SearchForMaze(int row, int col)
{
	if (row == 7 && col == 7)
	{
		count_65++;
	}
	else
	{
		int nextRow = row + 1;
		int nextCol = col + 1;
		int prevRow = row - 1;
		int prevCol = col - 1;
		if (nextRow > 7 && nextCol > 7) return;

		if (mazeGrid[nextRow][col].way == 0 && mazeGrid[nextRow][col].visited == false)
		{
			mazeGrid[nextRow][col].visited = true;
			SearchForMaze(row + 1, col);
			mazeGrid[nextRow][col].visited = false;
		}
			
		if (mazeGrid[prevRow][col].way == 0 && mazeGrid[prevRow][col].visited == false)
		{
			mazeGrid[prevRow][col].visited = true;
			SearchForMaze(row - 1, col);
			mazeGrid[prevRow][col].visited = false;
		}
		if (mazeGrid[row][nextCol].way == 0 && mazeGrid[row][nextCol].visited == false)
		{
			mazeGrid[row][nextCol].visited = true;
			SearchForMaze(row, col + 1);
			mazeGrid[row][nextCol].visited = false;
		}

		if (mazeGrid[row][prevCol].way == 0 && mazeGrid[row][prevCol].visited == false)
		{
			mazeGrid[row][prevCol].visited = true;
			SearchForMaze(row, col - 1);
			mazeGrid[row][prevCol].visited = false;
		}
	}
}

void solution65()
{
	for (int i = 0; i < size_65; i++)
	{
		for (int j = 0; j < size_65; j++)
		{
			mazeGrid[i][j].way = 1;
			mazeGrid[i][j].visited = false;
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			int way;
			cin >> way;
			mazeGrid[i][j].way = way;
		}
	}

	mazeGrid[1][1].visited = true;
	SearchForMaze(1, 1);

	cout << count_65;
}