#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Angry Person
// 분노유발자_ 종렬로 앉은 학생들 중 뒤에앉은 학생들 모두보다 키 큰 사람 수 찾기
// 입력 값 n: 한 줄에 앉는 학생 수, heightList: 앉은 학생들의 키
// 출력 값 : 분노유발자 수


int main()
{
	int n, ret = 0;
	int* heightList;
	cin >> n;
	heightList = new int[n];

	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		heightList[i] = height;
	}
	
	int maxValue = heightList[n - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		if (heightList[i] > maxValue)
		{
			maxValue = heightList[i];
			ret++;
		}
	}

	cout << ret;

	return 0;
}