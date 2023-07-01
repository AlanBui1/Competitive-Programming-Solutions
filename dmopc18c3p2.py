import sys; input = sys.stdin.readline

n = int(input())

F = [int(i) for i in input().split()]
E = [int(i) for i in input().split()]

if n == 1:
    print(max(F[0], E[0]))
else:
    dp = [[0 for i in range(3)] for k in range(n+1)]

    for i in range(1, n+1):
        for k in range(3):
            if k == 0:
                if i == 2:
                    dp[i][k] = max(dp[i-1][k], dp[i-1][k+1]) + E[i-1]

                else:
                    dp[i][k] = max(dp[i-1][k], dp[i-1][k+1], dp[i-1][k+2]) + E[i-1]
                
            elif k == 1:
                dp[i][k] = dp[i-1][k-1] + F[i-1]

            elif i != 1:
                dp[i][k] = dp[i-1][k-1] + F[i-1]

    print(max(dp[n][0], dp[n][1], dp[n][2]))