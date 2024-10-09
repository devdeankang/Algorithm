#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 귤 고르기
// https://school.programmers.co.kr/learn/courses/30/lessons/138476

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> um;
    for(int val : tangerine)
    {
        um[val]++;
    }
    vector<pair<int,int>> sorted(um.begin(), um.end());    
    sort(sorted.begin(), sorted.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    });
    
    for(auto& val : sorted)
    {
        k -= val.second;
        answer++;
        if(k<=0) break;
    }
    
    return answer;
}