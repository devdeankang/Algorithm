#include <string>
#include <vector>

using namespace std;

// 양궁대회
// https://school.programmers.co.kr/learn/courses/30/lessons/92342

vector<int> answer = {-1};
int maxScoreDiff = 0;

void Backtrack(int idx, int arrows, vector<int>& myBoard, vector<int>& targetBoard) {
    if (idx == 11 || arrows == 0) 
    {
        if (arrows > 0) myBoard[10] += arrows;
                
        int myScore = 0, targetScore = 0;
        for (int i = 0; i < 11; ++i) 
        {
            if (myBoard[i] > targetBoard[i]) myScore += (10 - i);
            else if (targetBoard[i] > 0) targetScore += (10 - i);
        }
                
        int scoreDiff = myScore - targetScore;
        if (scoreDiff > maxScoreDiff) 
        {
            maxScoreDiff = scoreDiff;
            answer = myBoard;
        } else if (scoreDiff == maxScoreDiff) 
        {
            for (int i = 10; i >= 0; --i) 
            {
                if (myBoard[i] != answer[i]) 
                {
                    if (myBoard[i] > answer[i]) answer = myBoard;
                    break;
                }
            }
        }
                
        if (arrows > 0) myBoard[10] -= arrows;
        return;
    }
        
    if (arrows > targetBoard[idx]) 
    {
        myBoard[idx] = targetBoard[idx] + 1;
        Backtrack(idx + 1, arrows - myBoard[idx], myBoard, targetBoard);
        myBoard[idx] = 0;
    }
        
    Backtrack(idx + 1, arrows, myBoard, targetBoard);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> myBoard(11, 0);
    Backtrack(0, n, myBoard, info);
    return answer;
}