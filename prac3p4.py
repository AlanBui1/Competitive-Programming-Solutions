import sys
input = sys.stdin.readline

while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break

    lis = [int(input()) for i in range(n)]
    dp = [0] + [-1 for i in range(m)]

    for bucket in lis:
        for i in range(m+1):
            if i-bucket >= 0:
                if (dp[i-bucket] >= 0):
                    if dp[i] == -1:
                        dp[i] = dp[i-bucket] + 1
                    else:
                        dp[i] = min(dp[i], dp[i-bucket] + 1)


    print(dp[-1])