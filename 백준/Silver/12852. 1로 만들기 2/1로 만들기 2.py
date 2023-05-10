import sys
from typing import Sequence, MutableSequence
from queue import Queue
from collections import deque
from heapq import heappush, heappop

dp = []

if __name__ == "__main__":
    #sys.stdin = open('input.txt', 'rt')
    n = int(sys.stdin.readline())

    dp = [[sys.maxsize, 0] for __ in range(n+1)]

    dp[n] = [0, 0]
    for i in range(n, 1, -1):
        if not i % 3 and dp[int(i//3)][0] > dp[i][0] + 1:
            dp[int(i//3)] = [dp[i][0]+1, i]
        if not i % 2 and dp[int(i//2)][0] > dp[i][0] + 1:
            dp[int(i//2)] = [dp[i][0]+1, i]
        if dp[i-1][0] > dp[i][0] + 1:
            dp[i-1] = [dp[i][0]+1, i]

    print(dp[1][0])
    ans = []
    idx = 1
    while idx != n:
        ans.append(idx)
        idx = dp[idx][1]
    ans.append(idx)

    for i in range(len(ans)-1, -1, -1):
        print(ans[i], end=" ")
