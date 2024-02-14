import sys
from collections import deque
from queue import PriorityQueue

def bfs() -> int :
  que = deque()
  que.append([0,cur_y,cur_x,False])
  check1[cur_y][cur_x] = True
  
  while len(que) :
    cnt, y,x,rest = que.popleft()
    food = graph[y][x]
    # print(y,x)
    if y == to_y and x == to_x :
      return cnt
    
    # 안 쉬는 경우
    for i in range(4):
      ny = y + dy[i] * food
      nx = x + dx[i] * food
      
      if 0 <= ny < n and 0 <= nx < m :
        if rest and not check2[ny][nx] :
          check2[ny][nx] = True
          que.append([cnt + 1, ny, nx, rest])
        elif not rest and not check1[ny][nx] :
          check1[ny][nx] = True
          que.append([cnt + 1, ny, nx, rest])

    # 쉬는 경우
    if not rest :
      temp_y = 0
      temp_x = 0
      if not check_col[x]:
        check_col[x] = True
        while temp_y < n:
          if temp_y == y or temp_y == y + food or temp_y == y - food:
            temp_y+=1
            continue
          if not check2[temp_y][x]:
            check2[temp_y][x] = True
            que.append([cnt + 1, temp_y, x, True])
          temp_y+=1
          
      if not check_row[y]:
        check_row[y] = True
        while temp_x < m:
          if temp_x == x or temp_x == x + food or temp_x == x - food:
            temp_x+=1
            continue
          if not check2[y][temp_x]:
            check2[y][temp_x] = True
            que.append([cnt+1, y, temp_x, True])
          temp_x+=1
    
    
  return -1


if __name__ == "__main__":
  # sys.stdin = open('input.txt','r')
  n,m = map(int,sys.stdin.readline().split())
  graph = []
  check1 = [[False for i in range(m)] for i in range(n)]
  check2 = [[False for i in range(m)] for i in range(n)]
  check_row = [False for i in range(n)]
  check_col = [False for i in range(m)]
  dy = [-1,1,0,0]
  dx = [0,0,-1,1]
  
  cur_y, cur_x, to_y, to_x = map(int,sys.stdin.readline().split())
  
  cur_y -= 1
  cur_x -= 1
  to_y -= 1
  to_x -= 1
  
  for i in range(n):
    graph.append(list(map(int,sys.stdin.readline().split())))
  
  print(bfs())
