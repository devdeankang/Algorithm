#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// nCr
// n! / ( r! * (n-r) )

int Factorial(int n)
{
	if (n == 1) return 1;
	else
	{
		return n * Factorial(n - 1);
	}
}

void solution76()
{
	int n, r;
	cin >> n >> r;

	cout << Factorial(n) / (Factorial(r) * (n - r));
}
