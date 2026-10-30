// https://leetcode.com/problems/max-area-of-island/description/

class Solution {
public:
    int ans = 0;
    int m, n;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    int dfs(int r, int c, vector<vector<int>>&grid){
        grid[r][c] = 0;

        int area = 1;
        
        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];

            //범위 내 && 섬 && 방문 x -> 탐색
            if(nr >=0 && nr < m && nc >=0 && nc < n && grid[nr][nc] == 1){
                area += dfs(nr, nc, grid);
            }
        }
        
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //1. 선언
        m = grid.size();
        n = grid[0].size();

        //2. 탐색
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                //미방문 && 1(섬) 이라면 탐색
                if(grid[r][c] == 1){
                    ans = max(ans, dfs(r, c, grid));
                }
            }
        }
        
        return ans;
    }
};