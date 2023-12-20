#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution40()
{
	vector<int> a, b, result;	
	int aSize = 0, bSize = 0;

	cin >> aSize;	
	for (int i = 0; i < aSize; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}

	cin >> bSize;	
	for (int i = 0; i < bSize; i++)
	{
		int num;
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
		
	int i = 0, j = 0;	
	while (i< aSize && j< bSize)
	{
		if (a[i] == b[j])
		{
			result.push_back(a[i]);			
			i++;
			j++;
		}
		else if (a[i] > b[j])
		{
			j++;
		}
		else if (a[i] < b[j])
		{
			i++;
		}
	}


	for (int num : result)
	{
		cout << num << " ";
	}

}