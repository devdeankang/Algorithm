#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void solution52()
{
	int n, p1=0, p2=0, p3=0;
	int min;
	cin >> n;
	vector<int> nums(n);

	nums[0] = 1;

	for (int i = 1; ; i++)
	{		
		min = nums[p1] * 2;

		if (nums[p2] * 3 < min) min = nums[p2] * 3;
		if (nums[p3] * 5 < min) min = nums[p3] * 5;

		if (min == nums[p1] * 2) p1++;
		if (min == nums[p2] * 3) p2++;
		if (min == nums[p3] * 5) p3++;
		
		nums[i] = min;		

		if (i + 1 == n) 
			break;
	}
	
	cout << min;
}