def solution(nodeinfo):
    answer = [[]]
    
    from collections import defaultdict
    import sys
    sys.setrecursionlimit(10**6) # 파이썬 재귀깊이 제한 확장
    
    for i in range(len(nodeinfo)):
        nodeinfo[i].append(i+1) # 노드 번호 저장
    
    nodeinfo.sort(key=lambda x:(-x[1], x[0])) # y축 내림차순, x축 오름차순 정렬
    left, right = defaultdict(int), defaultdict(int) # node의 자식 저장(left[parent] = child)
    
    # BST 삽입 함수
    # nodeinfo를 [level, value]라고 본다면
    # 정렬 후 level순으로 삽입할 때 루트부터 트리를 채울 수 있음.
    def insert(parent, child):
        parent = tuple(parent)
        
        # parent보다 왼쪽에 있다면
        if child[0] < parent[0]:
            if left[parent]: # 이미 left가 채워져 있으면 내려가서 삽입
                insert(left[parent], child)
            else:
                left[parent] = child # 없으면 바로 삽입 
                
        # parent보다 오른쪽에 있다면
        else:
            if right[parent]:
                insert(right[parent], child)
            else:
                right[parent] = child
    
    # 루트는 정렬 후 맨 앞에 있는 노드
    root = nodeinfo[0]
    
    # 그 다음 노드부터 순서대로 삽입
    for i in range(1, len(nodeinfo)):
        insert(root, nodeinfo[i])
    
    # 전위 순회: 기록 -> 왼쪽 -> 오른쪽
    def preorder(node, record):
        node = tuple(node)
        
        record.append(node[2])
        if left[node]:
            preorder(left[node], record)
        if right[node]:
            preorder(right[node], record)
        
        return record
    
    # 후위 순회: 왼쪽 -> 오른쪽 -> 기록
    def postorder(node, record):
        node = tuple(node)
        
        if left[node]:
            postorder(left[node], record)
        if right[node]:
            postorder(right[node], record)
        record.append(node[2])
        
        return record
    
    output = []
    output.append(preorder(root, []))
    output.append(postorder(root, []))
    return output
