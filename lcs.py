n, m = map(int, input().split())

lis1 = [int(i) for i in input().split()]
lis2 = [int(i) for i in input().split()]

dp = [[0 for i in range(1005)] for k in range(1005)]

for i in range(1,n+1):
    for k in range(1, m+1):
        dp[i][k] = max(dp[i-1][k], dp[i][k-1])
        
        if lis1[i-1] == lis2[k-1]:
            dp[i][k] = dp[i-1][k-1]+1
            
print(dp[n][m])