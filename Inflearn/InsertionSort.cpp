#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

 36. 삽입정렬
 삽입정렬로 정수 리스트를 오름차순으로 정렬하시오.
 입력 값 : 숫자 개수 n , 정수 리스트 numList
 출력 값 : 오름차순 정렬된 리스트

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

	for (int i = 0; i < n - 1; i++)
	{
		for (int curr = i + 1; curr > 0; curr--)
		{
			int prev = curr - 1;
			if (numList[curr] < numList[prev]) swap(numList[curr], numList[prev]);
			else break;
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		cout << numList[i] << " ";
	}


	return 0;
}