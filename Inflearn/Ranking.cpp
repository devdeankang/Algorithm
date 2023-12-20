#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#include <sstream>
#include <time.h>

using namespace std;

// 25. Ranking
// 석차 구하기(수학 점수 입력하고 학생의 석차를 입력된 순서대로 출력하는 프로그램)
// 입력 값 : n은 정수의 개수, 수학점수 scoreList
// 출력 값 : 입력된 수학점수의 순위를 출력한다


int main()
{
	int n;
	cin >> n;
	vector<int> scoreList(n);

	for (int i = 0; i < n; i++)
	{
		int score;
		cin >> score;
		scoreList[i] = score;
	}

	vector<int> sortedScores = scoreList;
	sort(sortedScores.begin(), sortedScores.end(), greater<>());

	unordered_map<int, int> scoreRankMap;
	for (int i = 0; i < n; i++)
	{
		scoreRankMap.insert({sortedScores[i], i+1});
	}

	for (int i = 0; i < n; i++)
	{	
		cout << scoreRankMap.at(scoreList[i]) << " ";
	}	

	return 0;
}