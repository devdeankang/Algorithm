#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// ÈÄº¸Å°
// https://programmers.co.kr/learn/courses/30/lessons/42890
// **err


vector<vector<string>> relationArr;
unordered_set<string> minimum;
int answer = 0;

bool IsMinimum(string selected, string maxStr, int cur)
{
	if (selected.size() == maxStr.size()) return false;

	for (int i = cur; i < maxStr.size(); i++)
	{
		selected.push_back(maxStr[i]);
		if (minimum.count(selected))
		{
			return true;
		}
		else
		{
			bool isSelectedMinimum = IsMinimum(selected, maxStr, i + 1);
			if (isSelectedMinimum == true) return true;
		}
		selected.pop_back();
	}
	return false;
}

void dfs(vector<int> selected, int maxColumn, string minimumCheck)
{
	if (selected.size() == maxColumn)
	{
		unordered_set<string> u;
		for (int i = 0; i < relationArr.size(); i++)
		{
			string str = "";
			
			for (int curColumn : selected)
			{
				str += relationArr[i][curColumn];
				str.push_back('+');			
			}
			if (u.count(str)) return;
			else u.insert(str);
		}
		answer++;
		minimum.insert(minimumCheck);
		return;
	}
	int start;
	if (selected.size()) start = selected.back() + 1;
	else start = 0;

	for (int i = start; i < relationArr[0].size(); i++)
	{
		selected.push_back(i);
		string toAttribute = "";
		toAttribute.push_back((char)(i + '0'));
		minimumCheck += toAttribute;

		bool isMinimum = IsMinimum("", minimumCheck, 0);

		if (isMinimum == false)
			dfs(selected, maxColumn, minimumCheck);

		minimumCheck.pop_back();
		selected.pop_back();
	}
}



int solution(vector<vector<string>> relation) 
{
	relationArr = relation;
	vector<int> v;
	for (int i = 1; i < relation[0].size(); i++)
	{
		dfs(v, i, "");
	}	
	
	return answer;
}


// 
int main()
{
	vector<vector<string>> inputData = {
		{"100", "ryan", "music", "2"},
		{"200", "apeach", "math", "2"},
		{"300", "tube", "computer", "3"},
		{"400", "con", "computer", "4"},
		{"500", "muzi", "music", "3"},
		{"600", "apeach", "music", "2"} };

	int result = solution(inputData);
}