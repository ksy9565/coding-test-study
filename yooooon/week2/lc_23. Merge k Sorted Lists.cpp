//https://leetcode.com/problems/merge-k-sorted-lists/description/

/*
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 */


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // 최소 힙
        // val이 작은 ListNode*가 top에 오도록 설정
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue< ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // 각 연결 리스트의 첫 번째 노드를 힙에 넣음
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        // 결과 연결 리스트의 시작을 쉽게 만들기 위한 tmp 노드
        ListNode tmp(0);
        ListNode* cur = &tmp;

        while (!pq.empty()) {
            // 현재 가장 작은 노드
            ListNode* node = pq.top();
            pq.pop();

            // 결과 리스트에 연결
            cur->next = node;
            cur = cur->next;

            // 방금 꺼낸 노드 뒤에 다음 노드가 있다면 다시 최소 힙에 넣음
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return tmp.next;
    }
};