// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;

            // mid 속도로 먹을 때 필요한 총 시간
            for (int p : piles) {
                hours += (p + (long long)mid - 1) / mid;
            }

            if (hours <= h) {
                // 시간 내에 먹을 수 있음
                // 더 느린 속도도 가능한지 확인
                right = mid;
            } else {
                // 시간이 부족 -> 속도를 높여야 함
                left = mid + 1;
            }
        }

        return left;
    }
};
