import sys
input = sys.stdin.readline
INF = int(9e18)

n = int(input())
lis = [[int(i) for i in input().split()] for k in range(n)]
lis.append([INF, INF, 0])

lis.sort()

dp = [0 for i in range(n+1)]

def nxt(v):
    lo = 0
    hi = n
    ret = n
    
    while lo <= hi:
        mid = (lo+hi)//2
        
        if lis[mid][0] >= v:
            ret = mid
            hi = mid-1
        else:
            lo = mid+1
            
    return ret

for i in range(n-1,-1,-1):
    WO = dp[i+1]
    W = lis[i][2] + dp[nxt(lis[i][0] + lis[i][1])]
    dp[i] = max(W, WO)
    
print(dp[0])