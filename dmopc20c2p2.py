import sys
input = sys.stdin.readline

n, m = map(int, input().split())

scarf = [int(i) for i in input().split()]

first = {}
last = {}

for i in range(n):
    if scarf[i] not in first:
        first[scarf[i]] = i
        last[scarf[i]] = i
    else:
        last[scarf[i]] = i

ans= 0
for i in range(m):
    x, y= map(int, input().split())
    if x in first and y in first:
        ans = max(ans, last[y] - first[x] + 1)
print(ans)