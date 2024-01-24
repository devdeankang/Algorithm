#include <string>
#include <vector>
#include <stack>

using namespace std;

// 햄버거 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/133502?language=cpp

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> st;
    
    for(int i =0; i<ingredient.size(); i++)
    {
        st.push(ingredient[i]);
        
        if(st.size() >= 4)
        {
            vector<int> temp(4);
            for(int j = 0; j<4; j++)
            {
                temp[3-j] = st.top();
                st.pop();
            }
            
            if(temp[0] == 1 && temp[1] == 2 && temp[2] == 3 && temp[3] == 1 )
            {
                answer++;
            }
            else
            {
                for(int j =0; j<4; j++)
                {
                    st.push(temp[j]);
                }
            }
        }        
    }    
    return answer;
}