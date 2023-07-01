import math
import sys
input = sys.stdin.readline
minutelimit, foodlimit, n = map(int, input().split())
lis =[]
for i in range(n):
  profit, minute, food = map(int, input().split())
  lis.append((profit, minute, food))

arr = [[0 for i in range(minutelimit+1)] for k in range(foodlimit+1)]
ans = 0

for profit, minute, food in lis:
  for i in range(foodlimit, -1, -1):
    for k in range(minutelimit, -1, -1):
      if i>=food and k>=minute:
        arr[i][k] = max(arr[i][k], arr[i-food][k-minute]+profit)
        ans = max(ans, arr[i][k])
print(ans)