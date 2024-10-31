#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

// 전력망을 둘로 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=cpp

int minDiff = INT_MAX;
vector<vector<int>> node;

int GetEdges(int n, vector<bool>& visited)
{
    int count = 1;
    visited[n] = true;
    
    for(auto& connected : node[n])
    {
        if(!visited[connected])
        {
            count += GetEdges(connected, visited);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {    
    node.assign(n+1, vector<int>());
    
    for(auto& w : wires)
    {
        node[w[0]].push_back(w[1]);
        node[w[1]].push_back(w[0]);
    }
    
    for(auto& w : wires)
    {
        int v1 = w[0];
        int v2 = w[1];
        
        node[v1].erase(remove(node[v1].begin(), node[v1].end(), v2), node[v1].end());
        node[v2].erase(remove(node[v2].begin(), node[v2].end(), v1), node[v2].end());
        
        vector<bool> visited(n+1, false);
        int a = GetEdges(v1, visited);
        int b = n-a;
        int diff = abs(a-b);
        
        minDiff = min(diff, minDiff);
        
        node[v1].push_back(v2);
        node[v2].push_back(v1);
    }
    
    return minDiff;
}