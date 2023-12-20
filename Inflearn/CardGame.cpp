#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// CardGame
// 카드게임
// 입력 값 : 0~9까지 순서의 숫자 두 쌍(A,B)
// 출력 값 : 합계가 이긴 사람 A,B 비기면 D

int* aCards;
int* bCards;

int* InputCardArray()
{
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}
	return arr;
}

int GetPoint(int a, int b)
{
	// 승리:3점, 동점:1점
	if (a == b) return 1;
	else if (a > b) return 3;
	else return 0;
}

char GetWinner(bool draw)
{
	// 총 점이 반드시 같을 경우

	char ret = 'D';
	if (draw == false) return '-1';
	
	for (int i = 9; i >= 0; i--)
	{	
		if (GetPoint(aCards[i], bCards[i]) == 1) continue;
		else if (GetPoint(aCards[i], bCards[i]) == 3)
		{
			ret = 'A';
			break;
		}
		else if (GetPoint(aCards[i], bCards[i]) == 0)
		{
			ret = 'B';
			break;
		}		
	}
	return ret;
}

char GetWinner(int a, int b)
{
	char ret;
	if (a == b) ret = GetWinner(true);
	else if (a > b) ret = 'A';
	else ret = 'B';

	return ret;
}

int main()
{
	int aPoint = 0, bPoint = 0;
	aCards = InputCardArray();
	bCards = InputCardArray();

	for (int i = 0; i < 10; i++)
	{
		aPoint += GetPoint(aCards[i], bCards[i]);
		bPoint += GetPoint(bCards[i], aCards[i]);
	}

	cout << aPoint << " " << bPoint << endl;
	
	cout << GetWinner(aPoint, bPoint);

	return 0;
}