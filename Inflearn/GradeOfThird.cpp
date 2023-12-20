#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 33. 3등의 성적은?
// N명의 수학성적이 주어지면 그 중 3등을 한 수학성적을 출력하는 프로그램
// 입력 값 : 성적 개수 n , 성적 리스트recordList
// 출력 값 : 3등의 점수를 출력

int main()
{
	int n;
	cin >> n;
	vector<int> recordList(n);

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		recordList[i] = num;
	}

	//라이브러리 사용
	sort(recordList.begin(), recordList.end(), greater<>());

	int rank = 0;
	for (int i = 1; i < n; i++)
	{
		int prev = i - 1;
		if (recordList[prev] != recordList[i])
		{			
			rank++;
			if (rank == 3) {
				cout << recordList[prev];
				break;
			}
		}
	}

	return 0;
}