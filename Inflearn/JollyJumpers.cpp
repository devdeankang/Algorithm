#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 24. Jolly Jumpers
// 유쾌한 점퍼 (서로 인접해 있는 두 수의 차가 1에서 n-1까지 값을 모두 갖는 경우)
// 입력 값 : n은 정수의 개수, 정수 numList
// 출력 값 : 유쾌한 점퍼면 YES출력, 아니면 NO출력


int main()
{
	int n;
	cin >> n;
	vector<int> numList(n);
	vector<int> jollyJumpers;	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		numList[i] = num;
	}

	
	for (int i = 0; i < n-1; i++)
	{
		int next = i + 1;
		int value = abs(numList[i] - numList[next]);
		jollyJumpers.push_back(value);
	}
	
	sort(jollyJumpers.begin(), jollyJumpers.end());

	for (int i = 0; i < n-1; i++)
	{
		if (jollyJumpers[i] != i + 1)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}