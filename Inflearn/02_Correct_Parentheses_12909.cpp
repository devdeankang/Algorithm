#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp

bool solution02(string s)
{
	int num = 0;
	queue<char> qChar;
	
	if (s.front() == ')' || s.back() == '(') return false;

	for (char ch : s)
	{
		if (ch == '(')
		{
			qChar.push(ch);
		}
		else
		{
			if (qChar.empty()) return false;
			qChar.pop();
		}
	}
	return qChar.empty();	
}