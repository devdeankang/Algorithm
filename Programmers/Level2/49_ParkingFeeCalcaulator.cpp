#include <string>
#include <vector>
#include <map>

using namespace std;

// 주차 요금 계산
// https://school.programmers.co.kr/learn/courses/30/lessons/92341?language=cpp

struct Car
{
    int time;
    bool isExit;
        
    Car(int _time, bool _isExit)
    {
        time = _time;        
        isExit = _isExit;
    }
};

int GetMinutes(string records)
{
    int hour = stoi(records.substr(0,2));
    int minute = stoi(records.substr(3,2));
    
    return hour * 60 + minute;
}

int GetFees(vector<int> fees, int time)
{
    int baseTime = fees[0];
    int baseFee = fees[1];
    int addTime = fees[2];
    int addFee = fees[3];
    
    if(time - baseTime <= 0) 
    {
        return baseFee;
    }
    else
    {
        int add = time - baseTime;
        if(add % addTime != 0)
        {
            return baseFee + ((add/addTime +1) * addFee);
        }
        else
        {
            return baseFee + (add / addTime * addFee);
        }        
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int endline = (23 * 60) + 59;
    map<int, vector<Car>> info;
    
    for(auto& r : records)
    {
        int carNum = stoi(r.substr(6,4));
        if(r[11] == 'I')
        {
            info[carNum].push_back(Car(GetMinutes(r), false));
        }
        else
        {
            info[carNum].push_back(Car(GetMinutes(r), true));
        }        
    }
    
    for(auto it = info.begin(); it != info.end(); it++)
    {        
        int total = 0, entry =0, exit =0;
        int carNum = it->first;
        vector<Car> cars = it->second;
        if(cars.size() % 2 == 1)
        {
            cars.push_back(Car(endline, true));
        }
        for(int i = cars.size() -1; i >=0; i--)
        {
            if(cars[i].isExit)
            {
                exit = cars[i].time;
            }
            else
            {
                entry = cars[i].time;
                total += (exit - entry);
                exit = 0;
                entry = 0;
            }
        }
        answer.push_back(GetFees(fees, total));
    }
    
    return answer;
}