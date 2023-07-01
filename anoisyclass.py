import sys; input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[] for i in range(n+1)]
visited = [False  for i in range(n+1)]

for i in range(m):
    a, b= map(int, input().split())

    if b not in graph[a]:
        graph[a].append(b)

fail = 0

def dfs(cur):
    global ded, vis
    vis[cur] = True
    for nxt in graph[cur]:
        if vis[nxt]:
            ded = True
            return
        dfs(nxt)
    vis[cur] = False
   

for i in range(1,n+1):
    if visited[i]:
        continue
    vis = [False for i in range(n+1)]
    ded = False
    dfs(i)
    if ded:
        print("N")
        fail = True
        break

if not fail:
    print("Y")