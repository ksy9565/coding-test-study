//https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

class Solution {
public:
    int findTheWinner(int n, int k) {

        //1. 선언
        //friends 벡터 선언
        vector<int> friends;

        for(int i=1; i<=n; i++){
            friends.push_back(i);
        }

        int idx = 0;

        //2. 반복 및 찬구 지우기
        while(friends.size() > 1){
            //종료 조건 : size = 1일때 (= 친구가 한명 남을 때)

            //idx를 % 연산자를 이용하여 판별 후 지우기
            idx = (idx + k - 1) % friends.size();
            friends.erase(friends.begin() + idx);

            //특이 케이스 : 마지막 인자를 지웠을 때
            //if문 쓰거나 %를 이용하기?
            if(idx == friends.size()) idx = 0;
        }

        return friends[0];
    }
};