#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 공백으로 구분하기 2
// https://school.programmers.co.kr/learn/courses/30/lessons/181868

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream ss(my_string);
    string buffer;
    
    while(getline(ss, buffer, ' '))
    {
        if(buffer != "")
            answer.push_back(buffer);
    }
    return answer;
}