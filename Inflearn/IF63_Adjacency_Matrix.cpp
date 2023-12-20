#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solution63()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{
		int row, col, val;
		cin >> row >> col >> val;
		row--;
		col--;

		arr[row][col] = val;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}