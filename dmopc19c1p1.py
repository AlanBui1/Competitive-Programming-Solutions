import sys
input = sys.stdin.readline
def solve():
    n, a, b, t= map(int, input().split())

    lo = 0
    hi = n
    ans = int(1e9)+7
    while lo <= hi:
        mid = (lo+hi)//2

        if (a*mid) - (b*(n-mid)) >= t:
            ans = min(ans, mid)
            hi = mid-1
        else:
            lo = mid+1

    
    if ans > n:
        print(-1)
    else:
        print(ans)

t = int(input())
for i in range(t):
    solve()