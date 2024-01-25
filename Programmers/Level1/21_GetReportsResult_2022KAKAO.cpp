#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

// 신고 결과 받기
// https://school.programmers.co.kr/learn/courses/30/lessons/92334

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;    
    map<string, set<string>> reporters; // key : 피신고자 , value 신고자들
    map<string, int> emailCounts;
    
    for(string str : id_list)
    {
        emailCounts[str] = 0;
    }
    
    for(string str : report)
    {
        istringstream ss(str);
        string buffer;
        vector<string> temp;
        while(getline(ss, buffer, ' '))
        {
            temp.push_back(buffer);
        }
        reporters[temp[1]].insert(temp[0]);
    }
    
    for(auto it = reporters.begin(); it != reporters.end(); it++)
    {                
        if(reporters[it->first].size() >= k)
        {
            for(string str : reporters[it->first])
            {
                emailCounts[str]++;
            }          
        }
    }
    
    for(int i=0; i<id_list.size(); i++)
    {
        auto it = emailCounts.find(id_list[i]);
        if(it != emailCounts.end())
        {
            answer.push_back(it->second);
        }
    }
    
    return answer;
}