#include <string>
#include <vector>
#include <map>

using namespace std;

// 완주하지 못한 선수
// https://school.programmers.co.kr/learn/courses/30/lessons/42576

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, pair<int,int>> tables;
    
    for(string name : participant)
    {
        tables[name].first++;
        tables[name].second++;
    }
    
    for(string name : completion)
    {
        tables[name].second--;
    }
    
    for(auto it = tables.begin(); it != tables.end(); it++)
    {
        pair<int,int> temp = it->second;
        if(temp.first - temp.second != temp.first)
        {
            answer = it->first;
            break;
        }
    }
        
    return answer;
}