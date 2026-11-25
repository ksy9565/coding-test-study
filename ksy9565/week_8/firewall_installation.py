# 제한 조건: n, m이 상당히 작은 문제
# 방화벽을 효율적으로 놓는 법을 찾는 것이 아니라
# 방화벽을 놓는 모든 경우의 수를 완전탐색하면 됨
from collections import deque

n, m = map(int, input().split())
origin = [list(map(int, input().split())) for _ in range(n)] # 원본 영역

fire = [] # 불 있는 곳
nofire = [] # 비어있는 곳
for i in range(n):
    for j in range(m):
        if origin[i][j] == 2:
            fire.append((i,j))
        if origin[i][j] == 0:
            nofire.append((i,j))

dx = (1,0,-1,0)
dy = (0,1,0,-1)

# 불이 번진 후 안전한 공간을 세는 함수
def count_safe(maps, wall):
    for i, j in wall:
        maps[i][j] = 1

    q = deque(fire[:])
    
    while q:
        x, y = q.popleft()
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 0:
                maps[nx][ny] = 2
                q.append((nx,ny))

    count = sum(row.count(0) for row in maps)
    return count

safe = 0 # count 중 가장 큰 값을 저장
l = len(nofire)
for i in range(l-2):
    for j in range(i+1, l-1):
        for k in range(j+1, l): # 방화벽 놓는 세 곳(i,j,k)을 완전탐색
            # [row[:] for row in origin]: 깊은 복사를 통해 원본 영역 변경하지 않고 여러 번 계산
            safe = max(safe, count_safe([row[:] for row in origin], [nofire[i],nofire[j],nofire[k]]))

print(safe)
