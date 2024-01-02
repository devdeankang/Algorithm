#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 달리기 경주
// https://school.programmers.co.kr/learn/courses/30/lessons/178871?language=cpp

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> m;
    
    for (int i = 0; i < players.size(); i++)
    {
        m[players[i]] = i;
    }
    
    for (string call : callings)
    {
        int pos = m[call];        
        m[players[pos]] = pos - 1;
        m[players[pos-1]] = pos;
        swap(players[pos], players[pos - 1]);
    }
    
    return players;
}