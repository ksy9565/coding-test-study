//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p, TreeNode* q) {

        while (root != nullptr) {

            // 1. p, q 모두 현재 노드보다 작은 경우
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // 2. p, q 모두 현재 노드보다 큰 경우
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // 3. 두 노드가 갈라지는 지점 또는 현재 노드가 p, q 중 하나인 경우
            else {
                return root;
            }
        }

        return nullptr;
    }
};