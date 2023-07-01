import sys; input = sys.stdin.readline

n = int(input())

c = [int(i) for i in input().split()]
m = [int(i) for i in input().split()]
c.sort(); m.sort()

ans =-1

for i in range(n):
    ans = max(ans, abs(c[i]-m[i]))

print(ans)