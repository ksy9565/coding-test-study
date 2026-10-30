// https://www.codetree.ai/ko/frequent-problems/all/problems/easy-workshop/description



//아래는 dfs 완전 탐색으로 푼 것

// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int n, k;
// int ans = INT_MAX;
// vector<vector<int>> maps;

// int dr[4] = {1, 0, -1, 0};
// int dc[4] = {0, -1, 0, 1};

// void dfs(int r, int c, int cnt, int curMax){
//     if(curMax >= ans) return;
//     if(cnt >= k){
//         //갱신
//         ans = min(ans, curMax);
//         return;
//     }

//     for(int d = 0; d<4; d++){
//         int nr = r + dr[d];
//         int nc = c + dc[d];

//         //벽 안, 증가 -> 이동
//         if(nr >=0 && nr < n && nc >= 0 && nc <n && maps[nr][nc] > maps[r][c]){
//             int nextMax = max(curMax, maps[nr][nc] - maps[r][c]);
//             dfs(nr, nc, cnt+1, nextMax);
//         }

//         //벽 밖이라면?
//     }

// }

// int main() {
//     // Please write your code here.

//     //1. 입력 및 선언
//     //n: 산의 크기, k: 등산로 길이
//     //maps[i][j]는 각 등산로의 높이

//     cin >> n >> k;

//     maps.assign(n, vector<int>(n)); 

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             int a;
//             cin >> a;
//             maps[i][j] = a;
//         }
//     }

//     //2. 탐색

//     //모든 시작점에서 탐색
//     for(int r=0; r<n; r++){
//         for(int c=0; c<n; c++){
//             dfs(r, c, 1, -0);   
//         }
//     }
    
//     if(ans == INT_MAX) cout << -1;
//     else    cout << ans;

//     return 0;
// }