import sys
input = sys.stdin.readline

n, k, m = map(int, input().split())
ans = [0 for i in range(n)]

G = 2*n -2
numGroups = m//G//k
m -= numGroups*G*k

for i in range(n):
    ans[i] += 2*numGroups*k
ans[-1] //= 2
ans[0] //= 2

dir = 1
cur = 0
# if numGroups > 0:
#     cur = 1
for i in range(m//k):
    ans[cur] += k
    cur += dir
    if cur == n:
        cur = n-2
        dir = -1
    elif cur == -1:
        dir = 1
        cur = 1
ans[cur] += m%k
print(*ans)

#3 6 180
#48 90 42