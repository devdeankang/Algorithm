#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 광물 캐기
// https://school.programmers.co.kr/learn/courses/30/lessons/172927?language=cpp

vector<string> _minerals;
int answer = 25 * 50 + 1;

int GetFatigue(int pickax, string mineral)
{
    switch (pickax)
    {
    case 0:
        return 1;
    case 1:
        if (mineral == "diamond") return 5;
        else return 1;
    case 2:
        if (mineral == "diamond") return 25;
        else if (mineral == "iron") return 5;
        return 1;
    default:
        return -1;
    }

    return -1;
}

void DFS(int sum, vector<int>& picks, int mIdx)
{
    if (_minerals.size() == mIdx ||
        (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
    {
        answer = min(answer, sum);
        return;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (picks[i] != 0)
            {
                picks[i]--;                
                int tmpSum = sum;
                int tmpIdx = mIdx;
                for (; tmpIdx < _minerals.size(); tmpIdx++)
                {
                    if (tmpIdx >= mIdx + 5) break;
                    tmpSum += GetFatigue(i, _minerals[tmpIdx]);
                }
                DFS(tmpSum, picks, tmpIdx);
                picks[i]++;
            }
        }       
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    _minerals = minerals;

    DFS(0, picks, 0);

    return answer;
}