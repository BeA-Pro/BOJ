import sys
from typing import Sequence, MutableSequence
from queue import Queue
from collections import deque
from heapq import heappush, heappop


def move():
    for shark in range(1, M+1):
        dir, y, x = shark_state[shark]
        # print(shark_state[shark])
        if dir:
            # print(dir)
            flag = False
            for j in range(4):
                nxt_dir = shark_dir[shark][dir][j]
                ny = dy[nxt_dir] + y
                nx = dx[nxt_dir] + x
                if 0 <= ny < N and 0 <= nx < N and not pos_info[ny][nx][0]:
                    shark_state[shark] = [nxt_dir, ny, nx]
                    flag = True
                    break

            if not flag:
                for j in range(4):

                    nxt_dir = shark_dir[shark][dir][j]
                    ny = dy[nxt_dir] + y
                    nx = dx[nxt_dir] + x
                    if 0 <= ny < N and 0 <= nx < N and pos_info[ny][nx][0] == shark:
                        shark_state[shark] = [nxt_dir, ny, nx]
                        flag = True
                        break


# 위 1, 아래 2, 왼쪽 3, 오른쪽 4
if __name__ == "__main__":
    #sys.stdin = open('input.txt', 'rt')
    dy = [0, -1, 1, 0, 0]
    dx = [0, 0, 0, -1, 1]
    N, M, K = map(int, sys.stdin.readline().split())

    map_info = []
    shark_state = [[] for i in range(M+1)]
    shark_num = M
    for i in range(N):
        map_info.append(list(map(int, sys.stdin.readline().split())))

    temp_direct = list(map(int, sys.stdin.readline().split()))

    for i in range(N):
        for j in range(N):
            if map_info[i][j] != 0:
                shark_state[map_info[i][j]] = [
                    temp_direct[map_info[i][j]-1], i, j]

    # 앞에 상어, 뒤에 냄새
    pos_info = [[[0, 0] for _ in range(N)] for _ in range(N)]
    for i in range(1, M+1):
        dir, y, x = shark_state[i]
        pos_info[y][x] = [i, K]

    # 상어 방향 저장
    shark_dir = [[[]for _ in range(5)] for _ in range(M+1)]

    for i in range(1, M+1):
        for j in range(1, 5):
            shark_dir[i][j] = list(map(int, sys.stdin.readline().split()))
    cnt = 0
    while cnt <= 1000:
        move()

        for shark in range(1, M+1):
            dir, y, x = shark_state[shark]
            if not dir:
                continue
            if pos_info[y][x][0] == shark or not pos_info[y][x][0]:
                pos_info[y][x] = [shark, K+1]
            else:
                if shark_state[shark][0] != 0:
                    shark_state[shark][0] = 0
                    shark_num -= 1

        for i in range(N):
            for j in range(N):
                if pos_info[i][j][0]:
                    pos_info[i][j][1] -= 1

                if not pos_info[i][j][1]:
                    pos_info[i][j][0] = 0

        # for i in range(N):
        #     for j in range(N):
        #         if pos_info[i][j][1] == K:
        #             print(pos_info[i][j][0], end=" ")
        #         else:
        #             print(0, end=" ")
        #     print()
        # print(shark_state)
        # print("shark_num", shark_num)
        # print()
        # print(shark_state)
        # for i in range(N):
        #     for j in range(N):
        #         print(pos_info[i][j], end=" ")
        #     print()
        # print()
        cnt += 1
        if shark_num == 1:
            break

    if cnt <= 1000:
        print(cnt)
    else:
        print(-1)
