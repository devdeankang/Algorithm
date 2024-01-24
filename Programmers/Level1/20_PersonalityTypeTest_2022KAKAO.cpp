#include <string>
#include <vector>
#include <map>

using namespace std;

// 성격 유형 검사하기
// https://school.programmers.co.kr/learn/courses/30/lessons/118666

string solution(vector<string> survey, vector<int> choices) {
    // survey[i][0] 비동의 , survey[i][1] 동의
    // 비동의 1:3점, 2:2점, 3:1점 / 4:0점 / 동의 5:1점, 6:2점, 7:3점    
    string answer = "";
    vector<string> base = {"RT", "CF", "JM", "AN"};
    map<char, int> types;
    
    for(int i=0; i<4; i++)
    {
        types[base[i][0]] = 0;
        types[base[i][1]] = 0;
    }
    
    for(int i=0; i<survey.size(); i++)
    {
        switch(choices[i])
        {
            case 1:
                types[survey[i][0]] += 3;
                break;
            case 2:
                types[survey[i][0]] += 2;
                break;
            case 3:
                types[survey[i][0]] += 1;
                break;
            case 4:
                break;
            case 5:
                types[survey[i][1]] += 1;
                break;
            case 6:
                types[survey[i][1]] += 2;
                break;
            case 7:
                types[survey[i][1]] += 3;
                break;
        }
    }
    
    for(int i =0; i<4; i++)
    {
        auto typeA = types.find(base[i][0]);
        auto typeB = types.find(base[i][1]);
        if(typeB->second > typeA->second)
        {
            answer.push_back(typeB->first);
        }
        else
        {
            answer.push_back(typeA->first);
        }
    }
    
    return answer;
}