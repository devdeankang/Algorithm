#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 22. MaxValue Of Temperature
// 온도의 최댓값
// 입력 값 : n은 전체 날짜의 개수 , k는 1과n사이의 정수로 합을 구학 위한 연속적인 날짜의 수, 빈칸을 사이에 두고 n개의 온도
// 출력 값 : 최대값


int main()
{
	int n, k, max = -1;
	cin >> n >> k;
	vector<int> temperatureList(n);
	for(int i = 0; i < n; i++)
	{
		int temperature;
		cin >> temperature;
		temperatureList[i] = temperature;
	}

	//// 2중 for문 하기 때문에 TimeComplexity걸림	
	//for (int i = 0; i < n - k; i++)
	//{
	//	int sum = 0;
	//	for (int j = i; j < i + k; j++)
	//	{			
	//		sum += temperatureList[j];
	//	}
	//	if (sum > max) max = sum;
	//}

	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += temperatureList[i];
	}
	max = sum;

	for (int i = k; i < n; i++)
	{
		int previous = i - k;
		sum += (temperatureList[i] - temperatureList[previous]);
		if (sum > max) max = sum;
	}

	cout << max;

	return 0;
}