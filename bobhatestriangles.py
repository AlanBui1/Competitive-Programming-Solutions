n, m = map(int, input().split())
for i in range(m):
    a, b = map(int, input().split())
    print(min(a, b), max(a, b))