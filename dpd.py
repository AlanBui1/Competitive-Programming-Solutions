import sys
input = sys.stdin.readline
n, w = map(int, input().split())
val = []
wt = []
dp = [0 for i in range(w+1)]
for i in range(n):
  weight, value = map(int, input().split())
  wt.append(weight)
  val.append(value)

for i in range(n):
  for j in range(w, 0, -1):
    maxWO = dp[j]
    maxW = 0
    curWeight = wt[i]
    if j >= curWeight:
      maxW = val[i]
      remWeight = j - curWeight
      maxW += dp[remWeight]
    dp[j] = max(maxW, maxWO)

print(dp[w])