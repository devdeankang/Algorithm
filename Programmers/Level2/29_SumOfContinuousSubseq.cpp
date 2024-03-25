#include <string>
#include <vector>

using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/178870?language=cpp
// 연속된 부분 수열의 합

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, -1);
    int start = 0, end = 0, sum = sequence[0];
    
    while(start < sequence.size() && end <sequence.size())
    {
        if(sum < k)
        {
            end++;            
            if(end <sequence.size())
            {
                sum += sequence[end];
            }
        }
        else if(sum > k)
        {
            sum -= sequence[start];
            start++;
        }
        else
        {
            if(answer[0] == -1 || end -start < answer[1] - answer[0])
            {
                answer[0] = start;
                answer[1] = end;
            }
            
            // 새로운 부분 수열 탐색하기 위해
            sum -= sequence[start];
            start++;
        }
    }
    
    return answer;
}