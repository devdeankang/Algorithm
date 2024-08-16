#include <string>
#include <vector>
#include <queue>

using namespace std;

// 디펜스 게임
// https://school.programmers.co.kr/learn/courses/30/lessons/142085

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(int i =0; i<enemy.size(); i++)
    {
        if(n >= enemy[i])
        {            
            n -= enemy[i];
            pq.push(enemy[i]);   
            answer++;
        }
        else if(k > 0)
        {
            if(!pq.empty() && pq.top() > enemy[i])
            {
                n += pq.top();
                pq.pop();
                
                n -= enemy[i];
                pq.push(enemy[i]);                    
            }
            answer++;
            k--;
        }        
        else
        {
            break;
        }
    }
    
    return answer;
}