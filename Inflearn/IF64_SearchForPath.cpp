#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n_64, m_64, count_64 = 0;
vector<int> visited_64;
vector<vector<int>> arr_64;

void SearchForPath(int v)
{
	if (v == n_64)
	{
		count_64++;
	}
	else
	{
		for (int i = 0; i <= n_64; i++)
		{
			if (arr_64[v][i] == 1 && visited_64[i] == 0)
			{
				visited_64[i] = 1;
				SearchForPath(i);
				visited_64[i] = 0;
			}
		}
	}
}

void solution64()
{	
	cin >> n_64 >> m_64;
	
	int size = n_64 + 1;
	for (int i = 0; i < size; i++)
	{
		visited_64.push_back(0);
		vector<int> temp;
		for (int j = 0; j < size; j++)
		{
			temp.push_back(0);
		}
		arr_64.push_back(temp);
	}

	for (int i = 0; i < m_64; i++)
	{
		int row, col;
		cin >> row >> col;

		arr_64[row][col] = 1;
	}

	visited_64[1] = 1;
	SearchForPath(1);

	cout << count_64;
}