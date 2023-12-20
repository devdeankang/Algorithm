#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

string Get16digitElement(int num)
{
	switch (num)
	{
	case 10: return "A";		
	case 11: return "B";
	case 12: return "C";
	case 13: return "D";
	case 14: return "E";
	case 15: return "F";
	}
	return "";
}

void solution53()
{
	int n, k;
	cin >> n >> k;
	
	stack<int> st;

	while (n > 0)
	{
		st.push(n % k);
		n /= k;
	}
	

	while (!st.empty())
	{
		int num = st.top();

		if (num >= 10) 
			cout << Get16digitElement(num);
		else 
			cout << st.top();

		st.pop();		
	}
}