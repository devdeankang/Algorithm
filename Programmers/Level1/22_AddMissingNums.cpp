#include <string>
#include <vector>

using namespace std;

// 없는 숫자 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/86051?language=cpp

int solution(vector<int> numbers) {
    int answer = 45;
    
    for(int num : numbers)
    {
        answer -= num;
    }
    
    return answer;
}