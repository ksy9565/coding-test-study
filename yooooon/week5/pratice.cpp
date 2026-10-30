//개선된 다익스트라
//추가 : pre테이블 - 경로 복원
//최단 거리를 갱신할 때 pre 테이블도 갱신
//시작점에서 나에게로 올때 어디를 방문했는지 확인

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e, st;

//{비용, 정점 번호}
vector<pair<int, int>> adj[20005];
const int INF = 129 + 10;
int d[20005]; //최단 거리 테이블
int main(void){
    cin >> v >> e >> st;
    fill(d, d + v + 1, INF);
    while(e--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    d[st] = 0;
    //우선순위 큐에 {0, 시작점} 추가
    pq.push({d[st], st});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    for (int i = 1; i <= v; i++){
        if(d[j] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}   





//다익스트라 기본형
// // {비용, 간선, 번호}
// vector<pair<int, int>> adj[20005];

// const int INF = 0x3f3f3f3f;
// bool fix[20005];
// int v = 10;
// void dik(int st){
//     fill(d, d + V + 1, INF); // 최단거리 테이블 초기화
//     d[st] = 0;
//     whild(true){
//         int idx = -1;
//         for (int i = 1; i <= V; i++){
//             if(fix[i]) continue;
//             if(idx == -1) idx = 1;
//             else if(d[i] < d[idx]) idx = i;
//         }
//         if(idx == -1 || d[dix] == INF) // 더이상 선택할 정점이 없으면
//             break;
//         fix[idx] = 1; //정점 idx 고정
//         for(auto nxt : adj[idx])
//             d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.Y);
//     }
// }