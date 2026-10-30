//https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; //최소힙
        
        // priority_queue<
        //     T,          // 저장할 자료형
        //     Container,  // 내부 컨테이너
        //     Compare     // 비교 방식
        // >

        //최대 힙 priority_queue<int> pq;

        for(int num: nums){
            pq.push(num);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};