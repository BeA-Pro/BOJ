import sys
from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
p = [[-1, 1, -1, 3, -1, 0], [-1, -1, 0, 2, 1, -1],
     [1, -1, 3, -1, -1, 2], [0, 2, -1, -1, 3, -1]]


def bfs(road, N):
    if p[0][road[0][0]] < 0:
        return int(1e9)

    result = int(1e9)
    q = deque()
    q.append((p[0][road[0][0]], 0, 0, 1))
    visited = [[False for _ in range(N)] for _ in range(N)]
    visited[0][0] = True

    while q:
        d, x, y, l = q.popleft()
        if x == N-1 and y == N-1 and d == 0:
            result = min(result, l)
            continue
        nx, ny = x+dx[d], y+dy[d]
        if nx >= N or ny >= N or nx < 0 or ny < 0:
            continue

        nd = p[d][road[ny][nx]]
        if nd >= 0:
            if visited[ny][nx] == False:
                visited[ny][nx] = True
                q.append((nd, nx, ny, l+1))
    return result


input = sys.stdin.readline
N, K = map(int, input().split())
road = []
for _ in range(N):
    road.append(list(map(int, input().split())))
result = int(1e9)
visited = [[False for _ in range(N)] for _ in range(N)]

if K == 0:
    result = bfs(road, N)
else:
    for i in range(N):
        for j in range(N):
            for t in range(6):
                if road[i][j] != t:
                    o = road[i][j]
                    road[i][j] = t
                    result = min(result, bfs(road, N))
                    road[i][j] = o

if result == int(1e9):
    print(-1)
else:
    print(result)
