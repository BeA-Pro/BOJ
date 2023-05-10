import sys
from typing import Sequence, MutableSequence
from queue import Queue
from collections import deque
from heapq import heappush, heappop

dy,dx = [-1,1,0,0], [0,0,1,-1]


if __name__ == "__main__":
    #sys.stdin = open('input.txt', 'rt')
    t = int(sys.stdin.readline())
    
    for z in range(t):
        m,n,k = map(int,sys.stdin.readline().split())
        arr = [[0 for __ in range(m)] for __ in range(n)]
        check = [[False for __ in range(m)] for __ in range(n)]
        for i in range(k) :
            x,y = map(int,sys.stdin.readline().split())
            arr[y][x] = 1
        
        cnt = 0
        for i in range(n):
            for j in range(m):
                if arr[i][j] and not check[i][j] :
                    check[i][j] = True
                    cnt+=1
                    q = deque()
                    q.append([i,j])
                    
                    while q:
                        y,x = q.popleft()
                        for k in range(4):
                            ny,nx = y+dy[k], x+dx[k]
                            if 0<=ny<n and 0<=nx<m and arr[ny][nx] and not check[ny][nx]:
                                check[ny][nx] = True
                                q.append([ny,nx])
        print(cnt)
