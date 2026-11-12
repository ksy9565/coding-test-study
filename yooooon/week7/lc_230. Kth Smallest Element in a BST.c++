// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int count = 0;

        // 중위 순회 : 왼 -> 중 -> 오
        while (cur != nullptr || !st.empty()) {

            // 1. 가장 왼쪽 노드까지 이동
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            // 2. 스택에서 노드를 꺼내 방문
            cur = st.top();
            st.pop();

            count++;

            // 3. k번째로 작은 값 발견
            if (count == k) {
                return cur->val;
            }

            // 4. 오른쪽 서브트리 탐색
            cur = cur->right;
        }

        return -1;
    }
};

