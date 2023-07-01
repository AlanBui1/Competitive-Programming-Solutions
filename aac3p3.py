import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]
    a.sort()

    l = []
    p1 = 0
    p2 = n-1
    cnt = 0

    while p1 < p2:
        cnt += 1
        if (cnt&1):
            l.append(a[p1])
            p1 += 1

        else:
            l.append(a[p2])
            p2 -= 1

    if len(l) < n:
        l.append(a[p1])

    print(*l)

    for i in range(n-1):
        if i&1:
            print("S", end = "")
        else:
            print("B", end = "")

    if n%2 == 0:
        print("S")
    else:
        print("E")

q = 1
for i in range(q):
    solve()