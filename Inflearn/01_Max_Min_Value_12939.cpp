#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/12939

string solution01(string s)
{	
	int sLength = s.length();
	vector<int> nums;
	string num = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			num += s[i];
		}
		if (s[i] == ' ' || i == s.length() - 1)
		{
			nums.push_back(stoi(num));
			num = "";
		}		
	}

	int min = nums[0];
	int max = nums[0];

	for (int n : nums)
	{
		if (min > n) min = n;
		if (max < n) max = n;
	}

	return to_string(min) + ' ' + to_string(max);
}