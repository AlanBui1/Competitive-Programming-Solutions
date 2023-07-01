n = int(input())

dp = [[0 for i in range(n*2)] for k in range(n*2)]
num = int(input())

dp[0][n] = num

for i in range(1, n):
    lis= [int(k) for k in input().split()]

    dp[i][n -i] = lis[0] + dp[i-1][n -i+1]
    dp[i][n +i] = lis[-1] + dp[i-1][n +i-1]

    cnt= 0
    for k in range(-i+2, i-2+1, 2):
        cnt += 1
        dp[i][n+k] = lis[cnt]
        dp[i][n+k] += max(dp[i-1][n+k-1], dp[i-1][n+k+1])

print(max(dp[n-1]))