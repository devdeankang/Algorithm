#include <iostream>
#include <vector>

using namespace std;


void solution45()
{
	int answer = 0;
	int n, k;
	vector<bool> princes;	

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		princes.push_back(true);		
	}

	int exceptionCnt = 0;
	int cnt = 0;
	int idx = 0;
	while (true)
	{
		if (princes[idx] == 0)
		{
			cnt++;
			if (cnt == k)
			{
				princes[idx] = false;
				cnt = 0;
				exceptionCnt++;
			}
		}
		idx++;

		if (idx > n - 1)
			idx = 0;

		if (exceptionCnt == n - 1) break;
	}

	for (int i = 0; i<n; i++)
	{
		if (princes[i] == true)
		{
			answer = i + 1;
			cout << answer;
			return;
		}
	}	
}