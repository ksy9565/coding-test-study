// https://leetcode.com/problems/network-delay-time/description/

class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int d[101];
    int ans = -1;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //입력
        //n : 노드 개수
        //k : 문제에서 주어진 시작 노드
        //times[i] = (출발 노드, 도착 노드, 가중치);

        //출력
        //모든 노드가 시그널을 받을 때까지의 최소시간
        //불가능하다면 -1 반환


        //1. 그래프 만들기
        //{비용, 도착정점}
        vector<pair<int, int>> adj[101];

        for(auto t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({w, v});
        }

        //2. 최단거리 배열 초기화
        fill(d, d+n+1, INF);
        d[k] = 0;

        //3. 우선순위 큐 만들기
        // {시작 정점 k에서 해당 정점까지의 거리, 정점 번호}
        priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>> pq;

        //4. 시작 정점을 우선순위 큐에 넣기
        //시작정점까지의 거리, 시작정점 번호
        pq.push({0, k});

        //5. 반복문
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            if(cur.first != d[cur.second]) continue;
            for(auto nxt: adj[cur.second]){
                //cur.second : 현재 탐색 중인 정점 번호
                //adj[cur.second] : 현재 정점에서 이동할 수 있는 간선들
                //nxt.first : 간선의 가중치
                //nxt.second : 도착 정점 번호


                //기존 최단거리가 짧아질 경우에만 갱신
                if(d[nxt.second] <= d[cur.second] + nxt.first) continue;

                //더 짧은 경로를 찾았으므로 다음 정점의 최단 거리 갱신
                d[nxt.second] = d[cur.second] + nxt.first;

                //갱신된 거리와 다음 정점 번호를 우선순위 큐에 추가
                pq.push({d[nxt.second], nxt.second});
            }   
        }

        for(int i=1; i<=n; i++){
            if(d[i] == INF) return -1;

            ans = max(ans, d[i]);
        }

        return ans;
        
    }
};

