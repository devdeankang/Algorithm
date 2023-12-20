#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Anagram(아나그램 : 구글 인터뷰 문제)
// 문자열 두 개 받아서 서로 같은 문자열 요소를 가지고 있으면 YES, 그렇지 않으면 NO 출력


unordered_map<string, int> wordCntTable;

void SetWordTable(string str)
{
	if (str.empty()) return;

	for (char ch : str)
	{
		string tmp;
		tmp.push_back(ch);
		if (wordCntTable.find(tmp) == wordCntTable.end())
		{
			wordCntTable.insert({ tmp, 1 });
		}
		else
		{
			wordCntTable[tmp]++;
		}
	}
	return;
}

bool IsAnagram(unordered_map<string, int> _wordCntTable)
{
	for (auto pair : _wordCntTable)
	{
		if (pair.second % 2 != 0)
		{
			return false;
		}
	}

	return true;
}

int main() {
	string str1 = "", str2 = "";
	string YES = "YES";
	string NO = "NO";

	cin >> str1;
	cin >> str2;

	SetWordTable(str1);
	SetWordTable(str2);

	if (IsAnagram(wordCntTable) == true)
	{
		cout << YES;
	}
	else
	{
		cout << NO;
	}

	return 0;
}