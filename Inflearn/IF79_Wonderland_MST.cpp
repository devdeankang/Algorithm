#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;


void solution79()
{
	struct Edge
	{
		int dest;
		int cost;

		Edge(int d, int c)
		{
			dest = d;
			cost = c;
		}

		bool operator<(const Edge& b)const {
			return cost > b.cost;
		}
	};

	int e, v, sum = 0;

	cin >> e >> v;
	vector<pair<int, int>> edgeData[100];
	priority_queue<Edge> pQ;
	bool isVisited[100] = { false, };

	for (int i = 0; i < v; i++)
	{
		int a, b, val;
		cin >> a >> b >> val;
		edgeData[a].push_back(make_pair(b, val));
		edgeData[b].push_back(make_pair(a, val));
	}
	pQ.push(Edge(1, 0));

	while (!pQ.empty())
	{
		Edge edge = pQ.top();
		pQ.pop();

		int node = edge.dest;
		int cost = edge.cost;

		if (!isVisited[node])
		{
			sum += cost;
			isVisited[node] = true;

			for (int i = 0; i < edgeData[node].size(); i++)
			{
				pQ.push(Edge(edgeData[node][i].first, edgeData[node][i].second));
			}
		}
	}

	cout << sum;
}