#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 공원 산책
// https://school.programmers.co.kr/learn/courses/30/lessons/172928

pair<int, int> GetDirection(string str)
{
    switch (str[0])
    {
    case 'E':
        return make_pair(0, 1);
    case 'W':
        return make_pair(0, -1);
    case 'S':
        return make_pair(1, 0);
    case 'N':
        return make_pair(-1, 0);
    }
    return make_pair(0, 0);
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = -1, y = -1;

    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                x = i, y = j;
                break;
            }
        }
    }
    
    for (int i = 0; i < routes.size(); i++)
    {
        stringstream ss(routes[i]);
        string buffer;
        vector<string> dir;
        while (getline(ss, buffer, ' '))
        {
            dir.push_back(buffer);
        }
        pair<int, int> direction = GetDirection(dir[0]);
        int offset = stoi(dir[1]);

        int dirX = direction.first * offset;
        int dirY = direction.second * offset;

        if (x + dirX < 0 || x + dirX >= park.size() || y + dirY < 0 || y + dirY >= park[0].size()) continue;

        bool isObstacleZone = false;        
        for(int t = 1; t <= offset; t++)
        {
            if(park[x + (direction.first * t)][y + (direction.second * t)] == 'X') isObstacleZone = true;
        }

        if (isObstacleZone == false)
        {
            x += dirX;
            y += dirY;
        }
    }

    answer.push_back(x);
    answer.push_back(y);
    return answer;
}