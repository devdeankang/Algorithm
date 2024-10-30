#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 피로도
// https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp

int maxCount = 0;
void BackTrack(int k, int count, vector<vector<int>>& dungeons, vector<bool>& visited)
{    
    maxCount = max(count, maxCount);

    for (int i = 0; i < dungeons.size(); i++)
    {
        int required = dungeons[i][0];
        int consumed = dungeons[i][1];

        if (k >= required && !visited[i])
        {
            visited[i] = true;
            BackTrack(k - consumed, count + 1, dungeons, visited);
            visited[i] = false;
        }        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    BackTrack(k, 0, dungeons, visited);
    return maxCount;
}