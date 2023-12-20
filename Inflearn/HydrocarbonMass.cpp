#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// 31. 탄화수소 질량
// 탄소 1개의 질량 12g, 수소 1개의 질량 1g일 때, 에틸렌(C2H4)의 질량은 28g이고 메탄(CH4)의 질량은 16g이다.
// 화합물의 질량을 구하는 프로그램
// 입력 값 : 탄화수소식
// 출력 값 : 입력 값으로 들어온 탄화수소식의 질량


int main()
{		
	int ret = 0;
	string str;
	cin >> str;

	string temp;
	int index_H = 1;
	if (str[1] == 'H') ret += 12;
	else
	{
		temp.clear();
		int i = 1;
		while (str[i] != 'H')
		{
			temp.push_back(str[i++]);			
		}
		index_H = i;
		ret += (stoi(temp) * 12);
	}	

	
	if (index_H == str.length() - 1) ret += 1;
	else 
	{
		temp.clear();
		int i = index_H+1;
		while (str[i] != '\0')
		{
			temp.push_back(str[i++]);
		}
		ret += stoi(temp);
	}


	cout << ret;

	return 0;
}