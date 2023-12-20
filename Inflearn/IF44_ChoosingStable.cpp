#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int GetCount(int n, int length, vector<int> stables)
{	
	int count = 1;
	int stableNum = stables[0];
	for (int i = 1; i < n; i++)
	{
		if (stables[i] - stableNum >= length)
		{
			count++;
			stableNum = stables[i];
		}
	}
	return count;
}

void solution44()
{
	int answer = 0;
	int n = 0, c;
	vector<int> stables;
	

	cin >> n >> c;
	int prev = n - 1;
	for (int i = 0; i < n; i++)
	{
		int stable = 0;
		cin >> stable;
		stables.push_back(stable);
	}
	sort(stables.begin(), stables.end());

	int start = 1;
	int end = stables[prev];
	int pivot;

	while (start <= end)
	{
		pivot = (start + end) / 2;
		if (GetCount(n, pivot, stables) >= c)
		{
			answer = pivot;
			start = pivot + 1;
		}
		else
		{
			end = pivot - 1;
		}
	}
	cout << answer;
}