import sys
import math
input = sys.stdin.readline
lis = [(0,0)]
tot = 0
n, w = map(int, input().split())
for i in range(n):
  wt, val = map(int, input().split())
  lis.append((wt, val))
  tot+=val

arr =[math.inf for i in range(tot+1)]
arr[0] = 0

for k in range(1, n+1):
  for i in range(tot, 0, -1):
    arr[i] = min(arr[i], arr[i-lis[k][1]]+lis[k][0])


for i in range(tot, -1, -1):
  if arr[i] <= w:
    print(i)
    break