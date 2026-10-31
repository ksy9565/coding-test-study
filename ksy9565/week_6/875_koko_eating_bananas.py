class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:

        def eating(k):
            count = 0
            # k개씩 먹을 때 몇 시간이 걸리는지 구함
            for i in range(len(piles)):
                count += (piles[i]+k-1) // k # 올림 연산: (p + k-1) // k
            
            # h보다 덜 걸리면 True, 더 걸리면 False 반환
            return h >= count

        # 이분탐색: 1 <= k <= max(piles)이고,
        # eating 함수의 count가 k에 비례해 단조 감소함
        # lower bound로 탐색하여 조건을 만족하는 최소 k를 찾을 수 있음
        
        # lower bound: 구간의 오른쪽에서 이미 조건을 만족하는 k를 찾았더라도
        # 더 왼쪽을 탐색하여 조건을 만족하는 최소 k값을 찾음.

        # upper bound: 더 오른쪽을 탐색하여 최대 k보다 처음으로 큰 값을 찾음.
        low, high = 1, max(piles)
        while low < high:
            mid = (low+high)//2

            if eating(mid):
                high = mid
            else:
                low = mid + 1
        
        return low

