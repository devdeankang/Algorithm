#include <string>
#include <vector>

using namespace std;

// x 사이의 개수
// https://school.programmers.co.kr/learn/courses/30/lessons/181867

vector<int> solution(string myString) {
    vector<int> answer;
    
    int cnt = 0;
    for(int i =0; i<myString.size(); i++)
    {            
        if(myString[i] == 'x')
        {
            answer.push_back(cnt);
            cnt = 0;            
        }
        else
        {
            cnt++;
        }
        
        if(i == myString.size() -1)
        {
            answer.push_back(cnt);
        }
    }
    
    return answer;
    
}