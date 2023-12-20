#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void D(int n)
{
	if (n == 0) return;
	else
	{
		D(n-1);
		cout << n << " ";
	}
}
	
void solution56()
{
	int n;
	cin >> n;

	D(n);
}