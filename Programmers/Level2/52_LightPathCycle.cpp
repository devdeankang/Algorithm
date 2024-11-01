#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 빛의 경로 사이클
// https://school.programmers.co.kr/learn/courses/30/lessons/86052

vector<vector<vector<bool>>> visited(510, vector<vector<bool>>(510, vector<bool>(4, false)));
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int m,n;

int GetCycleCount(int x, int y, int dir, vector<string>& grid)
{
    int count = 0;
        
    while(!visited[x][y][dir])
    {
        visited[x][y][dir] = true;
        count++;
        
        if(grid[x][y] == 'L')
        {
            dir = (dir + 1 + 4) % 4;
        }
        else if(grid[x][y] == 'R')
        {
            dir = (dir -1 + 4) % 4;
        }        
        
        x = (x + dx[dir] + m) % m;
        y = (y + dy[dir] + n) % n;            
    }
    return count;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    m = grid.size();
    n = grid[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j =0; j < n; j++)
        {
            for(int d = 0; d<4; d++)
            {
                if(!visited[i][j][d])
                {
                    answer.push_back(GetCycleCount(i,j,d,grid));
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}