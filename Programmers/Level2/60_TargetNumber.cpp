#include <string>
#include <vector>

using namespace std;

// 타겟 넘버
// https://school.programmers.co.kr/learn/courses/30/lessons/43165?language=cpp

int answer = 0;
void DFS(int i, int sum, vector<int> numbers, int target)
{
    if(i == numbers.size())
    {
        if(sum == target) answer++;
    }
    else
    {        
        DFS(i+1, sum + numbers[i], numbers, target);
        DFS(i+1, sum - numbers[i], numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, numbers, target);
    return answer;
}