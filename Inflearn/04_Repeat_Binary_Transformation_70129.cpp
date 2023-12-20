#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/70129


string GetBinaryString(int number)
{
	string ret = "";
	while (number >= 2)
	{
		if (number % 2 == 0) ret += '0';
		else ret += '1';

		number /= 2;
	}
	ret += '1';
	return ret;
}

vector<int> solution04(string s) 
{
	vector<int> answer;
	int transformationCnt = 0, zeroCount = 0;
		
	while (s != "1")
	{
		int oneCount = 0;
		for (char ch : s)
			if (ch == '1') oneCount++;

		zeroCount += s.length() - oneCount;				
		transformationCnt++;

		s = GetBinaryString(oneCount);
	}
	answer.push_back(transformationCnt);
	answer.push_back(zeroCount);
	return answer;
}