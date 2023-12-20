#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 37. Least Recently Used(카카오 캐시 문제 변형)
// 철수의 컴퓨터 캐시메모리 사용 규칙이 LRU알고리즘을 따른다.
// 가장 최근에 사용되지 않은 것을 제거하는 알고리즘이다. (만약 2 3 1 6 7 순서면 2가 가장 최근에 쓰인거 7이 가장 오래 쓰이지 않은 것)
// Cache Miss : 해야할 작업이 캐시에 없는 상태로 위 상태에서 만약 새로운 작업인 5번 작업을 CPU가 사용하면 Cache miss가 되고 모든 작업이 뒤로 밀리고 5번 작업은 캐시의 맨 앞에 위치한다 따라서 5 2 3 1 6 이 됨
// Cache Hit : 해야할 작업이 캐시에 있는 상태로 위 상태에서 만약 3번 작업을 한다면 Cache Hit이 되고, 6 3 앞에 있는 5 2 작업은 한칸 뒤로 미루고 3번이 맨 앞으로 위치함. 즉, 3 5 2 1 6
// 입력 값 : 캐시의 크기 s, 캐시의 개수 n , 캐시 리스트 cacheList
// 출력 값 : 가장 최근에 사용된 작업부터 차례로 출력

int main()
{
	int n, s;
	cin >> s;
	cin >> n;
	vector<int> cacheList(n);
	vector<int> retList(s);

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		cacheList[i] = num;
	}

	int dest = n - s;
	for (int i = n - 1; i >= dest; i--)
	{
		bool isDuplicated = false;
		for (int num : retList)
		{
			if (cacheList[i] == num)
			{
				dest--;
				isDuplicated = true;
				break;
			}
		}
		if (isDuplicated == false)
		{
			retList.push_back(cacheList[i]);
			cout << cacheList[i] << " ";
		}	

	}


	return 0;
}