#include <string>
#include <vector>

using namespace std;

// 정수를 나선형으로 배치하기
// https://school.programmers.co.kr/learn/courses/30/lessons/181832

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 1));
    bool order[4] = {true, false, false, false}; // right, down, left, up
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    int x=0,y=0;    
    visited[0][0]= true;
    for(int i =2; i<=n*n; i++)
    {
        if(order[0] == true)
        {
            y++;
            answer[x][y] = i;
            visited[x][y] = true;
            if(y == n-1 || visited[x][y+1] == true)
            {
                order[0] = false;                
                order[1] = true;
            }
        }
        else if(order[1] == true)
        {
            x++;
            answer[x][y] = i;
            visited[x][y] = true;
            if(x == n-1 || visited[x+1][y] == true)
            {
                order[1] = false;                
                order[2] = true;
            }
        }
        else if(order[2] == true)
        {
            y--;
            answer[x][y] = i;
            visited[x][y] = true;
            if(y == 0 || visited[x][y-1] == true)
            {
                order[2] = false;                
                order[3] = true;
            }
        }
        else if(order[3] == true)
        {
            x--;
            answer[x][y] = i;
            visited[x][y] = true;
            if(x == 1 || visited[x-1][y] == true)
            {
                order[3] = false;                
                order[0] = true;
            }
        }
    }
    
    return answer;
}