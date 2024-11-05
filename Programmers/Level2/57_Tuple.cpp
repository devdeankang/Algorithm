#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 튜플
// https://school.programmers.co.kr/learn/courses/30/lessons/64065

bool SortBySecondDesc(const pair<int,int>& a, const pair<int,int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {   
    vector<int> answer;
    unordered_map<int, int> tup;
    string str = s.substr(1, s.size()-2);
    
    vector<string> sets;
    string currentSet;
    bool isInside = false;
    for(char c : str)
    {
        if(c == '{')
        {
            isInside = true;
            currentSet.clear();            
        }
        else if(c == '}')
        {
            isInside = false;
            sets.push_back(currentSet);
        }
        else if(isInside)
        {
            currentSet += c;
        }
    }
    
    for(const string& setStr : sets)
    {
        istringstream ss(setStr);
        string num;
        
        while(getline(ss, num, ','))
        {
            tup[stoi(num)]++;
        }
    }
    
    vector<pair<int,int>> tups(tup.begin(), tup.end());
    sort(tups.begin(), tups.end(), SortBySecondDesc);
    
    for(const auto& t : tups)
    {
        answer.push_back(t.first);
    }
    
    return answer;
}