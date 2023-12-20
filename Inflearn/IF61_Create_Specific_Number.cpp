#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, m;
int count_61 = 0;
int arr[11];

void CreateSpecificNum(int idx, int num)
{
	if (idx >= n)
	{	
		if (num == m) count_61++;
		return;
	}
	else
	{
		CreateSpecificNum(idx +1, num);
		CreateSpecificNum(idx + 1, num + arr[idx]);
		CreateSpecificNum(idx + 1, num - arr[idx]);
	}
}

void solution61()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	CreateSpecificNum(0, 0);
	
	if (count_61 == 0) count_61 = -1;

	cout << count_61;
}