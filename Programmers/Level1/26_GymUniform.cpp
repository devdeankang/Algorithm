#include <string>
#include <vector>

using namespace std;

// 체육복
// https://school.programmers.co.kr/learn/courses/30/lessons/42862

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;    
    vector<int> students(n+2, 1);
    
    students[0] = students[n+1] = 0;    

    for(int r : reserve)
    {
        students[r] = 2;
    }
    
    for(int l : lost)
    {
        students[l] -= 1;
    }
    
    for(int i =1; i<=n; i++)
    {        
        if(students[i] == 0)
        {
            if(students[i-1] > 1)
            {
                students[i-1] -= 1;
                students[i] += 1;
            }
            else if(students[i+1] >1)
            {
                students[i+1] -= 1;
                students[i] += 1;
            }
        }
    }
    
    for(int student : students)
    {
        if(student > 0) answer++;
    }
    
    return answer;
}