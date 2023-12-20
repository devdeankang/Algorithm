#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;


void solution55()
{
	int n;
	cin >> n;
	int size = n + 2;

	stack<int> st;
	vector<int> data(size);
	vector<char> result;

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		data[i] = tmp;
	}

	int idx = 1, ans = 1;
	while (ans <= n)
	{
		if (idx - 1 > n)
		{
			cout << "impossible";
			return;
		}

		if (st.empty() || st.top() != ans)
		{
			st.push(data[idx++]);
			result.push_back('P');
		}
		else if (st.top() == ans)
		{
			result.push_back('O');			
			st.pop();
			ans++;
		}

	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}

}