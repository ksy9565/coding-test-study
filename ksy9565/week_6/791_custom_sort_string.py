class Solution:
    def customSortString(self, order: str, s: str) -> str:

        order_dict = {}
        for i in range(len(order)):
            order_dict[order[i]] = order.index(order[i]) # 인덱스 순서를 반환하는 맵 {a:2, b:1, c:0}
        
        result = sorted(s, key=lambda x:order_dict.get(x, len(order))) # getOrDefault와 유사. key는 작은 수부터 오름차순 배치
        # result = sorted(s, key=lambda x:order.index(x)) -> order에 없는 입력이 들어올 시 ValueError: substring not found

        return ''.join(result)