//https://school.programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int tSize;
string nextCity;
vector<bool> isUsed;

bool dfs(string startCity, vector<string>& answer, vector<vector<string>>& tickets){
    //모두 찾으면 true를 반환
    if(answer.size() == tSize +1) return true;
    
    //탐색 시작
    for(int i=0; i<tSize; i++){
        //출발 티켓이 존재 && 쓰이지 않은 상태
        if(tickets[i][0] == startCity && !isUsed[i]){
            isUsed[i] = true;   //사용으로 바꿈
            answer.push_back(tickets[i][1]);
            
            //dfs가 성공이어서 true를 반환한다면 이어서 true를 반환해서 재귀를 빠져나옴
            if(dfs(tickets[i][1], answer, tickets))
                return true;
            
            //false라면 back하기
            answer.pop_back();
            isUsed[i] = false;
        }
    }
    
    return false;
}

// void dfs(string startCity, vector<string>& answer, vector<vector<string>>& tickets){
//     //시작 도시, 정답, 티켓
//     string nextCity;
//     //dfs 로직 구현
//     for(int i=0; i<tSize; i++){
//         //[0]이 시작도시인 티켓 && 미사용 티켓
//         if(tickets[i][0] == startCity && !isUsed[i]){
//             nextCity = tickets[i][1];   //도착 도시 티켓
//             answer.push_back(nextCity); //ans에 추가
//             isUsed[i] = true;           //사용으로 바꿈
//             dfs(nextCity, answer, tickets); //dfs 돌리기
            
//             // 모든 곳이 방문되지 않았다면  (=ans의 크기와 티켓의 크기가 다름)
//             // back하는게 필요함
//             if(answer.size() != tSize +1){
//                 answer.pop_back();
//                 isUsed[i] = false;
//             }
//         }
//     }
// }

// void dfs(string startCity, vector<string>& answer, vector<vector<string>>& tickets){
//     //시작 도시, 정답, 티켓
//     string nextCity;
//     //dfs 로직 구현
//     for(int i=0; i<tSize; i++){
//         //[0]이 시작도시인 티켓 && 미사용 티켓
//         if(tickets[i][0] == startCity && !isUsed[i]){
//             nextCity = tickets[i][1];   //도착 도시 티켓
//             answer.push_back(nextCity); //ans에 추가
//             isUsed[i] = true;           //사용으로 바꿈
//             dfs(nextCity, answer, tickets); //dfs 돌리기
            
//             // 모든 곳이 방문되지 않았다면  (=ans의 크기와 티켓의 크기가 다름)
//             // back하는게 필요함
//             if(answer.size() != tSize +1){
//                 answer.pop_back();
//                 isUsed[i] = false;
//             }
//         }
//     }
// }
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    tSize = tickets.size();
    isUsed.assign(tSize, false); //티켓 사용 여부를 판별
    
    sort(tickets.begin(), tickets.end()); //알파벳 순으로 정렬
    
    answer.push_back("ICN");
    dfs("ICN", answer, tickets);

    
    return answer;
}