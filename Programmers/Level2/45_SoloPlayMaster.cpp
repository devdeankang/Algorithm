#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 혼자 놀기의 달인
// https://school.programmers.co.kr/learn/courses/30/lessons/131130?language=cpp

void DFS(int idx, int count, vector<int> cards, vector<bool>& visited, vector<int>& group)
{
    if(visited[idx] == true)
    {
        group.push_back(count);
        for(int i =0; i<visited.size(); i++)
        {
            if(visited[i] == false)
            {                
                DFS(i, 0, cards, visited, group);                
            }
        }
    }
    else
    {
        visited[idx] = true;
        DFS(cards[idx]-1, count+1, cards, visited, group);
    }
}

void DFS(int idx, int& count, const vector<int>& cards, vector<bool>& visited)
{
    visited[idx] = true;
    count++;
    int nextIdx = cards[idx] -1;
    if(!visited[nextIdx])
    {
        DFS(nextIdx, count, cards, visited);
    }
}

int solution(vector<int> cards) {    
    
    vector<bool> visited(cards.size(), false);
    vector<int> group;
    
    for(int i = 0; i<cards.size(); i++)
    {
        if(!visited[i])
        {
            int count = 0;
            DFS(i, count, cards, visited);
            group.push_back(count);
        }
    }
    
    if(group.size() < 2) return 0;
    sort(group.begin(), group.end(), greater<int>());
    return group[0] * group[1];
}