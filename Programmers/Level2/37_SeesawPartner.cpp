#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 시소 짝꿍
// https://school.programmers.co.kr/learn/courses/30/lessons/152996

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<pair<int, int>> offsets = { {2,3}, {3,4}, {2,4}, {1,1} };
    map<int, long long> weightCount;
    
    for(auto w : weights)
    {
        weightCount[w]++;
    }
    
    for(auto& w : weightCount)
    {
        int weight = w.first;
        long long count = w.second;
        
        // 중복
        if(count > 1)
        {
            answer += (count * (count-1)) / 2;
        }
        
        for(auto& offset : offsets)
        {
            int target = weight * offset.first / offset.second;
            int rest = weight * offset.first % offset.second;
            if(target != weight && rest == 0 && weightCount.find(target) != weightCount.end())
            {
                answer += count * weightCount[target];
            }
        }
    }
    
    return answer;
}