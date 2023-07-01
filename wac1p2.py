import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

n, m, k = map(int, input().split())

graph = [[] for i in range(n)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

visited = [0 for i in range(n)]

def dfs(start):
    global cnt, totEdges
    cnt += 1
    totEdges += len(graph[start])
    visited[start] = 1

    for nxt in graph[start]:
        if not visited[nxt]:
            dfs(nxt)
            
leftover = 0
comps = 0
for i in range(n):
    if visited[i]:
        continue
    comps += 1
    cnt = 0
    totEdges= 0
    dfs(i)
    leftover += totEdges//2 - cnt + 1

ans = max(0, comps - 1 - min(leftover, k))
print(ans)