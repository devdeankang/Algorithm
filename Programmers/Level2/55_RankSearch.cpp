#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

// 순위 검색
// https://school.programmers.co.kr/learn/courses/30/lessons/72412

unordered_map<string, vector<int>> info_map;

vector<string> GetSplitWords(string str)
{
    vector<string> ret;
    istringstream ss(str);
    string buffer;
    while(getline(ss, buffer, ' '))
    {
        if(buffer != "and")
            ret.push_back(buffer);
    }
    return ret;
}

void SetInfo(vector<string> words)
{
    string langs[2] = {words[0], "-"};
    string stacks[2] = {words[1], "-"};
    string levels[2] = {words[2], "-"};
    string foods[2] = {words[3], "-"};
    int score = stoi(words[4]);
    
    for(auto& lang : langs)
    {
        for(auto& st : stacks)
        {
            for(auto& lev : levels)
            {
                for(auto& food : foods)
                {
                    string key = lang + st + lev + food;
                    info_map[key].push_back(score);
                }
            }
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(auto& data : info)
    {
        SetInfo(GetSplitWords(data));
    }
    
    for (auto& entry : info_map) 
    {
        sort(entry.second.begin(), entry.second.end());
    }
    
    for(auto& q : query)
    {
        vector<string> data = GetSplitWords(q);
        string target = data[0] + data[1] + data[2] + data[3];
        int targetScore = stoi(data[4]);       
        
        if(info_map.find(target) != info_map.end())
        {
            auto scores = info_map[target];
            auto it = lower_bound(scores.begin(), scores.end(), targetScore);
            
            answer.push_back(scores.end()-it);
        }
        else
        {
            answer.push_back(0);
        }
        
    }
    return answer;
}