#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 23. Incremental Sequence
// 연속적인 증가수열
// 입력 값 : n은 자연수의 개수, 숫자열 numList
// 출력 값 : 최대 부분 증가수열의 길이


int main()
{
	int n, max = -1;
	cin >> n;
	vector<int> numList(n);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		numList[i] = num;
	}

	int cnt = 1;
	for (int i = 0; i < n-1; i++)
	{
		int next = i + 1;

		int prev = numList[i];
		int curr = numList[next];
		if (prev <= curr)
		{
			cnt++;
			if (max < cnt) max = cnt;
		}
		else
		{
			cnt = 1;
		}		
	}

	cout << max;

	return 0;
}