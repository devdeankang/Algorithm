#include <string>
#include <vector>
#include <map>

using namespace std;

// 키패드 누르기
// https://school.programmers.co.kr/learn/courses/30/lessons/67256

string solution(vector<int> numbers, string hand) {
    string answer = "";
    map<int, pair<int, int>> keyPos = {
        {1, {0, 0}}, {2, {0, 1}}, {3, {0, 2}},
        {4, {1, 0}}, {5, {1, 1}}, {6, {1, 2}},
        {7, {2, 0}}, {8, {2, 1}}, {9, {2, 2}},
        {0, {3, 1}}
    };

    pair<int, int> leftPos = {3, 0}; // * 위치
    pair<int, int> rightPos = {3, 2}; // # 위치

    for (int number : numbers) {
        if (number == 1 || number == 4 || number == 7) {
            answer += "L";
            leftPos = keyPos[number];
        } else if (number == 3 || number == 6 || number == 9) {
            answer += "R";
            rightPos = keyPos[number];
        } else {
            pair<int, int> targetPos = keyPos[number];
            int leftDist = abs(leftPos.first - targetPos.first) + abs(leftPos.second - targetPos.second);
            int rightDist = abs(rightPos.first - targetPos.first) + abs(rightPos.second - targetPos.second);

            if (leftDist < rightDist || (leftDist == rightDist && hand == "left")) {
                answer += "L";
                leftPos = targetPos;
            } else {
                answer += "R";
                rightPos = targetPos;
            }
        }
    }

    return answer;
}