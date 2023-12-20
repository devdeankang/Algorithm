#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution41()
{
	int n;
	cin >> n;
	vector<vector<int>> results;
	int max = n / 2 + 1;
	int count = 0;

	for (int i = 1; i <= max; i++)
	{
		int sum = 0;
		vector<int> res;
		for (int j = i; j <= max; j++)
		{
			if (sum >= n) break;
			sum += j;
			res.push_back(j);
		}
		if (sum == n)
		{
			count++;
			results.push_back(res);
		}
	}

	for (int i = results.size()-1; i >= 0; i--)
	{
		for (int j = 0; j < results[i].size(); j++)
		{
			cout << results[i][j];

			if (j == results[i].size() - 1)
				cout << " = " << n;
			else
				cout << " + ";
		}
		cout << endl;
	}
	cout << count;
}