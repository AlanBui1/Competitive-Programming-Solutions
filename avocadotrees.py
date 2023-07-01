import sys
input = sys.stdin.readline
n, q, h = map(int, input().split())

lis = []
for i in range(n):
    a, b = map(int, input().split())
    lis.append((a, b))
    
prefix = [0 for i in range(n+1)]
for i in range(0, n):
    height = lis[i][0]
    profit = lis[i][1]
    prefix[i+1] = prefix[i]
    if height <= h:
        prefix[i+1] += profit

ans =-1
for i in range(q):
    l, r = map(int, input().split())
    ans = max(ans, prefix[r] - prefix[l-1])
    
print(ans)