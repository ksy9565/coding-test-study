// 더 긴 LIS 발견: 길이 갱신 + 경우의 수 교체
// 같은 길이 LIS 발견: 경우의 수 누적

//https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxLen;
        int ans = 0;

        // dp[i]  : i번째 원소에서 끝나는 LIS의 최대 길이
        // cnt[i] : i번째 원소에서 끝나는 LIS 중 최대 길이를 가지는 경우의 수
        vector<int> dp(nums.size());
        vector<int> cnt(nums.size());

        dp[0] = 1;
        cnt[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            // 자기 자신만 선택하는 경우
            dp[i] = 1;
            cnt[i] = 1;

            // i 앞의 모든 원소를 확인
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {

                    // 기존보다 더 긴 LIS를 발견한 경우
                    // j에서 끝나는 LIS 뒤에 nums[i]를 붙임
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }

                    // 현재 최대 길이와 같은 LIS를 추가로 발견한 경우
                    // j에서 만들어지는 경우의 수를 누적
                    else if (dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        // 전체 LIS의 최대 길이
        maxLen = *max_element(dp.begin(), dp.end());

        // 최대 길이를 가지는 모든 LIS의 개수를 합산
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == maxLen)
                ans += cnt[i];
        }

        return ans;
    }
};