#include <string>
#include <vector>
#include <queue>

using namespace std;

// 두 큐 합 같게 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/118667

int solution(vector<int> queue1, vector<int> queue2) {        
    long long sum1 = 0, sum2 =0;
    queue<int> q1, q2;
    for(int i =0; i<queue1.size(); i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    long long average = (sum1 + sum2) / 2;
    int maxOperations = queue1.size() * 2, count = 0;
    
    if((sum1+sum2) % 2 == 1) return -1;
    
    while(count <= maxOperations *2)
    {
        if(sum1 == average) return count;
        
        if(sum1 > average)
        {
            int front = q1.front();
            q1.pop();
            q2.push(front);
            sum1 -= front;
            sum2 += front;
        }
        else
        {
            int front = q2.front();
            q2.pop();
            q1.push(front);
            sum2 -= front;
            sum1 += front;
        }
        count++;
    }
    
    return -1;
}