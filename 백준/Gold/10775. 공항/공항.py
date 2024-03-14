import sys
from typing import Sequence, MutableSequence
from queue import Queue
from collections import deque
from heapq import heappush, heappop


def find_parent(cur):
    if cur == parent[cur]:
        return cur
    par = find_parent(parent[cur])
    parent[cur] = par
    return par


if __name__ == "__main__":
    #sys.stdin = open('input.txt', 'rt')
    sys.setrecursionlimit(10**6)
    G = int(sys.stdin.readline())
    P = int(sys.stdin.readline())
    parent = [i for i in range(G+1)]
    ans = 0

    for i in range(P):
        cur = int(sys.stdin.readline())
        # print(i)
        cur_p = find_parent(cur)
        if cur_p == 0:
            break
        else:
            ans += 1
            parent[cur_p] = parent[find_parent(cur_p-1)]
    # print(parent)
    print(ans)
