#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void solution70()
{
	//freopen("input.txt", "r", stdin);
	vector<int> map[30];
	vector<int> visited(30, 0), distance(30, 0);
	queue<int> q;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int source, target;
		cin >> source >> target;
		map[source].push_back(target);
	}
	
	q.push(1);
	visited[1] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++)
		{
			if (visited[map[x][i]] == 0)
			{
				visited[map[x][i]] = 1;
				q.push(map[x][i]);

				distance[map[x][i]] = distance[x] + 1;
			}
		}

	}
	
	for (int i = 2; i <= n; i++)
	{
		cout << i << " : " << distance[i] << endl;
	}

}