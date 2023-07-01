import sys
input = sys.stdin.readline
def solve():
    n, k = map(int, input().split())
    lis = [int(input()) for i in range(n)]
        
    lis.sort()

    ans = 0
    used = 0
    for i in range(n-1, -1, -1):
        if lis[i] < 0 or used >= k:
            break
        ans += lis[i]
        used += 1
    print(ans)


solve()