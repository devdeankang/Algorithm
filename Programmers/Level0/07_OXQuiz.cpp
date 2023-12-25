#include <string>
#include <vector>
#include <sstream>

using namespace std;

// OX퀴즈
// https://school.programmers.co.kr/learn/courses/30/lessons/120907

string GetResult(int first, char op, int second, int ans)
{
    string res;    
    switch (op)
    {
    case '+':
        if (first + second == ans) res = "O";
        else res = "X";
        break;

    case '-':
        if (first - second == ans) res = "O";
        else res = "X";
        break;
    }
    return res;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for (int i = 0; i < quiz.size(); i++)
    {
        vector<string> split;
        stringstream ss(quiz[i]);
        string buffer;

        while (getline(ss, buffer, ' '))
        {
            if (buffer != "")
                split.push_back(buffer);
        }
        int first = stoi(split[0]);
        int second = stoi(split[2]);
        int ans = stoi(split[4]);
        string op = split[1];
        answer.push_back(GetResult(first, op[0], second, ans));
    }

    return answer;
}