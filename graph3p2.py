n, m = map(int, input().split())
g = [[] for i in range(n)]
for i in range(m):
  node1, node2, weight = map(int, input().split())
  g[node1-1].append([node2-1, weight])

from queue import PriorityQueue
q = PriorityQueue()
import math
dist = [math.inf for i in range(n)]
start = 0
q.put((0,start))
dist[start] = 0

while not q.empty():
  cur = q.get()
  node = cur[1]
  possible = g[node]
  for p in possible:
    w = p[1]
    x = p[0]
    if dist[node]+w < dist[x]:
      dist[x] = dist[node]+w
      q.put((dist[x], x))

print(dist[n-1])