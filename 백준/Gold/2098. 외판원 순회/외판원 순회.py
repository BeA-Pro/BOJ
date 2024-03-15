import sys
from typing import Sequence, MutableSequence
from queue import Queue
from collections import deque
from heapq import heappush, heappop

dp = []
arr = []
end,n = None,None
INF = 10**9

def dfs(cur,road):
    if road == end:
        if arr[cur][0] : return arr[cur][0]
        return INF
    
    if dp[cur][road] : return dp[cur][road]

    
    dp[cur][road] = INF
    
    for i in range(1,n):
        if not road & (1<<i) and arr[cur][i] : dp[cur][road] = min(dp[cur][road],dfs(i,road | (1<<i)) + arr[cur][i])

    return dp[cur][road]

if __name__ == "__main__":
    #sys.stdin = open('input.txt', 'rt')
    n = int(sys.stdin.readline())
    end = (1<<n) - 1
    dp = [[0]*(1<<n) for __ in range(n)]
    arr = [[] for __ in range(n)]
    for i in range(n) : arr[i] = list(map(int,sys.stdin.readline().split()))

    print(dfs(0,1))