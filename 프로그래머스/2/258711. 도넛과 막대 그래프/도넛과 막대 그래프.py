from collections import deque

def bfs(cur,graph, in_degree, out_degree, visit):
    
    dq = deque()
    dq.append(cur)
    flag = False
    a = 0
    
    while len(dq):
        a = dq.popleft()
        if in_degree[a] == 2 and out_degree[a] == 2:
            flag = True
            
        if a == cur and visit[a]:
            return a, flag
            
        for nxt in graph[a] :
            if not visit[nxt]:
                visit[nxt] = True
                dq.append(nxt)
        
    
    return a, flag

def solution(edges):
    answer = [0 for i in range(4)]
    in_degree = [0 for i in range(1000001)]
    out_degree = [0 for i in range(1000001)]
    graph = [[] for i in range(1000001)]
    visit = [False for i in range(1000001)]
    
    for edge in edges :
        a, b = edge
        out_degree[a] += 1
        in_degree[b] += 1
        graph[a].append(b)
        
    start = 0
    
    for i in range(1000001) :
        if in_degree[i] == 0 and out_degree[i] > 1 :
            start = i
            
    answer[0] = start
    visit[start] = True
    
    for next in graph[start] :
        in_degree[next] -= 1
        ro, flag = bfs(next, graph,in_degree, out_degree, visit)
        # print(next, ro ,flag)
        
        # 1 : 도넛, 2 : 막대, 3 : 8자
        if ro != next :
            answer[2]+=1
        else :
            if out_degree[ro] == 0 :
                answer[2] += 1
            elif flag :
                answer[3] += 1
            else :
                answer[1] += 1
    
    
    
    return answer