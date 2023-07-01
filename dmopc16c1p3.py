import sys; input = sys.stdin.readline

n = int(input())
lis= [int(i) for i in input().split()]
dp = [0 for i in range(n)]

if n == 1:
    print("%.1f" %(float(lis[0])))

elif n == 2:
    print("%.1f" %(float(lis[0]+lis[1] - (0.5*min(lis[0], lis[1])))))

else:

    dp[0] = lis[0]
    dp[1] = lis[0]+lis[1] - (0.5*min(lis[0], lis[1]))
    dp[2] = min(lis[2]+dp[1],  lis[2]+lis[1]-(0.5*min(lis[1], lis[2]))+dp[0], lis[2]+lis[1]+lis[0]-min(lis[0], lis[1], lis[2]))

    if n == 3:
        print("%.1f" %(float(dp[2])))

    else:

        for i in range(3, n):
            dp[i] = min(lis[i]+dp[i-1], lis[i]+lis[i-1]-(0.5*min(lis[i], lis[i-1]))+dp[i-2], lis[i]+lis[i-1]+lis[i-2]-min(lis[i], lis[i-1], lis[i-2])+dp[i-3])

        print("%.1f" %(float(dp[n-1])))