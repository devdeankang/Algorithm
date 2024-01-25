#include <string>
#include <vector>

using namespace std;

// 신규 아이디 추천
// https://school.programmers.co.kr/learn/courses/30/lessons/72410


string solution(string new_id) {
    string answer, temp;
    
    // 1. 소문자 치환
    for(char &ch : new_id)
    {
        ch = tolower(ch);
    }
        
    // 2. 소문자, 숫자, -, _, . 제외한 문자 제거
    for(auto ch : new_id)
    {
        if(islower(ch) || isdigit(ch) || ch == '-' || ch == '_' || ch == '.')
        {
            temp.push_back(ch);
        }
    }
    
    // 3. 마침표 두번 이상이면 하나로 치환
    for(char ch : temp)
    {
        if(!answer.empty() && answer.back() == '.' && ch == '.') continue;        
        answer.push_back(ch);
    }
    
    // 4. 마침표 처음과 끝이면 제거
    if(!answer.empty() && answer.front() == '.') answer.erase(answer.begin());
    if(!answer.empty() && answer.back() == '.') answer.erase(answer.end()-1);
    
    // 5. 빈 문자열
    if(answer.empty()) answer = "a";
    
    // 6. 길이가 16자 이상이면 15까지만 반환
    if(answer.length() >= 16)
    {
        answer.erase(15);
        if(answer.back() == '.') answer.erase(answer.end()-1);
    }
    
    // 7. 길이가 2자 이하면 마지막 문자로 길이 3자까지 붙임
    while(answer.length() < 3)
    {
        answer.push_back(answer.back());
    }
    
    return answer;
}