n, m = map(int, input().split())
g = [[] for i in range(n)]

for i in range(m):
  node1, node2, weight = map(int, input().split())
  g[node1].append([node2, weight])
  g[node2].append([node1, weight])

from queue import PriorityQueue
q = PriorityQueue()
import math
dist1 = [math.inf for i in range(n)]
dist2 = [math.inf for i in range(n)]

q.put((0, 0))
dist1[0] = 0

while not q.empty():
  cur = q.get()
  node = cur[1]
  possible = g[node]
  for p in possible:
    w = p[1]
    x = p[0]
    if dist1[node]+w < dist1[x]:
      dist1[x] = dist1[node] + w
      q.put((dist1[x], x))

q = PriorityQueue()
q.put((0,n-1))
dist2[n-1] = 0

while not q.empty():
  cur = q.get()
  node = cur[1]
  possible = g[node]
  for p in possible:
    w = p[1]
    x = p[0]
    if dist2[node]+w < dist2[x]:
      dist2[x] = dist2[node] + w
      q.put((dist2[x], x)) 

for i in range(len(dist1)):
  dist2[i] += dist1[i]

print(max(dist2))