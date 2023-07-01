import sys; input = sys.stdin.readline
n, r = map(int, input().split())
n+=1
graph= [[]for i in range((1<<n)+1)]

for i in range((1 << (n-1))-1):
    u, v, w, d = map(int, input().split())

    graph[u].append([v, d])
    graph[u].append([w, 0])

inf = int(1e9)
dist = [-inf for i in range((1<<n)+1)]
ans = -inf

def dfs(curNode, curDist):
    global ans
    dist[curNode] = curDist
    ans = max(ans, curDist)
    ret = curDist

    for nxtNode, nxtDist in graph[curNode]:
        ret = max(ret, dfs(nxtNode, curDist+nxtDist))

    return ret

dfs(1, r)
print(ans)