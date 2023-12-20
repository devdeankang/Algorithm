#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


void solution69()
{
	vector<int> grid[10];
	int q[100], visited[10];
	int front = -1, back = -1;

	for (int i =0; i<100; i++)
	{
		q[i] = 0;

		if (i < 10)
			visited[i] = 0;
	}

	for (int i = 1; i <= 6; i++)
	{
		int m, n;
		cin >> m >> n;
		grid[m].push_back(n);
		grid[n].push_back(m);
	}

	q[++back] = 1;
	visited[1] = 1;

	while (front < back)
	{
		int x = q[++front];
		cout << x << " ";
		for (int i = 0; i < grid[x].size(); i++)
		{
			if (visited[grid[x][i]] == 0)
			{
				visited[grid[x][i]] = 1;
				q[++back] = grid[x][i];
			}
		}
	}
}