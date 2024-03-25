#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 요격 시스템
// https://school.programmers.co.kr/learn/courses/30/lessons/181188

int solution(vector<vector<int>> targets) {

    sort(targets.begin(), targets.end());
    int count = 0;
    double currentEnd = -1;
    
    for (auto target : targets) 
    {        
        if (currentEnd < target[0]) 
        {
            currentEnd = target[1] - 0.1;
            count++;
        }
        
        currentEnd = min(currentEnd, (double)target[1] - 0.1);
    }

    return count;
}