#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Noise Between Floors
// 최대 연속으로 울린 경보음 횟수
// 입력 값 cnt: 횟수, limit: 경보음 울릴 수치, n개의 경보음수치
// 출력 값 : 최대 경보음 횟수


int main()
{
	int limit, cnt, ret = 0, tmp = 0;		
	cin >> cnt >> limit;			

	for (int i = 0; i < cnt; i++)
	{
		int alarm;		
		cin >> alarm;
		
		if (alarm > limit) tmp++;
		else tmp = 0;

		if (tmp > ret) ret = tmp;
	}	
	
	if (ret == 0) ret = -1;

	cout << ret;

	return 0;
}