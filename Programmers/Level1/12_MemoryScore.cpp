#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 추억 점수
// https://school.programmers.co.kr/learn/courses/30/lessons/176963

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> table;
    
    for(int i =0; i<name.size(); i++)
    {
        table[name[i]] = yearning[i];
    }
    
    for(int i =0; i<photo.size(); i++)
    {
        int sum = 0;
        for(int j =0; j<photo[i].size(); j++)
        {
            if(table.find(photo[i][j]) != table.end())
                sum += table[photo[i][j]];
        }
        answer.push_back(sum);
    }
    
    return answer;
}