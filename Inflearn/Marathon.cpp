#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 26. Marathon
// 마라톤(주어진 입력 값 순서대로 현 시점 달리기 순위이며 정수값은 능력치, 앞에 있는 선수보다 능력치가 높으면 따라잡기 가능 )
// 입력 값 : n은 마라톤 참여 선수의 수, 마라톤 선수 능력리스트 statsList
// 출력 값 : 최선의 등수들을 출력


int main()
{
	int n;
	cin >> n;
	vector<int> statsList(n);
	vector<int> hightestRankList(n);

	for (int i = 0; i < n; i++)
	{
		int stats;
		cin >> stats;
		statsList[i] = stats;
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		int curStats = statsList[i];
		int hightestRank = i + 1;

		for (int j = i; j >= 0; j--)
		{
			if (statsList[j] < curStats) hightestRank--;
		}

		hightestRankList[i] = hightestRank;
	}

	for (int i = 0; i < n; i++)
	{
		cout << hightestRankList[i] << " ";
	}

	return 0;
}