import sys; input = sys.stdin.readline

n, k = map(int, input().split())

g = k+1

ans = 0
ans += k*(n//g)
ans += n%g

print(ans)