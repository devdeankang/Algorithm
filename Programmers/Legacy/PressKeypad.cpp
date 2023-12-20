#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 키패드 누르기
// https://programmers.co.kr/learn/courses/30/lessons/67256

int keypad[4][3];

void InitKeyPad()
{    
    int keyNum = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 3)
            {
                keypad[i][0] = -1;
                keypad[i][1] = 0;
                keypad[i][2] = -2;
                return;
            }
            keypad[i][j] = keyNum++;
        }
    }
    return;
}

vector<int> GetIndexOfKeyPad(int keyNum)
{
    vector<int> index = {0,0};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (keypad[i][j] == keyNum)
            {
                index[0] = i;
                index[1] = j;
                return index;
            }
        }
    }
    return index;
}

string GetLeftOrRight(int num)
{
    string hand = "";
    switch (num)
    {
    case 1:
    case 4:
    case 7:
        hand = "L";
        break;
    case 3:
    case 6:
    case 9:
        hand = "R";
        break;
    default:        
        break;
    }

    return hand;
}

string GetLeftOrRight(int num, int leftHand, int rightHand)
{    
    vector<int> target = GetIndexOfKeyPad(num);
    vector<int> curLeft = GetIndexOfKeyPad(leftHand);
    vector<int> curRight = GetIndexOfKeyPad(rightHand);
    int distanceOfLeft = abs(target[0]-curLeft[0]) + abs(target[1]-curLeft[1]);
    int distanceOfRight = abs(target[0] - curRight[0]) + abs(target[1] - curRight[1]);

    if (distanceOfLeft > distanceOfRight) return "R";
    else if (distanceOfLeft < distanceOfRight) return "L";
    else return "";    
}

string GetMainHand(string hand)
{
    if (hand == "left") return "L";
    else if (hand == "right") return "R";
    else return hand;
}

string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    int curLeftHand = -1;
    int curRightHand = -2;    
    string mainHand = GetMainHand(hand);

    InitKeyPad();
    
    for (int num : numbers)
    {
        string getLeftRight = GetLeftOrRight(num);

        if (getLeftRight == "")
        {
            string getLeftRightByCal = GetLeftOrRight(num, curLeftHand, curRightHand);
            if (getLeftRightByCal == "")
                answer.append(mainHand);
            else
                answer.append(getLeftRightByCal);

            getLeftRight = getLeftRightByCal;
        }
        else
        {
            answer.append(getLeftRight);            
        }

        if (getLeftRight == "L") curLeftHand = num;
        else if (getLeftRight == "R") curRightHand = num;
        else
        {
            if (mainHand == "L") curLeftHand = num;
            else curRightHand = num;
        }
    }
    
    return answer;    
}