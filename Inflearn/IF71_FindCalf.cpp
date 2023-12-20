#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

void solution71()
{
	int s, e, pos, way[3] = {1,-1,5};
	bool hasAnswer = false;
	vector<int> distance(10001, 0);	// 인덱스가 위치, 값이 이동횟수
	queue<int> q;

	cin >> s >> e;

	q.push(s);
	distance[s] = 1;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

				
		for (int i = 0; i < 3; i++)
		{
			pos = current + way[i];
			if (pos < 1 || pos > 10000) continue;

			if (pos == e)
			{
				cout << distance[current];
				hasAnswer = true;
				break;
			}

			if (distance[pos] == 0)
			{
				distance[pos] = distance[current] + 1;
				q.push(pos);				
			}
		}
		if (hasAnswer == true) break;
	}

}