#include <string>
#include <vector>
#include <map>

using namespace std;

// 최빈값 구하기
// https://school.programmers.co.kr/learn/courses/30/lessons/120812

int solution(vector<int> array) {
    int answer = 0, max = 0, dup = 0;
    
    map<int, int> m;
    for(auto n : array)
    {
        m[n]++;
        if(max < m[n]) max = m[n];
    }
    
    for(auto it : m)
    {
        if(it.second == max) 
        {
            answer = it.first;
            dup++;
            if(dup > 1) return -1;
        }
    }    
    
    return answer;
}