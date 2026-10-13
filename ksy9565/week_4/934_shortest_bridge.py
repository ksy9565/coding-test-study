from collections import deque

class Solution:
    def shortestBridge(self, grid: list[list[int]]) -> int:
        n = len(grid)
        dx = (1,0,-1,0)
        dy = (0,1,0,-1)

        visited = set()
        q = deque()

        # 두 섬을 구분하기 위해 섬을 2로 바꾸는 dfs 함수(bfs도 상관없음)
        # 동시에 q에 섬 전체를 삽입함. -> 다중 시작점 bfs를 실행하기 위해
        def dfs(x, y):

            dfsq = deque()

            grid[x][y] = 2

            visited.add((x,y))
            q.append((x,y,0))

            dfsq.append((x,y)) 

            while dfsq:
                x, y = dfsq.pop()
                for d in range(4):
                    nx, ny = x+dx[d], y+dy[d]
                    if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                        grid[nx][ny] = 2
                        q.append((nx,ny,0))
                        visited.add((nx,ny))
                        dfsq.append((nx,ny))
        
        # 첫 섬을 2로 바꾸고 나면 for문에서 빠져나옴
        t = False
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i,j)
                    t = True
                    break
            if t:
                break
        
        # bfs: 섬으로부터 최단거리로 멀어져있는 만큼이 depth에 저장됨
        while q:
            x, y, depth = q.popleft()
            for d in range(4):
                nx, ny = x+dx[d], y+dy[d]
                if 0 <= nx < n and 0 <= ny < n and (nx,ny) not in visited:
                    if grid[nx][ny] == 0:
                        visited.add((nx,ny))
                        q.append((nx,ny,depth+1))
                    
                    if grid[nx][ny] == 1:
                        return depth # 거쳐간 0의 최소 개수가 답이므로 +1 하지 않고 그냥 return
