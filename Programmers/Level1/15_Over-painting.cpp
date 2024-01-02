#include <string>
#include <vector>

using namespace std;

// 덧칠하기
// https://school.programmers.co.kr/learn/courses/30/lessons/161989

int solution(int n, int m, vector<int> section) {
    int answer = 0, currentPart = -m;
    
    for (int part : section)
    {
        if (currentPart + m <= part)
        {
            answer++;
            currentPart = part;                        
        }        
    }
    
    return answer;
}