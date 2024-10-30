#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 할인 행사
// https://school.programmers.co.kr/learn/courses/30/lessons/131127?language=cpp

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> um;
    
    for(int i=0; i<want.size(); i++)
    {
        um[want[i]] = number[i];        
    }
    
    for(int i =0; i<=discount.size()-10; i++)
    {
        unordered_map<string, int> temp = um;
        int count = 0;
        for(int j = i; j<i+10; j++)
        {
            temp[discount[j]]--;
            if(temp[discount[j]] == 0) count++;
        }
        if(count == want.size()) answer++;
    }
    return answer;
}