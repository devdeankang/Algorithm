#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

void solution54()
{
	int tmp = 0;
	string str, res = "";
	cin >> str;

	stack<char> st;
	for (char ch : str)
	{
		st.push(ch);
	}

	while (!st.empty())
	{
		char ch = st.top();

		if (ch == ')') tmp++;
		else if (ch == '(') tmp--;

		if (tmp < 0) break;
		st.pop();
	}

	if (tmp != 0) res = "NO";
	else res = "YES";

	cout << res;

}