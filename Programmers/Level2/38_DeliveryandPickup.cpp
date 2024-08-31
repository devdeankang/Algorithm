#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 택배 배달과 수거하기
// https://school.programmers.co.kr/learn/courses/30/lessons/150369

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {    
    long long answer = 0;
    int delIndex = n - 1;
    int pickIndex = n - 1;

    while (delIndex >= 0 || pickIndex >= 0) {
        while (delIndex >= 0 && deliveries[delIndex] == 0) delIndex--;
        while (pickIndex >= 0 && pickups[pickIndex] == 0) pickIndex--;

        int maxDistance = max(delIndex, pickIndex) + 1;
        answer += maxDistance * 2;

        int delCap = cap;
        int pickCap = cap;

        for (int i = delIndex; i >= 0 && delCap > 0; i--) {
            if (deliveries[i] > 0) {
                int load = min(delCap, deliveries[i]);
                deliveries[i] -= load;
                delCap -= load;
            }
        }

        for (int i = pickIndex; i >= 0 && pickCap > 0; i--) {
            if (pickups[i] > 0) {
                int load = min(pickCap, pickups[i]);
                pickups[i] -= load;
                pickCap -= load;
            }
        }
    }

    return answer;
}