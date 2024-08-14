#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 호텔 대실
// https://school.programmers.co.kr/learn/courses/30/lessons/155651

struct Booking{
    int start, end;
    bool operator<(const Booking& other) const{
        return end > other.end;
    }
};

int ToMinutes(string time)
{
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return hour * 60 + min;
}

int solution(vector<vector<string>> book_time) {
    
    vector<Booking> books;
    priority_queue<Booking> pq;
    for(int i = 0; i<book_time.size(); i++)
    {
        Booking temp;
        temp.start = ToMinutes(book_time[i][0]);
        temp.end = ToMinutes(book_time[i][1]);
        books.push_back(temp);
    }
    sort(books.begin(), books.end(), [](Booking& a, Booking& b){
        return a.start < b.start;
    });
        
    for(int i=0; i<books.size(); i++)
    {
        Booking current = books[i];
        
        if(!pq.empty() && pq.top().end <= current.start)
        {
            pq.pop();
        }
        current.end += 10;
        pq.push(current);
    }
    
    
    return pq.size();
}