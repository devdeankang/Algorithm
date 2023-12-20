#include <iostream>
#include <string>
#include <vector>

// 카카오컬러링북
// https://programmers.co.kr/learn/courses/30/lessons/1829

#define MAXSIZE 100

using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[MAXSIZE][MAXSIZE];
int tempLevel = 0;

void initVisit() {
    for (int a = 0; a < MAXSIZE; a++) {
        for (int b = 0; b < MAXSIZE; b++) {
            visit[a][b] = false;
        }
    }
}
void dfs(vector<vector<int>> picture, int x, int y) {
    for (int a = 0; a < 4; a++) {
        int rx = x + dx[a];
        int ry = y + dy[a];

        if (rx >= 0 && ry >= 0 && rx < picture.size() && ry < picture[0].size()) {
            if (picture[rx][ry] == 0) continue;
            if (visit[rx][ry]) continue;
            if (picture[rx][ry] != picture[x][y]) continue;
            tempLevel++;
            visit[rx][ry] = true;
            dfs(picture, rx, ry);
        }

    }

}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = -1;
    initVisit();

    for (int a = 0; a < picture.size(); a++) {
        for (int b = 0; b < picture[a].size(); b++) {
            if (picture[a][b] == 0) continue;
            if (visit[a][b]) continue;
            number_of_area++;
            tempLevel = 1;
            visit[a][b] = true;
            dfs(picture, a, b);
            if (tempLevel > max_size_of_one_area) {
                max_size_of_one_area = tempLevel;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}