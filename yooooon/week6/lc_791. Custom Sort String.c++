//https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {0, };
        string ans = "";

        // 1. s에 등장하는 문자 개수 세기
        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        // 2. order 순서대로 문자 추가
        for (char ch : order) {
            while (cnt[ch - 'a'] > 0) {
                ans += ch;
                cnt[ch - 'a']--;
            }
        }

        // 3. order에 없는 나머지 문자 추가
        for (int i = 0; i < 26; i++) {
            while (cnt[i] > 0) {
                ans += char('a' + i);
                cnt[i]--;
            }
        }

        return ans;
    }
};
