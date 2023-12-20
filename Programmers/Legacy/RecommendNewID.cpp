#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 신규 아이디 추천
// https://programmers.co.kr/learn/courses/30/lessons/72410


char ConvertToLower(char ch)
{    
    if (ch >= 65 && ch <= 90)
    {
        ch += 32;
    }
    return ch;
}

bool IsLowerCase(char ch)
{
    if (ch >= 97 && ch <= 122) return true;    
    return false;
}

bool IsNumber(char ch)
{
    if (ch >= 48 && ch <= 57) return true;
    return false;
}

bool IsValidCharacter(char ch)
{
    if (ch == 45 || ch == 46 || ch == 95) return true;
        return false;
}

string DeduplicateDot(string id)
{
    int max = id.length();
    for (int i = 1; i < max;)
    {
        if (id[i] == '.' && id[i - 1] == '.')
        {
            id.erase(id.begin() + i);
            continue;
        }
        else
            i++;
    }    
    return id;
}

string RemoveDotOfStartEnd(string id)
{
    if (id.length() == 0) return id;
    if (id.front() == '.') id.erase(id.begin());
    if (id.length() == 0) return id;
    if (id.back() == '.') id.erase(id.end() - 1);

    return id;
}

string Remove16OrMore(string id)
{
    if (id.length() >= 16) 
    {
        id.erase(15, id.length());
    }
    id = RemoveDotOfStartEnd(id);
    return id;
}

string RepeatChar(string id)
{
    if (id.length() <= 2)
    {
        while (id.length() < 3)
        {            
            id += id.back();
        }
    }
    return id;
}


string solution(string new_id) {
    string answer = "";
    
    for (char element : new_id) 
    {
        // 소문자 변환
        char ch = ConvertToLower(element);

        // 특수문자 제거
        if (IsLowerCase(ch) == true || IsNumber(ch) == true || IsValidCharacter(ch) == true) 
            answer += ch;
    }

    // 점 중복제거
    answer = DeduplicateDot(answer);

    // 점 시작,끝 제거
    answer = RemoveDotOfStartEnd(answer);
    
    // 빈 문자열이면 a
    if (answer.length() == 0) answer = "a";

    // 16자리 제거
    answer = Remove16OrMore(answer);    

    // 2자리 이하면 마지막 문자 반복
    answer = RepeatChar(answer);

    return answer;
}