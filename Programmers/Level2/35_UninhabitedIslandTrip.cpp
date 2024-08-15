#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 무인도 여행
// https://school.programmers.co.kr/learn/courses/30/lessons/154540?language=cpp

int m,n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int DFS(vector<string>& maps, vector<vector<bool>>& visited, int x, int y)
{    
    visited[x][y] = true;
    int sum = maps[x][y] - '0';
    
    for(int i =0; i<4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if(nextX >= 0 && nextX < m && nextY >=0 && nextY < n
            && maps[nextX][nextY] != 'X' && !visited[nextX][nextY])
        {
            sum += DFS(maps, visited, nextX, nextY);
        }
    }
    
    return sum;    
}
 
vector<int> solution(vector<string> maps) {
    vector<int> answer;   
    m = maps.size();
    n = maps[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    for(int i =0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(maps[i][j] != 'X' && !visited[i][j])
            {
                answer.push_back(DFS(maps, visited, i, j));
            }
        }
    }
    
    if(answer.empty()) 
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
        
    return answer;
}