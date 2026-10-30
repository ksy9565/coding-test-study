// https://leetcode.com/problems/combination-sum/description/

/*
* [DFS + 백트래킹]
* 1. DFS를 통해 candidates의 원소를 선택하며 target과 일치하는 조합 탐색
* 2. sum == target이면 현재 조합을 ans에 저장하고 탐색 종료
* 3. sum + candidates[i] > target이면 해당 후보를 건너뜀
*    - candidates가 정렬되어 있지 않으므로 break가 아닌 continue 사용
* 4. 현재 원소를 tmp에 추가한 후 dfs(i, ...) 호출
*    - 동일 원소를 여러 번 선택할 수 있으므로 i+1이 아닌 i 전달
*    - idx부터 탐색하여 순서만 다른 중복 조합 방지
* 5. DFS 종료 후 pop_back()으로 이전 상태 복구 (백트래킹)
*/

class Solution {
public:
    int s, n;
    vector<int> tmp;
    vector<vector<int>> ans;

    void dfs(int idx, int sum, int& target, vector<int>& tmp, vector<int>& candidates){
        if(sum == target){
            ans.push_back(tmp);
            return;
        }

        for(int i = idx; i<s; i++){
            if(sum + candidates[i] > target) continue; //정렬되어있다는 조건이 없으므로 continue로 다음 모든 idx를 탐색하게 함
            
            tmp.push_back(candidates[i]);
            dfs(i, sum + candidates[i], target, tmp, candidates);
            tmp.pop_back();
        }
    }

    // void dfs(int idx, int sum, int& target, vector<int>& tmp, vector<int>& candidates){
    //     sum += candidates[idx];
    //     tmp.push_back(candidates[idx]);

    //     if(sum == target){
    //         ans.push_back(tmp);
    //     }else if(sum <target){
    //         for(int i=idx; i<s; i++){
    //             dfs(i, sum, target, tmp, candidates);
    //         }
    //     }

    //     tmp.pop_back();
    //     return;
    // }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        s = candidates.size();
        n = s / target + 1;

        dfs(0, 0, target, tmp, candidates);

        return ans;
    }
};