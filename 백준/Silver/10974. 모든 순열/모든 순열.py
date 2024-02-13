import sys

def cal() :
  if len(arr) == n :
    for i in arr : print(i,end=" ")
    print()
    return
  
  for i in range(n):
    if not check[i] :
      check[i] = True
      arr.append(data[i])
      cal()
      check[i] = False
      arr.pop()
      

if __name__ == "__main__":
  #sys.stdin = open('input.txt','r')
  n = int(sys.stdin.readline())
  data = [i+1 for i in range(n)]
  
  check = [False for i in range(n)]
  arr = []
  
  cal()