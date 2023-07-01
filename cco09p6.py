import math
import sys
input = sys.stdin.readline
c, d, k = map(int, input().split())
coins = []

for i in range(d):
  val, weight = map(float, input().split())
  coins.append((int(val), weight))

has = []
tot = 0
ctot = 0

for i in range(k):
  n = int(input())
  has.append(coins[n-1])
  tot+=coins[n-1][0]
  ctot+=coins[n-1][1]

tot = int(tot)
if tot < c:
  print("too poor")

else:
  arr = [-math.inf for i in range(int(tot+1))]
  arr[0] = 0
  for cost,val in has:
    for i in range(int(tot), -1, -1):

      if cost > i:
        break

      if arr[i-int(cost)] != -1:
        arr[i] = max(arr[i], arr[int(i-cost)]+val)

  back = [i-c for i in range(tot+1)]
  coins.sort(reverse=True)
  for i in range(tot+1):
    x=0
    if i < c:
      continue
    while back[i] > 0:
      denom = coins[x][0]
      weight = coins[x][1]
      if denom <= back[i]:
        back[i] -= denom
        arr[i] -= weight

      else:
        x+=1
        
  ans = math.inf
  for i in range(c,tot+1):
    if i == -math.inf:
      continue
    ans = min(ans, ctot-arr[i])
  print("%.2f"%ans)