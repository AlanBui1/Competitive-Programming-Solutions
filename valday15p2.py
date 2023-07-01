import sys
input = sys.stdin.readline

c, m = map(int, input().split())
val = []
wt = []
dp = [0 for i in range(m+1)]
for i in range(c):
  n, k = map(int, input().split())
  wt.append(k)
  val.append(n)

for i in range(len(val)):
  for j in range(m, 0, -1):
    maxWO = dp[j]
    maxW = 0
    curWeight = wt[i]
    if j >= curWeight:
      maxW = val[i]
      remWeight = j - curWeight
      maxW += dp[remWeight]
    dp[j] = max(maxW, maxWO)

print(dp[m])