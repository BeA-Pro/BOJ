import sys
from collections import deque

def bfs() -> int :
  dq = deque()
  dq.append(1)
  check[1] = True
  cnt = 0
  
  while len(dq) != 0 :
    cur = dq.popleft()
    
    for nxt in graph[cur]:
      if not check[nxt] :
        check[nxt] = True
        dq.append(nxt)
        cnt+=1
  
  return cnt
  

if __name__ == "__main__" :
  #sys.stdin = open('input.txt','r')
  n = int(sys.stdin.readline())
  m = int(sys.stdin.readline())
  graph = [[] for i in range(n + 1)]
  check = [False for i in range(n + 1)]
  
  for i in range(m) :
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)
    
  print(bfs())