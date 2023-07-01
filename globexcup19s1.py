import sys; input = sys.stdin.readline

n, k = map(int, input().split())
vis = {}
cnt = 0
for i in range(n):
    a = int(input())
    if a not in vis:
        cnt+= 1
        vis[a] = 0

    print(vis[a])
    vis[a]+=1

print(cnt)