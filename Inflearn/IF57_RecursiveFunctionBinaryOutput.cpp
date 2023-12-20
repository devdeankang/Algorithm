#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void ConvertBinary(int n)
{
	if (n / 2 <= 1)
	{
		if (n / 2 != 0) cout << n / 2;

		cout << n % 2;
		return;
	}
	else
	{
		ConvertBinary(n / 2);
		cout << n % 2;
	}
}

void solution57()
{
	int n;
	cin >> n;

	ConvertBinary(n);
}