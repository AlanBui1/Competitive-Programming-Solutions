def solve():
    a, b, c, d = map(int, input().split())
    if (d-c) * (b-a) > a*c:
        print("YES")
    else:
        print("NO")


t = int(input())
for _ in range(t):
    solve()