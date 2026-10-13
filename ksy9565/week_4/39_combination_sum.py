from collections import deque

class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        n = len(candidates)

        # 만들 수 있는 중복조합을 완전 탐색하며 조건에 맞는 조합만 골라내면 되므로, dfs나 bfs 중 골라서 하면 됨
        # dfs가 좀 더 직관적인 것 같으므로(작은 수부터 끝까지 덧셈) dfs를 골라 해보겠음.
        candidates.sort() # 오름차순 정렬
        answer = []
        for i in range(n):
            q = deque()
            
            if candidates[i] == target:
                answer.append([candidates[i]])
            else:
                q.append(([candidates[i]], i)) # [조합], candidates의 인덱스
            
            while q:
                comb, idx = q.pop()
                for curr in range(idx, n):
                    comb.append(candidates[curr])
                    s = sum(comb)
                    if s == target:
                        answer.append(comb[:])
                    elif s > target:
                        break
                    else: # s가 작은 경우
                        q.append((comb[:],curr))

                    comb.pop()
        
        return answer