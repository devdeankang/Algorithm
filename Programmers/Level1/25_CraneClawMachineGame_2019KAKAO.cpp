#include <string>
#include <vector>
#include <stack>

using namespace std;

// 크레인 인형뽑기 게임
// https://school.programmers.co.kr/learn/courses/30/lessons/64061

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int max = board.size();
    stack<int> st;
    st.push(0);
    for(int i = 0; i<moves.size(); i++)
    {
        int col = moves[i] - 1;
        for(int row = 0; row < max; row++)
        {
            if(board[row][col] != 0)
            {
                int val = board[row][col];
                board[row][col] = 0;
                int top = st.top();
                
                if(val == top) 
                {
                    st.pop();
                    answer += 2;
                }
                else
                {
                    st.push(val);
                }
                break;
            }
        }
    }
    
    return answer;
}