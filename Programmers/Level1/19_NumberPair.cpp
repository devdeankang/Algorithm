#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 숫자 짝꿍
// https://school.programmers.co.kr/learn/courses/30/lessons/131128

string solution(string X, string Y) {
    string answer = "";
    map<char, int> aDic, bDic;
    vector<char> chars;
    
    for(auto ch : X)
    {
        aDic[ch]++;
    }
    for(auto ch : Y)
    {
        bDic[ch]++;
    }
    
    for(auto it = aDic.begin(); it != aDic.end(); it++)
    {
        char key = it->first;
        int aVal = it->second;
        
        auto it2 = bDic.find(key);
        if(it2 != bDic.end())
        {
            int bVal = it2->second;
            int min = bVal;
            if(aVal < bVal) min = aVal;
            for(int i =0; i<min; i++)
            {
                chars.push_back(key);
            }
        }
    }
    
    sort(chars.rbegin(), chars.rend());
    
    for(auto ch : chars)
    {
        if(answer[0] != '0')
            answer.push_back(ch);
    }
    
    if(answer == "") answer = "-1";

    return answer;
}