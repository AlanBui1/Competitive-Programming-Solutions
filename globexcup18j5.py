import sys
input = sys.stdin.readline
n, m, y, c = map(int, input().split())

g = [[] for i in range(n)]

for i in range(m):
  node1, node2 = map(int, input().split())
  g[node1-1].append([node2-1, 1])
  g[node2-1].append([node1-1, 1])

from queue import PriorityQueue
q = PriorityQueue()
q.put((0, c-1))
import math
dist = [math.inf for i in range(n)]
dist[c-1] = 0

while not q.empty():
  cur = q.get() 
  node = cur[1]
  possible = g[node]
  for p in possible:
    if dist[node]+p[1] < dist[p[0]]:
      dist[p[0]] = dist[node]+p[1]
      q.put((dist[p[0]], p[0]))

for i in range(y):
  start, end = map(int, input().split())
  if dist[start-1] == math.inf:
    print('This is a scam!')
  elif dist[end-1] == math.inf:
    print('This is a scam!')
  else:
    print(dist[start-1]+dist[end-1])