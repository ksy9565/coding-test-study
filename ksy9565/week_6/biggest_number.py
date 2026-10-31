def solution(numbers):
    answer = ''
    
    # 커스텀 비교 함수
    # str으로 바꿔서 더하면 330과 303으로 비교 가능
    def compare(x, y):
        if str(x)+str(y) > str(y)+str(x):
            return True
        return False
    
    # 병합 정렬 함수
    # merge_sort: 반씩 분할하여 merge 실행
    def merge_sort(arr):
        if len(arr) <= 1:
            return arr
        
        mid = len(arr) // 2
        left = merge_sort(arr[:mid])
        right = merge_sort(arr[mid:])
        
        return merge(left, right)
    
    # merge: 왼쪽 리스트와 오른쪽 리스트의 0번 인덱스부터 비교
    # 기준: compare 함수
    # 더 큰 결과가 나오는 순서대로 병합
    def merge(left, right):
        sorted_list = []
        i = j = 0
        
        while i < len(left) and j < len(right):
            if compare(left[i], right[j]):
                sorted_list.append(left[i])
                i += 1
            else:
                sorted_list.append(right[j])
                j += 1

        sorted_list.extend(left[i:])
        sorted_list.extend(right[j:])
        return sorted_list
    
    numbers = merge_sort(numbers)
    numbers = list(map(str, numbers))
    answer = ''.join(numbers)
    if answer[0] == '0':
        return '0'
    
    
    ### 내장 정렬 이용
    from functools import cmp_to_key
    
    # 내림차순 정렬이므로 오름차순의 부호 반대로 return
    def compare(x, y):
        if str(x)+str(y) > str(y)+str(x):
            return -1
        elif str(x)+str(y) < str(y)+str(x):
            return 1
        return 0
    
    numbers.sort(key=cmp_to_key(compare))
    numbers = list(map(str, numbers))
    answer = ''.join(numbers)
    
    if answer[0] == '0':
        return '0'
    
    return answer