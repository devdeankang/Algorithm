#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void solution73()
{
	priority_queue<int> pQ;

	while (true)
	{
		int node;
		cin >> node;

		if (node == -1) break;
		if (node == 0)
		{
			if (pQ.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << pQ.top() << endl;
				pQ.pop();
			}
		}
		pQ.push(node);
	}
}