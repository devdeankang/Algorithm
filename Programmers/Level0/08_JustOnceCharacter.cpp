#include <string>
#include <vector>
#include <map>

using namespace std;

// 한 번만 등장한 문자
// https://school.programmers.co.kr/learn/courses/30/lessons/120896?language=cpp

string solution(string s) {
    string answer = "";
    map<char, int> m;
    
    for (auto ch : s)
    {
       m[ch]++;
    }
    
    for(auto it : m)
    {
        if(it.second == 1)
        {
            answer.push_back(it.first);
        }
    }
    
    return answer;
}