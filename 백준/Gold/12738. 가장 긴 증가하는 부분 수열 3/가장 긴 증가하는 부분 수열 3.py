import sys
from typing import Sequence, MutableSequence
from queue import Queue
from collections import deque
from heapq import heappush, heappop

if __name__ == "__main__":
    # sys.stdin = open('input.txt', 'rt')
    N = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))

    long_arr = [arr[0]]
    ans = 1

    for i in range(1, N):
        if arr[i] > long_arr[len(long_arr)-1]:
            long_arr.append(arr[i])
        else:
            left = 0
            right = len(long_arr)-1
            mid = (left+right)//2
            upper_bound = 0
            while left < right:
                mid = (left+right)//2
                if long_arr[mid] < arr[i]:
                    left = mid + 1
                else:
                    right = mid
            long_arr[right] = arr[i]
    # print(long_arr)
    print(len(long_arr))
