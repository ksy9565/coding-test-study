# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode | None, k: int) -> int:
        
        answer = None

        def inorder(node):
            nonlocal k, answer
            
            if node is None:
                return

            inorder(node.left)

            k -= 1
            if k == 0:
                answer = node.val
                return
            
            inorder(node.right)
        
        inorder(root)
        return answer