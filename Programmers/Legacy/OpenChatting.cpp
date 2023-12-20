#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 오픈채팅방
// https://programmers.co.kr/learn/courses/30/lessons/42888

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> uIDMap;   // id, nickname
    vector<pair<string, string>> logData;

    for (string order : record)
    {
        int num = 0;
        vector<string> fullOrder;

        for (int i = 0; i < order.length(); i++)
        {
            if (order[i] == ' ')
            {
                fullOrder.push_back(order.substr(num, i - num));
                num = i + 1;
            }
        }

        if (fullOrder[0] != "Leave")
            uIDMap[fullOrder[1]] = order.substr(num);
        else
            fullOrder.push_back(order.substr(num));
        logData.push_back({ fullOrder[0], fullOrder[1] });
    }

    for (pair<string, string> str : logData)
    {
        string order = str.first;
        string id = str.second;
        if (order == "Enter")
            answer.push_back(uIDMap[id] + "님이 들어왔습니다.");
        else if (order == "Leave")
            answer.push_back(uIDMap[id] + "님이 나갔습니다.");
    }

    return answer;
}