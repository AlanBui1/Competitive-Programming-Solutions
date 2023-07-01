n = int(input())

dp = [0 for i in range(n+1)]
dp[0] = 1

for i in range(4, n+1):
    if dp[i-4]:
        dp[i] += dp[i-4]

for i in range(5, n+1):
    if dp[i-5]:
        dp[i]+=dp[i-5]

print(dp[-1])