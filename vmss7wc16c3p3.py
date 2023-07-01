from queue import PriorityQueue
import sys
import math
input = sys.stdin.readline
n, m, b, o = map(int, input().split())
ans = [math.inf for i in range(n)]
g = [[] for i in range(n)]
for i in range(m):
  node1, node2, weight = map(int, input().split())
  g[node1-1].append([node2-1, weight])
  g[node2-1].append([node1-1, weight])

q = PriorityQueue()
dist = [math.inf for k in range(n)]

start = b-1
q.put((0,start))
dist[start] = 0
while not q.empty():
  cur = q.get()
  node = cur[1]
  possible = g[node]
  for p in possible:
    w = p[1]
    x = p[0]
    if dist[node] + w < dist[x]:
      dist[x] = dist[node]+w
      q.put((dist[x], x))

for i in range(o):
  r = int(input())
  print(dist[r-1] if dist[r-1] != math.inf else -1)