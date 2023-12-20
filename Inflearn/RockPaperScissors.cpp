#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Rock-Paper-Scissors
// 가위바위보
// 입력 값 n: 가위바위보 게임 횟수, A가 낸 정보, B가 낸 정보
// 1:가위 / 2:바위 / 3:보
// 출력 값 : 승자 출력(A,B 비길경우 D)


int* SetRCPArray(int n)
{
	int* ret = new int[n];
	for (int i = 0; i < n; i++)
	{
		int rcp;
		cin >> rcp;
		ret[i] = rcp;
	}

	return ret;
}

char GetWinner(int userA, int userB)
{
	if (userA == userB) return 'D';
	else if (userA == 1 && userB == 3) return 'A';
	else if (userA == 2 && userB == 1) return 'A';
	else if (userA == 3 && userB == 2) return 'A';
	else return 'B';
}

int main()
{
	int n;
	cin >> n;
	int* aList = new int[n];
	int* bList = new int[n];

	aList = SetRCPArray(n);
	bList = SetRCPArray(n);

	for (int i = 0; i < n; i++)
	{
		char ret = GetWinner(aList[i], bList[i]);
		cout << ret << endl;
	}

	return 0;
}