#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 문자열압축
// https://school.programmers.co.kr/learn/courses/30/lessons/60057

int GetMinimumCount(int v1, int v2)
{
	if (v1 <= v2) return v1;
	else return v2;
}

int GetStringCompressionCount(string s)
{
	int ret = s.length();
	for (int idx = 1; idx <= s.length() / 2; ++idx)
	{
		int position = 0;
		int length = s.length();

		while (true)
		{
			string str = s.substr(position, idx);
			position += idx;

			if (position >= s.length()) break;

			int count = 0;
			while (true)
			{
				if (str.compare(s.substr(position, idx)) == 0)
				{
					++count;
					position += idx;
				}
				else
				{
					break;
				}
			}
			if (count > 0)
			{
				length -= (idx * count);

				if (count < 9) length += 1;
				else if (count < 99) length += 2;
				else if (count < 999) length += 3;
				else length += 4;
			}
		}
		ret = GetMinimumCount(ret, length);
	}
	return ret;
}


int solution(string s)
{
	return GetStringCompressionCount(s);
}
