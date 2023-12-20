#include <iostream>
#include <vector>

using namespace std;

bool IsMoutainTop(vector<vector<int>> ground,int row, int col)
{
	if (row == 0 || col == 0) return false;
	int nextRow = row + 1;
	int nextCol = col + 1;
	int prevRow = row - 1;
	int prevCol = col - 1;

	int value = ground[row][col];

	if (value <= ground[prevRow][col] || value <= ground[nextRow][col]
		|| value <= ground[row][prevCol] || value <= ground[row][nextCol])
		return false;
	else
		return true;
}

void solution47()
{
	int moutainTopCount = 0;

	int n = 0;
	cin >> n;

	int size = n + 2;
	vector<vector<int>> groundHeights(size, vector<int>(size, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp = 0;
			cin >> temp;
			groundHeights[i][j] = temp;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (IsMoutainTop(groundHeights, i, j) == true) moutainTopCount++;
		}
	}

	cout << moutainTopCount;
}