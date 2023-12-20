#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 34. 버블정렬
// 정수값들이 주어지면 버블정렬하라
// 입력 값 : 숫자 개수 n , 숫자 리스트 numList
// 출력 값 : 정렬된 숫자 리스트를 출력

int main()
{
	int n;
	cin >> n;
	vector<int> numList(n);

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		numList[i] = num;
	}

	// Time Complexity : O(n^2)
	for (int i = 0; i < n-1; i++)
	{
		for (int currentIdx = 0; currentIdx < n-1; currentIdx++)
		{
			int nextIdx = currentIdx + 1;
			if(numList[currentIdx] > numList[nextIdx]) swap(numList[currentIdx], numList[nextIdx]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << numList[i] << " ";
	}

	return 0;
}