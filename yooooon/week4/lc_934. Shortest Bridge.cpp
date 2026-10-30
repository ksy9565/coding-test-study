// https://leetcode.com/problems/shortest-bridge/description/

/*
* 1. dfs를 통해 첫번째 섬의 정보를 q에 삽입, isVis에 표시
*   q: 앞으로 BFS로 탐색할 좌표를 저장
*   isVis: 이미 방문한 좌표인지 확인해서 중복 탐색 방지
* 2. 해당 섬으로부터 qSize만큼 1 depth 씩 두번째 섬을 만날때까지 bfs 탐색
* 3. depth 값 반환
*/

class Solution {
public:
    bool flag = false;
    int r, c, ans = 0;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    vector<vector<bool>> isVis;
    queue<pair<int, int>> q;

    void dfs(int now_r, int now_c, vector<vector<int>>& grid){
        isVis[now_r][now_c] = true;
        q.push({now_r, now_c});

        for(int d=0; d<4; d++){
            int nr = now_r + dr[d];
            int nc = now_c + dc[d];

            if(nr >=0 && nr < r && nc >= 0 && nc < c && !isVis[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        //1. 1개의 섬만 표시하기
        
        r = grid.size();
        c = grid[0].size();

        isVis.assign(r, vector<bool>(c, false));

        //섬 1개만 찾고 나옴, 한 개의 섬은 isVis의 map에 저장되어있음
        for(int i=0; i<r && !flag; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid);
                    flag = true;
                    break;
                }
            }
        }

        //이제 isVis를 1 depth씩 bfs시켜서 처음 isVis에 없는 1을 만날때 그 depth를 반환하게 하기
        // 탐색은 모든 방향으로 시키기

        while(!q.empty()){
            int qSize = q.size();
            for(int i=0; i<qSize; i++){
                for(int d=0; d<4; d++){
                    int nr = q.front().first + dr[d];
                    int nc = q.front().second + dc[d];

                    if(nr >= 0 && nr < r && nc >= 0 && nc < c && !isVis[nr][nc]){
                        if(grid[nr][nc] == 1){
                            return ans;
                        }else if(grid[nr][nc] == 0){
                            isVis[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
                q.pop();
            }
            ans ++;
        }

        return ans;
    }
};