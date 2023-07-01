import sys
input =sys.stdin.readline

def solve():
    n = int(input())
    lis = [int(input()) for i in range(n)]

    dp = [0 for i in range(1441)]
    dp[0] = 1

    for thing in lis:
        for i in range(1440, -1, -1):
            if i - thing < 0:
                break
            if dp[i-thing]:
                dp[i] = 1

    x = 0
    for i in range(1441):
        if dp[i]:
            x = max(x, i)

    print(1440-x)
for i in range(5):
    solve()