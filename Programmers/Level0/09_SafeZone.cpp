#include <string>
#include <vector>

using namespace std;

// 안전지대
// https://school.programmers.co.kr/learn/courses/30/lessons/120866

int solution(vector<vector<int>> board) {
    int answer = 0, size = 0;
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0 };
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1 };

    size = board.size();
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            bool isSafeZone = true;            
            if(board[i][j] == 1) continue;
            
            for(int k =0; k<8; k++)
            {  
                int dirX = i+dx[k];
                int dirY = j+dy[k];
                                
                if(dirX < 0 || dirX >= size || dirY < 0 || dirY >= size ) 
                    continue;
                
                if(board[dirX][dirY] == 1) 
                {
                    isSafeZone = false;
                    break;
                }
            }
            
            if(isSafeZone == true) answer++;
        }
    }
        
    return answer;
}