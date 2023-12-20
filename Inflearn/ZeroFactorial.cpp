#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 28. zero Factorial
// 팩토리얼의 값에서 1의 자리부터 연속적으로 0이 몇 개 있는지 구하는 프로그램
// 입력 값 : n은 정수 값
// 출력 값 : 1의 자리부터 연속된 0의 개수


int main()
{
	// 2*5 = 10 이기 때문에 10^n 
	// 2,5의 개수 중 최소값이 정답

	int n;
	cin >> n;
	int num2 = 0;
	int num5 = 0;

	for (int i = 2; i <= n; i++)
	{
		int tmp = i;
		int j = 2;
		while (j <= tmp)
		{
			if (tmp % j == 0)
			{
				switch (j)
				{
				case 2:
					num2++;
					break;
				case 5:
					num5++;
					break;
				default:
					break;
				}

				tmp /= j;
			}
			else j++;
		}
	}

	cout << min(num2, num5);

	return 0;
}