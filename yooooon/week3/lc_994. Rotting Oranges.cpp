//https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int m, n, depth = -1;
    //depth = -1인 이유
    // 첫 BFS 레벨은 초기 rotten 상태(0분)이므로 depth++ 이후 0이 되도록 -1에서 시작
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};
    int freshOrange = 0;
    queue<pair<int, int>> newRotten;

    int orangesRotting(vector<vector<int>>& grid) {
        //1. 선언
        m = grid.size();
        n = grid[0].size();

        //먼저 rotten인 오렌지들을 queue에다가 넣기
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 2){
                    newRotten.push({r, c});
                }
                else if(grid[r][c] == 1) freshOrange ++;
            }
        }

        if(freshOrange == 0) return 0;
        if(newRotten.empty()) return -1;

        //2. 탐색 후 섬이 있는지 파악
        //fresh orange의 개수를 이용하여 연산 섬이 있는지 여부를 파악

        //3. bfs로 rotten을 시키며 depth가 몇인지 파악하기
        while(!newRotten.empty()){
            depth++; //현재 bfs의 레벨의 시간
            int qSize = newRotten.size(); // 같은 시간대에 처리할 rotten 개수
            for(int j = 0; j < qSize; j ++){
                for(int i=0; i<4; i++){ //4방면으로 탐색 및 rotten화 시키기
                    int nr = newRotten.front().first + dr[i]; //row
                    int nc = newRotten.front().second + dc[i]; //coloumn

                    //rotten화 시키기
                    //1. rotten으로 바꾸기 2. queue에 새로운 rottenOrange 삽입 3. freshOrange 개수-1
                    if(nr >=0 && nr <m && nc >=0 && nc <n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        newRotten.push({nr, nc}); 
                        freshOrange --;
                        }
                }
                newRotten.pop(); //4방면으로 다 rotten 시킨건 queue에서 제거
            }
        }

    //섬이 있다면 -1
    if(freshOrange != 0) return -1;

    //모두 성공적으로 rotten시키면 depth
    return depth;
    }
};