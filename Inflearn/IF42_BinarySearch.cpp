#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution42()
{
	int n, selectedNum, answer = -1;
	vector<int> nums;

	cin >> n >> selectedNum;	

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());
	
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] == selectedNum)
		{
			answer = i+1;
			break;
		}
	}
	
	cout << answer;
}