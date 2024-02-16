def solution(friends, gifts):
    answer = 0
    change = {}
    
    for i in range(len(friends)) :
        change[friends[i]] = i
    
    rel = [[0 for i in range(len(friends))] for j in range(len(friends))]
    n = len(friends)
    
    get_cnt = [0 for i in range(n)]
    give_cnt = [0 for i in range(n)]
    final = [0 for i in range(n)]
    
    
    for i in gifts:
        a, b = i.split()
        rel[change[a]][change[b]]+=1
        give_cnt[change[a]] += 1
        get_cnt[change[b]] += 1
    
    for i in range(n):
        for j in range(i + 1,n):
            if rel[i][j] > rel[j][i] :
                final[i] +=1
            elif rel[i][j] < rel[j][i] :
                final[j] +=1
            else :
                i_rate = give_cnt[i] - get_cnt[i]
                j_rate = give_cnt[j] - get_cnt[j]
                if i_rate > j_rate:
                    final[i] += 1
                elif i_rate < j_rate:
                    final[j] += 1
            
    answer = max(final)
            
    
        
            
        
    return answer