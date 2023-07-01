from queue import PriorityQueue
import math
for y in range(5):
  r, c = map(int, input().split())
  lis = []
  for i in range(r):
    maze = [k for k in input()]
    for j in maze:
      lis.append(j)
  g = [[] for i in range(c) for i in range(r)]
  for i in range((r*c)-1):
    if lis[i] != '#' and lis[i+1] != '#':
      g[i].append([i+1, 1])
      g[i+1].append([i, 1])
  for i in range((r*c)-c):
    if lis[i] != '#' and lis[i+c] != '#':
      g[i].append([i+c, 1])
      g[i+c].append([i, 1])
  q = PriorityQueue()
  dist = [math.inf for i in range(r*c)]
  start = lis.index('A')
  dest1 = lis.index('B')
  dest2 = lis.index('C')
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
  ans = dist[dest1]+dist[dest2]
  q = PriorityQueue()
  dist = [math.inf for i in range(r*c)]
  q.put((0, dest1))
  dist[dest1] = 0
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
  print(ans+dist[dest2])