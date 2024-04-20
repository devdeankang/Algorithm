#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 리코쳇 로봇
// https://school.programmers.co.kr/learn/courses/30/lessons/169199?language=cpp

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1}; 
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int,int>> q;
    pair<int, int> startPos, endPos;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                startPos = {i, j};
                q.push(startPos);
                visited[i][j] = 1;
            } else if (board[i][j] == 'G') {
                endPos = {i, j};
            }
        }
    }

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int currentX = current.first;
        int currentY = current.second;

        for (int i = 0; i < 4; i++) {
            int nextX = currentX;
            int nextY = currentY;

            while (true) {
                int tmpX = nextX + dx[i];
                int tmpY = nextY + dy[i];
                if (tmpX < 0 || tmpX >= n || tmpY < 0 || tmpY >= m || board[tmpX][tmpY] == 'D') break;
                nextX = tmpX;
                nextY = tmpY;
            }
            
            if (!visited[nextX][nextY]) {
                visited[nextX][nextY] = visited[currentX][currentY] + 1;
                q.push({nextX, nextY});
                if (nextX == endPos.first && nextY == endPos.second) {
                    return visited[nextX][nextY] - 1;
                }
            }
        }
    }

    return -1;
}