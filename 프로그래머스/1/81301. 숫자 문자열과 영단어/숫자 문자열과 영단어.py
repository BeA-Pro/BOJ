def solution(s):
    answer = 0
    st_number = ["zero","one","two","three","four","five","six","seven","eight","nine"]
    
    temp = ''
    for i in s :
        # print(answer)
        # print(temp)
        # print(i,ord(i), ord('0'), ord(i) - ord('0'))
        if 0 <= ord(i) - ord('0') <= 9:
            answer= answer * 10 + (ord(i) - ord('0') )
            continue
        
        temp += i
        for j in range(10):
            if st_number[j] == temp:
                answer = answer * 10 + j
                temp = ''
                
        
            
            
    return answer