#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void solution72()
{
	queue<int> q;
	int n, k, count = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		count++;

		if (count == k)
		{
			count = 0;			
			q.pop();
		}
		else
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
	}

	cout << q.front();
}