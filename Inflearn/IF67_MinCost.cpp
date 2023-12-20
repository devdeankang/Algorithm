#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int m_67, n_67, min_67;
vector<vector<pair<int, bool>>> grid_67(30, vector<pair<int, bool>>(30, pair<int,bool>(-1, false)));

void SearchMinCost(int v, int sum)
{
	if (v == m_67)
	{
		if (sum < min_67)
		{
			min_67 = sum;
		}
	}
	else
	{
		for (int i = 1; i <= m_67; i++)
		{
			if (grid_67[v][i].first != -1 && grid_67[v][i].second == false)
			{
				grid_67[v][i].second = true;
				SearchMinCost(i, sum + grid_67[v][i].first);
				grid_67[v][i].second = false;
			}
		}
	}
}

void solution67()
{		
	cin >> m_67 >> n_67;
	int max = 0;
	for (int i = 1; i <= n_67; i++)
	{
		int row, col, cost;
		cin >> row >> col >> cost;
		grid_67[row][col].first = cost;
		max += grid_67[row][col].first;
	}
	min_67 = max;
	
	grid_67[1][0].second = true;
	SearchMinCost(1, 0);	
	
	cout << min_67;
}	