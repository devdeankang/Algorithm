#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int unf78[10001];

int Find78(int v)
{
	if (v == unf78[v])
		return v;
	else
		return unf78[v] = Find78(unf78[v]);
}

void Union78(int a, int b)
{
	a = Find78(a);
	b = Find78(b);

	if (a != b)
		unf78[a] = b;
}

void solution78()
{
	struct Edge
	{
		int v1, v2, val;

		Edge(int a, int b, int v)
		{
			v1 = a;
			v2 = b;
			val = v;
		}

		bool operator<(Edge& b) {
			return val < b.val;
		}
	};

	vector<Edge> connectedRoads;

	int v, e, sum = 0;
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
	{
		unf78[i] = i;		
	}
		
	for (int i = 1; i <= e; i++)
	{
		int a, b, dis;
		cin >> a >> b >> dis;
		connectedRoads.push_back(Edge(a, b, dis));
	}
	sort(connectedRoads.begin(), connectedRoads.end());

	for (int i = 0; i < e; i++)
	{		
		int a = Find78(connectedRoads[i].v1);
		int b = Find78(connectedRoads[i].v2);
		if (a != b)
		{
			sum += connectedRoads[i].val;
			Union78(connectedRoads[i].v1, connectedRoads[i].v2);
		}
	}	

	cout << sum;
}