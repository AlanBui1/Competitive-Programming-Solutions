import sys
from queue import PriorityQueue
import math
input = sys.stdin.readline
n, m, a, b = map(int, input().split())
ans = 0
g = [[] for i in range(n)]
dist = [math.inf for i in range(n)]

for i in range(m):
  node1, node2 = map(int, input().split())
  g[node1-1].append([node2-1, 1])
  g[node2-1].append([node1-1, 1])

q = PriorityQueue()
start = 0
q.put((0, start))
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

if dist[a-1] != math.inf:
  ans += dist[a-1]
  dist = [math.inf for i in range(n)]
  q = PriorityQueue()
  start = a-1
  q.put((0, start))
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
  if dist[b-1] != math.inf:
    ans += dist[b-1]
    print(ans)
  else:
    print(-1)
else:
  print(-1)