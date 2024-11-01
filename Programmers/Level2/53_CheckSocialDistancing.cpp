#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 거리두기 확인하기
// https://school.programmers.co.kr/learn/courses/30/lessons/81302?language=cpp#fn1

bool isValidDistance(vector<string>& place, int x1, int y1, int x2, int y2) {
    int dist = abs(x1 - x2) + abs(y1 - y2);
    if (dist == 1) return false;
    if (dist == 2) {
        if (x1 == x2) {
            if (place[x1][(y1 + y2) / 2] != 'X') return false;
        } else if (y1 == y2) {
            if (place[(x1 + x2) / 2][y1] != 'X') return false;
        } else {  
            if (place[x1][y2] != 'X' || place[x2][y1] != 'X') return false;
        }
    }
    return true;
}

bool checkPlace(vector<string>& place) {
    vector<pair<int, int>> people;    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] == 'P') {
                people.push_back({i, j});
            }
        }
    }
    
    for (int i = 0; i < people.size(); i++) {
        for (int j = i + 1; j < people.size(); j++) {
            if (!isValidDistance(place, people[i].first, people[i].second, people[j].first, people[j].second)) {
                return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto& place : places) {
        if (checkPlace(place)) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }

    return answer;
}