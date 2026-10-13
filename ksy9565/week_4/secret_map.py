def solution(n, arr1, arr2):
    answer = []

    # 십진수를 이진수 문자열로 바꾸는 함수(0:" ", 1:"#")
    def ten_to_two(num):
        if num == 0:
            return " " * n
        
        bin_num = ""
        for _ in range(n): # 이진수 변환, n자릿수 채움.
            if num % 2:
                bin_num = "#" + bin_num
            else:
                bin_num = " " + bin_num
            num = num // 2
        
        return bin_num

    # arr1과 arr2의 결과를 answer1, answer2에 각각 저장
    for i in range(n):
        answer1 = ten_to_two(arr1[i])
        answer2 = ten_to_two(arr2[i])

        result = ""
        for j in range(n):
            # answer1과 answer2를 비트or 연산처럼 합침
            if answer1[j] == "#" or answer2[j] == "#":
                result += "#"
            else:
                result += " "
        answer.append(result)
    
    return answer