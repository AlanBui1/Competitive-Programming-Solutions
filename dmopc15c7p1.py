import sys
input =sys.stdin.readline

n = int(input())

cfactor = [int(i) for i in input().split()]
lis = []

start = -1

for _ in range(n):
    i, p, s, t = map(int, input().split())
    lis.append([i, p, s, t])

    start = max(start, s)

for i, p, s, t in lis:
    if p == 10:
        print(0)
    elif start + (t*cfactor[i-1]) <= 180:
        print(10-p)
    else:
        print("The kemonomimi are too cute!")