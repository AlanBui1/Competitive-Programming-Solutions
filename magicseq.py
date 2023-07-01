n = int(input())

dp = [0 for i in range(n+1)]
dp[0] = 1

for i in range(1, n+1):
    if i%2 == 0:
        for k in range(1, i, 2):
            dp[i] += dp[k]

    else:
        for k in range(0, i, 2):
            dp[i] += dp[k]

print(sum(dp)-1)