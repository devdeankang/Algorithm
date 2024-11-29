#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문자열 압축
// https://school.programmers.co.kr/learn/courses/30/lessons/60057

int solution(string s) {
    int answer = s.size();   
    int count = 1;
    string comp;
    for(int n =1; n <= s.size()/2; n++)
    {       
        string source = s.substr(0, n);
        for(int i = n; i <= s.size(); i+=n)       
        {
            if(source == s.substr(i, n)) count++;
            else
            {
                if(count > 1)
                {
                    comp += (to_string(count) + source);
                    source = s.substr(i, n);
                }
                else 
                {
                    comp += source;
                    source = s.substr(i, n);
                }
                count = 1;
            }   
        }
        comp += source;
        int cLength = comp.size();
        answer = min(answer, cLength);
        comp.clear();
    }
    
    return answer;
}