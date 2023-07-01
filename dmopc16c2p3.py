import sys
input = sys.stdin.readline
def solve():
    n, m = map(int, input().split())
    a = 0
    b = 0

    for i in range(m):
        x, y = map(int, input().split())
        a = max(a, x)
        b = max(b, y)

    if a+b > n:
        print(-1)
        return

    print(("a"*a)+("b"*b)+("a"*(n-b-a)))
        

t = int(input())
for _ in range(t):
    solve()