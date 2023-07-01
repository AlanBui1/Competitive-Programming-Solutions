import sys
input = sys.stdin.readline
import queue
n, m = map(int, input().split())

graph = [[] for i in range(n+1)]
visited = [False for i in range(n+1)]
unbeatable = True

for i in range(m):
    x, y = map(int, input().split())
    graph[y].append(x)
    if y == 1:
        unbeatable = False
q = queue.Queue()
q.put(1)

while not q.empty():
    curNode = q.get()

    for nxt in graph[curNode]:
        if not visited[nxt]:
            visited[nxt] = True
            q.put(nxt)
ans = ""
for i in range(1, n+1):
    if visited[i]:
        ans += "1"
    else:
        ans += "0"
if unbeatable:
    print("1"+ans[1:])
else:
    print(ans)