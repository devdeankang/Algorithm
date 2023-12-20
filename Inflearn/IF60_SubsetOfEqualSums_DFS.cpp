#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool isEqualSubset = false;
void EqualSubset(int count, int idx, int subsetSum, vector<int> arr, int sum)
{		
	if (idx == count)
	{
		if (subsetSum == sum - subsetSum)
		{
			isEqualSubset = true;
			return;
		}

	}
	else
	{
		EqualSubset(count, idx + 1, subsetSum + arr[idx], arr, sum);
		EqualSubset(count, idx + 1, subsetSum, arr, sum);
	}
}

void solution60()
{
	string YES = "YES", NO = "NO";

	int n, sum = 0;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		sum += tmp;
		arr[i] = tmp;
	}

	EqualSubset(n, 0, 0, arr, sum);

	if(isEqualSubset == true)
		cout << YES;
	else
		cout << NO;

}