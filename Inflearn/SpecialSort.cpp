#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 35. Special Sort (구글 인터뷰)
// 음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야한다. 또한 양의 정수와 음의 정수의 순서에는 변함이 없어야 한다
// 입력 값 : 숫자 개수 n , 양수 리스트 postiveList, 음수 리스트 negativeList
// 출력 값 : 음의 정수, 양의 정수 정렬

int main()
{
	int n;
	cin >> n;
	vector<int> positiveList;
	vector<int> negativeList;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num > 0) positiveList.push_back(num);
		else negativeList.push_back(num);
	}

	vector<int> numList;
	
	for (auto i : negativeList) numList.push_back(i);
	for (auto i : positiveList) numList.push_back(i);


	for (int i = 0; i < numList.size(); i++)
	{
		cout << numList[i] << " ";
	}

	return 0;
}