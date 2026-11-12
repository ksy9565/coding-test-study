// https://school.programmers.co.kr/learn/courses/30/lessons/64062

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = INT_MAX;
    deque<int> dq;

    for (int i = 0; i < stones.size(); i++) {

        // 1. 현재 돌보다 작거나 같은 값은 뒤에서 제거
        //    현재 돌보다 작으면 이후 최댓값이 될 수 없음
        while (!dq.empty() &&
               stones[dq.back()] <= stones[i]) {
            dq.pop_back();
        }

        // 2. 현재 돌의 인덱스 삽입
        dq.push_back(i);

        // 3. 윈도우 범위를 벗어난 인덱스 제거
        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        // 4. 윈도우 크기가 k가 되면 최댓값 확인
        if (i >= k - 1) {
            int maxValue = stones[dq.front()];

            // 모든 구간의 최댓값 중 최솟값 갱신
            answer = min(answer, maxValue);
        }
    }

    return answer;
}

// /*
// 이분 탐색으로 풀이
// 1. mid명이 건널수 있는가를 기준으로 이분탐색을 진행
// 2. mid 번쨰 사람이 건널 수 있는지 확인
//     - stones[i] >= mid : 해당 돌을 밟을 수 있음
//     - stones[i] < mid : 해당 돌을 밟을 수 없음
// 3. 밟을 수 없는 돌이 k개 연속이면 건널 수 없음 ** 중요
// 4. 건널 수 있다면 -> 더 많은 인원(mid + 1)
//    건널 수 없다면 -> 더 적은 인원 탐색
// */



// bool cross(const vector<int>& stones, int k, int mid){
//     int cnt = 0;
    
//     for(int stone : stones){
//         if(stone < mid){
//             cnt ++;
//         } else{
//             cnt = 0;
//         }
        
//         if(cnt >= k) return false;
//     }
    
//     return true;
// }

// int solution(vector<int> stones, int k) {
//     int ans = 0;
//     int left = 1;
//     int right = *max_element(stones.begin(), stones.end());
    
//     while(left <= right){
//         int mid = left + (right - left) / 2;
        
//         if(cross(stones, k, mid)){
//             ans = mid;
//             left = mid + 1;
//         } else{
//             right = mid - 1;
//         }
//     }
    
//     return ans;
// }