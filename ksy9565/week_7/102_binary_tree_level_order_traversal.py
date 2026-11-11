# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode | None) -> list[list[int]]:
        from collections import deque

        if root is None:
            return []

        answer = []

        # 큐에 root 넣고 bfs 실행
        q = deque()
        q.append(root)

        while q:
            level = len(q)
            curr = [] # 현재 레벨의 노드를 저장할 리스트
            
            # 같은 레벨의 노드를 한번에 처리할 필요가 있으므로 level번 pop
            for _ in range(level):
                node = q.popleft()

                curr.append(node.val)

                # 자식 노드를 큐에 추가
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            # 현재 레벨 순회가 끝나면 answer에 추가
            answer.append(curr)
        
        return answer
        