// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int ss = s.size();
        vector<vector<int>> dp(ss, vector<int>(ss));
        // dp[i][j] = s의 i번째부터 j번째까지 구간에서 만들 수 있는 가장 긴 팰린드롬 부분수열의 길이

        // dp[i][j]를 구할 때 dp[i+1][...] 값이 필요하므로 i는 뒤에서부터 앞으로 이동
        for(int i=ss-1; i>=0; i--){
            dp[i][i] = 1;

            for(int j=i+1; j<ss; j++){
                if(s[i] == s[j]){
                    //(안쪽구간) + 2;
                    dp[i][j] = dp[i+1][j-1] +2;
                }
                else if(s[i] != s[j]){
                    // 이전값을 그대로 가져옴
                    
                    // 양 끝 문자가 다르면 둘을 동시에 양 끝으로 사용할 수 없음
                    // → 왼쪽 문자를 제외한 경우와 오른쪽 문자를 제외한 경우 중
                    //   더 긴 팰린드롬 부분수열을 선택
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][ss-1];
    }
};