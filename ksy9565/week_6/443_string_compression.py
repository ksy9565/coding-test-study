class Solution:
    def compress(self, chars: list[str]) -> int:
        
        # You must write an algorithm that uses only constant extra space.
        # 리스트 슬라이싱 등 범위 수정 불가 -> 한칸씩 r/w 해야함.
        # The characters in the array beyond the returned length do not matter and should be ignored.
        # 배열 전체를 수정하지 않아도 되는 조건 -> 정답 배열의 길이까지만 제출하면 됨

        # 투 포인터를 통해 r/w를 분리
        r = 0 # read 포인터
        w = 0 # write 포인터

        while r < len(chars):
            # 문자를 만나면 char에 문자 저장
            char = chars[r]
            count = 0

            # char와 다른 문자를 만날 때까지 카운팅
            while r < len(chars) and chars[r] == char:
                r += 1
                count += 1
            
            # 카운팅이 끝난 후 w 포인터 자리에서 결과 쓰기 시작
            # 문자를 적은 후, 개수는 문자열로 변환하여 작성
            # write가 아직 읽지 않은 문자에 영향을 주지 않음
            chars[w] = char
            w += 1

            if count > 1:
                for i in str(count):
                    chars[w] = i
                    w += 1

        return w