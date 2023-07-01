n, m = map(int, input().split())

lis = []

for _ in range(m):
    p, q=  map(int, input().split())
    name = input()
    lis.append([p, q, name])

y = int(input())

for p, q, name in lis:
    if q == y:
        print(name)