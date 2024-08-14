#include <string>
#include <vector>
#include <queue>

using namespace std;

// 미로 탈출
// https://school.programmers.co.kr/learn/courses/30/lessons/159993?language=cpp

struct Point
{
    int x, y, distance;
    
    Point(int _x = 0, int _y = 0, int _dis = 0)
    {
        x = _x, y = _y, distance = _dis;
    }
};

int BFS(vector<string> maps, int m, int n, Point start, Point dest)
{
    if(start.distance == -1) return -1;
    
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<Point> q;
    
    q.push(start);
    visited[start.x][start.y] = true;
    
    while(!q.empty())
    {
        Point current = q.front();
        q.pop();
        
        if(current.x == dest.x && current.y == dest.y)
        {            
            return current.distance;
        }
        
        for(int i = 0; i<4; i++)
        {
            int nextX = current.x + dx[i];
            int nextY = current.y + dy[i];
            
            if(nextX >=0 && nextX < m && nextY >=0 && nextY < n
              && maps[nextX][nextY] != 'X' && !visited[nextX][nextY])
            {
                q.push({nextX, nextY, current.distance + 1});
                visited[nextX][nextY] = true;
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {    
    int m = maps.size();
    int n = maps[0].size();
    Point sPoint, lPoint, ePoint;
    
    for(int i = 0; i<m; i++)
    {
        for(int j =0; j<n; j++)
        {
            Point temp(i, j, 0);
            if(maps[i][j] == 'S') sPoint = temp;
            else if(maps[i][j] == 'L') lPoint = temp;
            else if(maps[i][j] == 'E') ePoint = temp;            
        }
    }
    
    lPoint.distance = BFS(maps, m, n, sPoint, lPoint);    
    
    return BFS(maps, m, n, lPoint, ePoint);
}

