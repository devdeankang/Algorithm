#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 27. N Factorial
// N!을 이용해서 입력값 n이 주어지면 2, 3 ,5 , 7 , 11 과 같이 소수들의 개수를 출력
// 입력 값 : n은 정수 값
// 출력 값 : 소수들의 개수 (2, 3, 5 ,7, 11) 

map<int, int> primeNumMap;

void SetPrimeNumMap(int num)
{
	bool hasPrimeNumber = false;
	for (auto primePair : primeNumMap)
	{
		if (primePair.first == num)
		{
			hasPrimeNumber = true;
			primeNumMap[primePair.first]++;
			break;
		}
	}
	if (hasPrimeNumber == false) primeNumMap.insert({ num, 1 });
}

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		int tmp = i;
		int j = 2;
		while (tmp != 1)
		{
			if (tmp % j == 0)
			{
				tmp /= j;
				SetPrimeNumMap(j);
			}
			else
			{
				j++;
			}
		}
	}

	cout << n << "! = ";
	for (auto primePair : primeNumMap)
	{
		cout << primePair.second << " ";
	}
	

	return 0;
}

// 문제핵심
// 38 ~ 54 라인 :  소수만 뽑아서 map에 세팅하는거