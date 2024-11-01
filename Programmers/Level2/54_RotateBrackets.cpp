#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 괄호 회전하기
// https://school.programmers.co.kr/learn/courses/30/lessons/76502?language=cpp

bool IsValid(string s)
{
    stack<char> st;
    for(char ch : s)
    {
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty()) return false;
            
            char top = st.top();
            if((top == '(' && ch == ')') ||
               (top == '{' && ch == '}') ||
               (top == '[' && ch == ']') )
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    for(int i =0; i<s.size(); i++)
    {
        if(IsValid(s)) answer++;
        rotate(s.begin(), s.begin()+1, s.end());
    }
    return answer;
}