#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이모티콘 할인행사
// https://school.programmers.co.kr/learn/courses/30/lessons/150368

int maxSubscribers = 0;
int maxSales = 0;
int rate[] = {10, 20, 30, 40};

int GetDiscountPrice(int price, int rate)
{
    return price * (100 - rate) / 100;
}

void Calculate(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discountSet)
{
    int subscribers = 0;
    int sales = 0;
    
    for(int i =0; i<users.size(); i++)
    {
        int discountLimit = users[i][0];
        int saleLimit = users[i][1];
        int totalCost = 0;
        
        for(int j=0; j<emoticons.size(); j++)
        {   
            if(discountSet[j] >= discountLimit)
            {
                totalCost += GetDiscountPrice(emoticons[j], discountSet[j]);
            }
        }
        
        if(totalCost >= saleLimit)
        {
            subscribers++;
        }
        else
        {
            sales += totalCost;
        }
    }
    
    if(subscribers > maxSubscribers)
    {
        maxSubscribers = subscribers;
        maxSales = sales;
    }
    else if (subscribers == maxSubscribers)
    {
        maxSales = max(sales, maxSales);
    }
}

void DFS(int idx, vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discountSet)
{
    if(idx == emoticons.size())
    {
        Calculate(users, emoticons, discountSet);
        return;
    }
    
    for(int i =0; i<4; i++)
    {
        discountSet[idx] = rate[i];
        DFS(idx+1, users, emoticons, discountSet);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> discountSet(emoticons.size(), 0); // 이모티콘들 할인율
    
    DFS(0, users, emoticons, discountSet);
    
    return {maxSubscribers, maxSales};
}