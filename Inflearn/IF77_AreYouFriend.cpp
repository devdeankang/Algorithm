#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// Union & Find

vector<int> relationships77(1001);

int Find77(int num)
{
	if (relationships77[num] == num)
		return num;
	else
		return relationships77[num] = Find77(relationships77[num]);
}

void Union77(int a, int b)
{
	a = Find77(a);
	b = Find77(b);

	if (a != b)
		relationships77[a] = b;
}


void solution77()
{
	int n, m, stuA, stuB;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		relationships77[i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		Union77(a, b);
	}

	cin >> stuA >> stuB;

	if (Find77(stuA) == Find77(stuB))
		cout << "YES";
	else
		cout << "NO";

}