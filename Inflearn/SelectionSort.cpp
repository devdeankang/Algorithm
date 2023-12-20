#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 32. 선택정렬
// N개의 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램
// 입력 값 : 자연수 n , 자연수리스트 nList
// 출력 값 : 오름차순으로 정렬된 자연수 리스트 출력


int main()
{
	int n;	
	cin >> n;
	vector<int> nList(n);	

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nList[i] = num;
	}
	
	//라이브러리 사용
	//sort(nList.begin(), nList.end());

	//// 버블정렬
	//for (int i = 0; i < n-1; i++)
	//{
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (nList[i] > nList[j])
	//		{
	//			int tmp = nList[i];
	//			nList[i] = nList[j];
	//			nList[j] = tmp;
	//		}
	//	}
	//}
	
	// 선택정렬
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (nList[j] < nList[min]) min = j;
		}
		swap(nList[min], nList[i]);
	}

	for (int num : nList)
	{
		cout << num << " ";
	}

	return 0;
}