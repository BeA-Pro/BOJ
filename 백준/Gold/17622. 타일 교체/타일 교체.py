import sys
dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]
line = [[0, 0, 1, 1], [0, 1, 1, 0], [1, 0, 0, 1],
        [1, 1, 0, 0], [1, 0, 1, 0], [0, 1, 0, 1]]


def match(i):
    if i < 2:
        return i + 2
    return i - 2


def dfs(y, x):
    if y == N - 1 and x == N - 1:
        if board[y][x] == 2 or board[y][x] == 5:
            return 1
        return -1
    if y == 0 and x == 0:
        if board[y][x] % 2 == 0:
            return -1
    visit[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        m = match(i)
        if ny < 0 or nx < 0 or ny >= N or nx >= N or not line[board[y][x]][i] or not line[board[ny][nx]][m] or visit[ny][nx]:
            continue
        ret = dfs(ny, nx)
        if ret == -1:
            return -1
        return ret + 1
    return -1


# sys.stdin = open('input.txt', 'rt')
#     N, K = map(int, sys.stdin.readline().split())
N, k = map(int, sys.stdin.readline().split())
board = []
for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))
visit = [[0] * N for _ in range(N)]
ans = 9e8
if k:
    for i in range(N):
        for j in range(N):
            t = board[i][j]
            for k in range(6):
                if t != k:
                    board[i][j] = k
                    visit = [[0] * N for _ in range(N)]
                    ret = dfs(0, 0)
                    if ret != -1:
                        ans = min(ans, ret)
            board[i][j] = t
else:
    ans = dfs(0, 0)
print(ans if ans != 9e8 else -1)

# import sys
# from typing import Sequence, MutableSequence
# from queue import Queue
# from collections import deque
# from heapq import heappush, heappop


# def bfs():
#     dq = deque()
#     visit = [[False for i in range(N+2)] for _ in range(N+2)]
#     dq.append([1, 0, 0])
#     visit[1][0] = True

#     while len(dq) != 0:
#         y, x, dist = dq.popleft()
#         # print(y, x)
#         dir = map_info[y][x]
#         if y == N and x == N + 1:
#             return dist-1
#         # print(dir)
#         # print(dir_info[dir])
#         for y1, x1 in dir_info[dir]:
#             ny = y1 + y
#             nx = x1 + x
#             # print(ny, nx)
#             if 0 <= ny <= N and 0 <= nx <= N+1 and map_info[ny][nx] != -1 and not visit[ny][nx]:
#                 for y2, x2 in dir_info[map_info[ny][nx]]:
#                     nny = y2 + ny
#                     nnx = x2 + nx
#                     # print(nny, nnx)
#                     if nnx == x and nny == y:
#                         # print(ny, nx)
#                         visit[ny][nx] = True
#                         dq.append([ny, nx, dist+1])

#     return -1


# if __name__ == "__main__":
#     sys.stdin = open('input.txt', 'rt')
#     N, K = map(int, sys.stdin.readline().split())
#     map_info = [[-1 for i in range(N+2)]]
#     for i in range(N):
#         temp = [-1]
#         temp.extend(list(map(int, sys.stdin.readline().split())))
#         temp.append(-1)
#         map_info.append(temp)

#     map_info[1][0] = 5
#     map_info[N][N+1] = 5

#     # for i in range(N+1):
#     #     print(map_info[i])

#     dir_info = [
#         [[0, 1], [1, 0]],
#         [[0, -1], [1, 0]],
#         [[0, 1], [-1, 0]],
#         [[0, -1], [-1, 0]],
#         [[-1, 0], [1, 0]],
#         [[0, -1], [0, 1]]
#     ]

#     if K == 0:
#         print(bfs())
#     else:
#         ans = 10 ** 9
#         for i in range(1, N+1):
#             for j in range(1, N+1):
#                 temp = map_info[i][j]
#                 for k in range(6):
#                     # print(k, map_info[i][j])
#                     if k == map_info[i][j]:
#                         continue

#                     map_info[i][j] = k
#                     cnt = bfs()
#                     if cnt != -1:
#                         ans = min(ans, cnt)

#                 map_info[i][j] = temp

#         if ans == 10 ** 9:
#             print(-1)
#         else:
#             print(ans)
