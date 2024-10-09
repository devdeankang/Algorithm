#include <string>
#include <vector>

using namespace std;

// 마법의 엘리베이터
// https://school.programmers.co.kr/learn/courses/30/lessons/148653?language=cpp

int solution(int storey) {
    int count = 0;
        
    while(storey != 0)
    {
        int mod = storey % 10;
        storey /= 10;
        
        if(mod > 5)
        {
            count += (10-mod);
            storey += 1;
        }
        else if(mod == 5 && (storey%10) >= 5)
        {
            count += 5;
            storey += 1;
        }
        else
        {
            count += mod;
        }
        
    }
        
    return count;
}