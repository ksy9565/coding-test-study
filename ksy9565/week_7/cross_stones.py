def solution(stones, k):
    answer = 0
    
    # num명이 건넌 후, k번 연속 0이 나오는지 계산하는 함수
    # k번 연속 0이 나오면 False 반환
    def cross_stones(num):
        count = 0
        for stone in stones:
            if stone <= num:
                count += 1
            else:
                count = 0
                
            if count >= k:
                return False
        return True
    
    # 예시에서 3명이 건널 수 있으나 num=3이면 False가 뜸
    # False가 뜨는 값 중 가장 작은 값이 건널 수 있는 최대 사람 수
    low, high = 0, max(stones)
    while low < high:
        mid = (low+high)//2
        
        if cross_stones(mid):
            low = mid + 1
        else:
            high = mid
    
    return low