#include <string>
#include <vector>
#include <set>

using namespace std;

// 배열의 원소 삭제하기
// https://school.programmers.co.kr/learn/courses/30/lessons/181844?language=cpp

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    set<int> sArr;
    set<int>::iterator it;
    
    for(int i = 0; i<delete_list.size(); i++)
    {
        sArr.insert(delete_list[i]);
    }
    
    for(int i =0; i<arr.size(); i++)
    {
        int target = arr[i];
        it = sArr.find(target);
        if(it == sArr.end())
        {
            answer.push_back(target);
        }
    }
    
    return answer;
}