#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/12941?language=cpp

int solution03(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.rbegin(), A.rend());
	sort(B.begin(), B.end());
	
	for (int i = 0; i < A.size(); i++)
	{
		answer += (A[i] * B[i]);
	}

	return answer;
}