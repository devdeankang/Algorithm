#include <string>
#include <vector>
#include <map>

using namespace std;

// 대충 만든 자판
// https://school.programmers.co.kr/learn/courses/30/lessons/160586


vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> minData;
    
    for(int i = 0; i<keymap.size(); i++)
    {
        string key = keymap[i];
        for(int j = 0; j < key.size(); j++)
        {
            if(minData.find(key[j]) == minData.end())
            {             
                minData[key[j]] = j+1;
            }
            else
            {                
                if(j+1 < minData[key[j]]) minData[key[j]] = j+1;                
            }
        }
    }
    
    for(int i =0; i<targets.size(); i++)
    {
        int count = 0;
        bool isValid = true;
        string texts = targets[i];
        for(char ch : texts)
        {            
            if(minData.find(ch) == minData.end()) isValid = false;            
            else count += minData[ch];
        }
        
        if(isValid == true) answer.push_back(count);
        else answer.push_back(-1);
    }
    
    return answer;
}