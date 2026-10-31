class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        # start_i를 기준으로 오름차순 정렬
        intervals.sort(key=lambda x:x[0])

        # 앞에서부터 붙어있는 두개를 비교: 구간이 겹치면 병합
        # 종료조건: 마지막 구간에서 병합이 일어나지 않았을 때
        i = 0
        while i+1<len(intervals):
            # [a,b] [x,y]에서 b >= x이면:
            if intervals[i][1] >= intervals[i+1][0]:
                # b >= y이면: [a,b]가 [x,y]를 포함하고 있으므로 [x,y]만 삭제
                if intervals[i][1] >= intervals[i+1][1]:
                    intervals = intervals[:i+1] + intervals[i+2:]

                # b < y이면: [a,b]를 [a,y]로 바꾼 후 [x,y] 삭제
                else:
                    intervals[i][1] = intervals[i+1][1]
                    intervals = intervals[:i+1] + intervals[i+2:]

            # 병합이 일어났으면 i를 증가시키지 말고 한번 더 루프
            else:
                i += 1
        
        return intervals