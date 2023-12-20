#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 30. 3의 개수는(large)
// 자연수 N이 입력되면 1부터 N까지의 자연수 중 3의 총 개수를 구하는 프로그램(3<=n<=1b)
// 입력 값 : n은 정수 값
// 출력 값 : n까지의 자연수 중 3의 개수


int main()
{
	// 현재 자릿수의 값이 cur
	// 현재 자릿수의 왼쪽이 left , 오른쪽이 right, k는 현재 자릿수

	int n, left = -1, right, cur, k = 1, count = 0;
	cin >> n;

	while (left != 0)
	{
		left = n / (k * 10);
		cur = (n / k) % 10;
		right = n % k;

		if (cur > 3) count += ((left + 1) * k);
		else if (cur < 3) count += (left * k);
		else count += ( (left * k ) + right+1);
		k *= 10;
	}

	cout << count;

	return 0;
}




// 잘못 품
//int GetPowerOfNum(int num)
//{
//	int power = 0;	
//
//	while (num >= 10)
//	{
//		power++;
//		num /= 10;
//	}
//
//	return power;
//}
//
//int GetCount(int power)
//{
//	return power * pow(10, power - 1);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int cnt = 0;
//		
//	while (n > 10)
//	{
//		int power = GetPowerOfNum(n);
//		cnt += GetCount(power);
//		n -= pow(10, power);
//	}
//
//	if (n > 3) cnt++;
//
//	cout << cnt;
//
//	return 0;
//}