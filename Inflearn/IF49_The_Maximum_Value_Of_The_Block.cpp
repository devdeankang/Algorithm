#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solution49()
{
	int result = 0;
	int n;
	cin >> n;

	vector<int> frontView;
	vector<int> rightView;

	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		frontView.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		rightView.push_back(tmp);
	}
	reverse(rightView.begin(), rightView.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (frontView[i] < rightView[j])
				result += frontView[i];
			else
				result += rightView[j];
		}
	}

	cout << result;
	
}