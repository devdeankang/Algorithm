#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 메뉴 리뉴얼
// https://school.programmers.co.kr/learn/courses/30/lessons/72411

void GetCombinations(const string& str, int k, int start, string current, unordered_map<string,int>& combinations)
{
    if(k == current.length())
    {
        combinations[current]++;
        return;
    }
    else
    {
        for(int i = start; i < str.length(); i++)
        {
            GetCombinations(str, k, i+1, current+str[i], combinations);
        }
    }    
}

bool SortBySecond(const pair<string,int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto& k : course)
    {
        unordered_map<string, int> combinations;
        int maxCount = 0;
        
        for(auto& str : orders)
        {
            sort(str.begin(), str.end());
            GetCombinations(str, k, 0, "", combinations);            
        }
        vector<pair<string, int>> combs(combinations.begin(), combinations.end());
        sort(combs.begin(), combs.end(), SortBySecond);
        
        maxCount = combs[0].second;
        for(auto& comb : combs)
        {
            if(comb.second >=2 && comb.second >= maxCount)
            {                
                answer.push_back(comb.first);
            }            
            else
            {
                break;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}