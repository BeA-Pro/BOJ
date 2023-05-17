from sys import stdin as s
from typing import Sequence, MutableSequence

if __name__ == "__main__":
    #s = open('input.txt', 'rt')
    n = int(s.readline())
    arr = list(map(int,s.readline().split()))
    memo = [0 for __ in range(n)]
    ans = []
    ans.append(arr[0])
    memo[0] = 0
    
    for i in range(1,len(arr)):
        num = arr[i]
        if num>ans[len(ans)-1]:
            ans.append(num)
            memo[i] = len(ans)-1
        else:
            left,right=0, len(ans)-1

            tmp_mid = -1
            while left<=right:
                mid = (left+right)//2
                if ans[mid] < num:
                    left = mid + 1
                else:
                    tmp_mid = mid
                    right = mid - 1
            ans[tmp_mid] = num
            memo[i]=tmp_mid
    print(len(ans))
    cnt = len(ans)-1
    li = []
    for i in range(len(arr)-1,-1,-1):
        if memo[i] == cnt:
            li.append(arr[i])
            cnt-=1
    
    for i in range(len(li)-1,-1,-1):
        print(li[i],end=" ")
    # for i in range(len(arr)):
    #     if stack : stack.append([arr[i],memo[i]])
    #     else :
    #         while stack and stack[-1][0]==memo
    # print(sum(ans))
