#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전국 대회 선발 고사
// https://school.programmers.co.kr/learn/courses/30/lessons/181851?language=cpp

int solution(vector<int> rank, vector<bool> attendance) {
    vector<pair<int,int>> attendable;
    for(int i =0; i<rank.size(); i++)
    {
        if(attendance[i] == true)
        {
            attendable.push_back(make_pair(rank[i],i));
        }
    }
    sort(attendable.begin(), attendable.end());
    
    return 10000 * attendable[0].second + 100 * attendable[1].second + attendable[2].second;
}