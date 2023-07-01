import sys 
input = sys.stdin.readline

n, k = map(int, input().split())
lis = [int(i) for i in input().split()]

found = True
cur = 0
days = 0

while found and cur != n-1:
    found = False
    nxt = min(n-1, cur+k)

    for i in range(nxt, cur, -1):
        if lis[i]:
            cur = i
            found = True
            break

    days += 1

if not found:
    print(-1)
else:
    print(days)