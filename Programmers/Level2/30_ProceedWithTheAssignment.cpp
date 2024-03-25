#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 과제 진행하기
// https://school.programmers.co.kr/learn/courses/30/lessons/176962?language=cpp

struct Report
{
    string name;
    int start, playTime, remaining;

    Report(string n, int s, int p, int r = 0)
    {
        name = n;
        start = s;
        playTime = p;
        remaining = r;
    }

    bool operator<(const Report& b) const {
        return start < b.start;
    }
};

int ConvertTimetoMin(string time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Report> reports;
    stack<Report> paused_tasks;
    
    for (auto plan : plans)
    {
        string name = plan[0];
        int start = ConvertTimetoMin(plan[1]);
        int playTime = stoi(plan[2]);
        reports.emplace_back(Report(name, start, playTime));
    }
    sort(reports.begin(), reports.end());   // 시작시간을 기준으로 오름차순 정렬

    for (int i =1; i<reports.size(); i++)
    {
        Report curr = reports[i];
        Report prev = reports[i-1];

        int availableTime = curr.start - prev.start - prev.playTime ;
        
        if (prev.start + prev.playTime > curr.start)
        {
            prev.remaining = prev.start + prev.playTime - curr.start;
            paused_tasks.push(prev);
        }
        else
        {
            answer.emplace_back(prev.name);
        }

        while (!paused_tasks.empty() && prev.start + prev.playTime < curr.start)
        {
            Report task = paused_tasks.top();
            paused_tasks.pop();
            if (availableTime < task.remaining)
            {
                task.remaining -= availableTime;
                paused_tasks.push(task);
                break;
            }
            else if (availableTime > task.remaining)
            {
                availableTime = availableTime - task.remaining;
                answer.emplace_back(task.name);
                continue;
            }
            else
            {
                answer.emplace_back(task.name);
                break;
            }
        }

        if (i == reports.size() - 1)
        {
            answer.emplace_back(curr.name);
        }            
    }
    
    while (!paused_tasks.empty())
    {
        Report report = paused_tasks.top();
        paused_tasks.pop();
        answer.emplace_back(report.name);
    }

    return answer;
}