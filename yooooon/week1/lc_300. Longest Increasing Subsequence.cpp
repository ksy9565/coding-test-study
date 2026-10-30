// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dp(nums.size());
        dp[0] = 1;

        for(int i=1; i<nums.size(); i++){
            dp[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // for(auto a : dp)
        //     cout << a << "\n";

        // return 0;

        ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};