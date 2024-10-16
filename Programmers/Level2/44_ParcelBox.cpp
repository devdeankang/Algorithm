#include <string>
#include <vector>
#include <stack>

using namespace std;

// 택배상자
// https://school.programmers.co.kr/learn/courses/30/lessons/131704?language=cpp

int solution(vector<int> order) {
    int answer = 0, idx = 0;
    stack<int> st;
    
    for(int i = 1; i<=order.size(); i++)
    {
        while(!st.empty())
        {
            int top = st.top();
            if(top == order[idx])
            {
                st.pop();
                answer++;
                idx++;                
            }
            else
            {
                break;
            }
        }
        
        if(i == order[idx])
        {
            answer++;
            idx++;
        }
        else
        {
            st.push(i);
        }
    }
    
    while(!st.empty())
    {
        int top = st.top();
        if(top == order[idx])
        {
            st.pop();
            answer++;
            idx++;                
        }
        else
        {
            break;
        }
    }
   
    return answer;
}