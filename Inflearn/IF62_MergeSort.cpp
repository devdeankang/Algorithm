#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n62;
int arr62[101], temp62[101];

void DivideConquer(int left, int right)
{
	int mid, p1, p2, p3;
	if (left < right)
	{
		mid = (left + right) / 2;
		DivideConquer(left, mid);
		DivideConquer(mid + 1, right);

		p1 = left;
		p2 = mid + 1;
		p3 = left;

		while (p1 <= mid && p2 <= right)
		{
			if (arr62[p1] < arr62[p2]) temp62[p3++] = arr62[p1++];
			else temp62[p3++] = arr62[p2++];
		}

		while (p1 <= mid) temp62[p3++] = arr62[p1++];
		while (p2 <= right) temp62[p3++] = arr62[p2++];

		for (int i = left; i <= right; i++)
		{
			arr62[i] = temp62[i];
		}
	}
}

void solution62()
{
	cin >> n62;
	for (int i = 0; i < n62; i++)
	{
		int tmp;
		cin >> tmp;
		arr62[i] = tmp;
	}

	DivideConquer(0, n62 - 1);

	for (int i = 0; i < n62; i++)
	{
		cout << arr62[i] << " ";
	}
}