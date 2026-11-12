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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;

        //빈 트리일 경우
        if(root == nullptr) return answer;

        //bfs
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            //현재 레벨에 존재하는 노드 개수
            int size = q.size();

            //현재 레벨의 노드 값을 저장할 배열
            vector<int> level;

            //현재 레벨에 있는 노드만 처리
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                //현재 노드의 값 저장
                level.push_back(node -> val);

                //다음 레벨의 노드들을 큐에 삽입
                if(node -> left != nullptr){
                    q.push(node -> left);
                }

                if(node -> right != nullptr){
                    q.push(node-> right);
                }
            }

            //하나의 레벨 탐색 완료

            answer.push_back(level);
        }

        return answer;
    }
};