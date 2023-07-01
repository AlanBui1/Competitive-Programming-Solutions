import sys
input = sys.stdin.readline

n, k, m = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

inds = {}
count =0
for i in b:
    inds[i] = count
    count += 1

ans = 0
for i in range(n):
    want = m - a[i]
    if n >= abs(i - inds.get(want, -100000000)) >= k:
        ans += 1
print(ans)