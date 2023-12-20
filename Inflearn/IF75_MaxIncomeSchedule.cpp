#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct Schedule75
{
	int m, d;

	Schedule75(int _m, int _d)
	{
		m = _m;
		d = _d;
	}
};

int CompareByDeadline(Schedule75 a, Schedule75 b)
{
	return a.d > b.d;
}

void solution75()
{	
	int n;
	cin >> n;
	vector<Schedule75> schedules;
	priority_queue<int> pQ;
	int sum = 0;
	int deadline = 10000;

	for (int i = 0; i < n; i++)
	{
		int m, d;
		cin >> m >> d;
		schedules.push_back(Schedule75(m, d));
	}
	sort(schedules.begin(), schedules.end(), CompareByDeadline);
	deadline = schedules[0].d;

	int index = 0;
	while (true)
	{
		for (int i = index; i < n; i++)
		{			
			if (deadline > schedules[i].d) break;
			pQ.push(schedules[i].m);
			index++;
		}
		
		if (!pQ.empty())
		{
			sum += pQ.top();
			pQ.pop();
		}

		deadline--;
		if (index + 1 > n) break;
	}

	cout << sum;
}