import sys
input = sys.stdin.readline

n, q = map(int, input().split())

lis = [{} for i in range(n+1)]

for i in range(q):
    op, ind, name = input().split()
    ind = int(ind)
    if op == "1":
        if name in lis[ind]:
            print(1)
        else:
            print(0)
    else:
        lis[ind][name] = 1