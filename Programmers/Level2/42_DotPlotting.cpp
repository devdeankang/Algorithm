#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 점 찍기
// https://school.programmers.co.kr/learn/courses/30/lessons/140107

long long solution(int k, int d) {
    long long answer = 0;
    long long limit = (long long)d * (long long)d;
    
    for(int a = 0; a <= d; a += k)
    {
        long long squared_maxB = limit - (long long)a* (long long)a;
        long long maxB = (long long)sqrt(squared_maxB);
        
        answer += (maxB / k) + 1;
    }
    
    return answer;
}