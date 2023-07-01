import sys
input = sys.stdin.readline
from queue import PriorityQueue
from pprint import pprint as pp
n, k = map(int, input().split())
graph = [[] for i in range(n)]
weights = [int(i) for i in input().split()]

for i in range(n-1):
    graph[i].append((i+1, weights[i]))
    graph[i+1].append((i, weights[i]))

    if i+k<n:
        graph[i].append((i+k, 0))
        graph[i+k].append((i, 0))
m=n-1
edgeCount=0
mstCost=0
visited = [False for i in range(n)]
pq = PriorityQueue()

visited[0] = True
possible = graph[0]
for p in possible:
    if not visited[p[0]]:
        pq.put((p[1], p[0]))

while not pq.empty() and edgeCount != m:
    weight, node = pq.get()
    if visited[node]:
        continue
    visited[node] = True
    edgeCount += 1
    mstCost += weight

    possible = graph[node]
    for p in possible:
        if not visited[p[0]]:
            pq.put((p[1], p[0]))

print(mstCost)