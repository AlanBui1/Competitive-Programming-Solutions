def solve():
    n = int(input())

    l = int(1e9)
    r = -l
    u = l
    d = r
    
    for i in range(n):
        x, y= map(int, input().split())

        l = min(l, x)
        r = max(r, x)
        u = min(u, y)
        d = max(d, y)

    print(2*(d-u+r-l))
solve()