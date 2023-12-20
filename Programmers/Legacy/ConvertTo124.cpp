#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 124나라의 숫자
// https://programmers.co.kr/learn/courses/30/lessons/12899


string ConvertAs124(int n)
{
    if (n == 0) return "1";
    if (n == 1) return "2";
    if (n == 2) return "4";

    return ConvertAs124(n / 3 - 1) + ConvertAs124(n % 3);
}

string solution(int n) {
    string answer = ConvertAs124(n-1);
    return answer;
}