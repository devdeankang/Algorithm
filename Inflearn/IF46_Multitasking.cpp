#include <iostream>
#include <vector>

using namespace std;


void solution46()
{
	int n, k, answer = -1;
	vector<int> multitask;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int task;
		cin >> task;
		multitask.push_back(task);
	}

	cin >> k;

	int count = 0;
	int i = 0;
	while (true)
	{
		if (multitask[i] != 0)
		{
			count++;
			multitask[i]--;			
		}
		i++;

		if (i == n) i = 0;

		if (count == k) break;
	}

	int endOfTask = 0;
	for (i; i < n; i++)
	{
		if (multitask[i] != 0) 
		{
			answer = i + 1;
			cout << answer;
			return;
		}
		else
		{
			endOfTask++;
		}

		if (endOfTask == n) break;
		if (i == n - 1) i = 0;
	}

	cout << answer;
}