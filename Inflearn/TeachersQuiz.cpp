#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Teachers Quiz
// Automatic Sum

vector<unordered_map<int, int>> studentQuestionTable;

void SetStudentMapTable(int studentCnt)
{
	for (int i = 0; i < studentCnt; i++)
	{
		int question, answer;		
		cin >> question >> answer;
		unordered_map<int, int> questionAnswer;
		questionAnswer.insert({ question, answer });
		studentQuestionTable.push_back(questionAnswer);
	}
}

bool IsScoring(int question, int answer)
{
	if (question == 1 && answer == 1)  return true;
	if ((1 + question) * question / 2 == answer) return true;
	else return false;	
}

int main() 
{
	string YES = "YES", NO = "NO";
	int studentCnt;	
	cin >> studentCnt;
	SetStudentMapTable(studentCnt);

	for (unordered_map<int,int> studentQuestion : studentQuestionTable)
	{
		for (auto sqPair : studentQuestion)
		{
			if (IsScoring(sqPair.first, sqPair.second) == true) cout << YES << endl;
			else cout << NO << endl;
		}
	}

	return 0;
}