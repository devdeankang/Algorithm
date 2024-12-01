#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 구명보트
// https://school.programmers.co.kr/learn/courses/30/lessons/42885

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size()-1;
   
    while(left <= right)
    {
        if(people[left] + people[right] <= limit) left++;
        right--;
        answer++;
    }
    return answer;
}