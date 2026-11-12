// https://leetcode.com/problems/merge-intervals/description/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        // 1. 시작점을 기준으로 오름차순 정렬
        sort(intervals.begin(), intervals.end());

        // 2. 첫 번째 구간 삽입
        ans.push_back(intervals[0]);

        // 3. 나머지 구간 확인
        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // 이전 병합 구간의 종료점
            int prevEnd = ans.back()[1];

            if (start <= prevEnd) {
                // 겹치는 경우: 종료점 확장
                ans.back()[1] = max(prevEnd, end);
            } else {
                // 겹치지 않는 경우: 새로운 구간 추가
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
