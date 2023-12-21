#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 공백으로 구분하기 1
// https://school.programmers.co.kr/learn/courses/30/lessons/181869?language=cpp

vector<string> solution(string my_string) {
    vector<string> answer;
    istringstream ss(my_string);
    string buffer;
    while(getline(ss, buffer, ' '))
    {   
        answer.push_back(buffer);
    }
    
    return answer;
}