#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 큰 수 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/42883?language=cpp

string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    
    for(auto digit : number)
    {
        while(!st.empty() && st.top() < digit && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(digit);    
    }
    
    while(k>0)
    {
        st.pop();
        k--;
    }
    
    while(!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}