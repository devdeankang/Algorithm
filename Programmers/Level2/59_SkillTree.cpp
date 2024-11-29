#include <string>
#include <vector>

using namespace std;

// 스킬트리
// https://school.programmers.co.kr/learn/courses/30/lessons/49993?language=cpp

int solution(string skill, vector<string> skill_trees) {
    int validCount = 0;

    for (auto skill_tree : skill_trees) 
    {
        string filtered;

        for (char c : skill_tree) 
        {
            for (int i = 0; i < skill.size(); i++) 
            {
                if (skill[i] == c) 
                {
                    filtered += c;
                    break;
                }
            }
        }
        
        bool isValid = true;
        for (int i = 0; i < filtered.size(); i++) 
        {
            if (filtered[i] != skill[i]) 
            {
                isValid = false;
                break;
            }
        }

        if (isValid) validCount++;
    }

    return validCount;
}