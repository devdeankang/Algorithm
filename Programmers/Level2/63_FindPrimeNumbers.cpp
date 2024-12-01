#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

// 소수 찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=cpp

bool IsPrimeNumber(int num)
{
    if(num < 2) return false;
    for(int n = 2; n<=sqrt(num); n++)
    {
        if(num % n == 0) return false;            
    }
    return true;
}

void SetCombinations(string& numbers, set<int>& result, string current, vector<bool>& isVisited)
{
    if(!current.empty())
    {
        result.insert(stoi(current));
    }
    
    for(int i=0; i<numbers.size(); i++)
    {
        if(isVisited[i]) continue;
        isVisited[i] = true;
        SetCombinations(numbers, result, current+numbers[i], isVisited);
        isVisited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    set<int> nums;
    vector<bool> isVisited(numbers.size(), false);
    
    SetCombinations(numbers, nums, "", isVisited);
    
    for(int num : nums)
    {
        if(IsPrimeNumber(num)) answer++;
    }
    return answer;
}