import sys
input = sys.stdin.readline

dist = [0 for i in range(105)]
inf = int(1e9)

def dfs(curNode, curDist):
    global graph, ans, dist
    dist[curNode] = curDist
    if ans != -1:
        return
    for nxtNode in graph[curNode]:
        if dist[nxtNode] != inf:
            ans = curNode-dist[nxtNode]
            return
        dfs(nxtNode, curDist+1)

def solve():
    global dist, inf, graph, ans
    n = int(input())
    graph = [[] for i in range(105)]
    for i in range(n):
        a, b = map(int, input().split())
        graph[a].append(b)

    dist = [inf for i in range(105)]
    ans = -1
    dfs(1, 0)
    print(ans)
    
for _ in range(5):
    solve()