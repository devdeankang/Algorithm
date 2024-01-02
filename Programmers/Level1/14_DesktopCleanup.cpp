#include <string>
#include <vector>

using namespace std;

// 바탕화면 정리
// https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=cpp

vector<int> solution(vector<string> wallpaper) {    
    int h = wallpaper.size(), v = wallpaper[0].size();
    int startX = h, startY = v, endX = 0, endY = 0;
    
    for(int i =0; i<h; i++)
    {
        for(int j=0; j<v; j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i < startX) startX = i;                
                if(j < startY) startY = j;
                
                if(i > endX) endX = i;
                if(j > endY) endY = j;
            }
        }
    }

    return {startX, startY, endX + 1, endY + 1};
}