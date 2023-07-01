n = int(input())

lis = {}
g = [[] for i in range(n)]

for i in range(n):
  node1, node2 = map(int, input().split())
  if node1 not in lis:
    lis[node1] = len(lis)
  if node2 not in lis:
    lis[node2] = len(lis)
  g[lis[node1]].append([lis[node2], 1])

from queue import PriorityQueue
import math


while True:
  node1, node2 = map(int, input().split())
  if node1 == 0 and node2 == 0:
    break
  else:
    q = PriorityQueue()
    q.put((0, lis[node1]))
    dist = [math.inf for i in range(n)]
    dist[lis[node1]] = 0

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
    print('No' if dist[lis[node2]] == math.inf else 'Yes'+' '+str(dist[lis[node2]]-1))