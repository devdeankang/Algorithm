#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int n82, r82, count82 = 0;
vector<int> arr82(20), res82(20);
vector<bool> dup82(20, false);

void DFS_Permutation(int num)
{
	if (num == r82)
	{
		for (int i = 0; i < num; i++)
		{
			cout << res82[i] << " ";			
		}
		count82++;
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n82; i++)
		{
			if (!dup82[i])
			{
				res82[num] = arr82[i];
				dup82[i] = true;
				DFS_Permutation(num + 1);
				dup82[i] = false;
			}
		}
	}
}

void solution82()
{	
	cin >> n82 >> r82;

	for (int i = 1; i <= n82; i++)
	{
		int val;
		cin >> val;
		arr82[i] = val;
	}

	DFS_Permutation(0);

	cout << count82;
}

int main()
{
	solution82();
}