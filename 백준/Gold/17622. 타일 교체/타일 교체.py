import sys
from typing import Sequence, MutableSequence
from queue import Queue
from collections import deque
from heapq import heappush, heappop


def bfs():
    dq = deque()
    visit = [[False for i in range(N+2)] for _ in range(N+2)]
    dq.append([1, 0, 0])
    visit[1][0] = True

    while len(dq) != 0:
        y, x, dist = dq.popleft()
        dir = map_info[y][x]
        if y == N and x == N + 1:
            return dist-1
        for y1, x1 in dir_info[dir]:
            ny = y1 + y
            nx = x1 + x
            # print(ny, nx)
            if 0 <= ny <= N and 0 <= nx <= N+1 and map_info[ny][nx] != -1 and not visit[ny][nx]:
                for y2, x2 in dir_info[map_info[ny][nx]]:
                    nny = y2 + ny
                    nnx = x2 + nx
                    # print(nny, nnx)
                    if nnx == x and nny == y:
                        # print(ny, nx)
                        visit[ny][nx] = True
                        dq.append([ny, nx, dist+1])

    return -1


if __name__ == "__main__":
    # sys.stdin = open('input.txt', 'rt')
    N, K = map(int, sys.stdin.readline().split())
    map_info = [[-1 for i in range(N+2)]]
    for i in range(N):
        temp = [-1]
        temp.extend(list(map(int, sys.stdin.readline().split())))
        temp.append(-1)
        map_info.append(temp)

    map_info[1][0] = 5
    map_info[N][N+1] = 5

    # for i in range(N+1):
    #     print(map_info[i])

    dir_info = [
        [[0, 1], [1, 0]],
        [[0, -1], [1, 0]],
        [[0, 1], [-1, 0]],
        [[0, -1], [-1, 0]],
        [[-1, 0], [1, 0]],
        [[0, -1], [0, 1]]
    ]

    if K == 0:
        print(bfs())
    else:
        ans = N*N + 1
        for i in range(1, N+1):
            for j in range(1, N+1):
                for k in range(6):
                    # print(k, map_info[i][j])
                    if k == map_info[i][j]:
                        continue
                    temp = map_info[i][j]
                    map_info[i][j] = k
                    cnt = bfs()

                    if cnt != -1:
                        ans = min(ans, cnt)
                    map_info[i][j] = temp

        if ans == N*N + 1:
            print(-1)
        else:
            print(ans)
