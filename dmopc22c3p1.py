n, m = map(int, input().split())

if n == 1:
    print(m//2 + m%2, m//2)

else:
    n, m = max(n, m), min(n, m)
    if n%2 == 0 or m%2 == 0:
        print(n*m//2, n*m//2)
    else:
        mid = [n//2 + n%2, m//2 + m%2]
        # print(mid)

        RED = min(mid[0] * m, mid[1]*n)
        GREEN = n*m - RED
        print(max(RED, GREEN), min(RED, GREEN))