#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Edge
{
	int node;
	int distance;

	Edge(int n, int dis)
	{
		node = n;
		distance = dis;
	}

	bool operator<(const Edge& b)const {
		return node < b.node;
	}
};

int n80, m80;
vector<Edge> edgeData80[30];
vector<int> answer80;

void solution80()
{
	//freopen("input.txt", "rt", stdin);
	int n,m; //
	cin >> n >> m;
	
	n80 = n, m80 = m; //
	int maxIdx = n80 + 1;


	for (int i = 0; i <= maxIdx; i++)
	{
		answer80.push_back(-1);
	}

	for (int i = 0; i < m; i++)
	{
		int start, end, val;
		cin >> start >> end >> val;

		edgeData80[start].push_back(Edge(end, val));
	}
	answer80[0] = 0;
	answer80[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < edgeData80[i].size(); j++)
		{
			int node = edgeData80[i][j].node;
			int prevNode = i;
			int distance = edgeData80[i][j].distance;
			
			if (answer80[prevNode] == -1) continue;

			if (answer80[node] == -1)
			{
				answer80[node] = answer80[prevNode] + distance;
			}
			else
			{
				int minValue = min(answer80[node], answer80[prevNode] + distance);
				if (minValue != answer80[node])
					answer80[node] = answer80[prevNode] + distance;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (answer80[i] == -1)
			printf("%d : impossible\n", i);
		else
			printf("%d : %d\n", i, answer80[i]);
	}
}