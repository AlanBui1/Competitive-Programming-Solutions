import queue
import sys
input = sys.stdin.readline
t = int(input())
import math

for z in range(t):
  l, w = map(int, input().split())
  floor = [[k for k in input()] for i in range(w)]
  g = [[] for i in range(l*w)]

  for i in range(w):
    for k in range(l):
      if (k+1)<l:
        if floor[i][k] != 'X' and floor[i][k+1] != 'X':
          g[(i*l)+k].append((i*l)+k+1)
          g[(i*l)+k+1].append((i*l)+k)
      if (i+1) <w:
        if floor[i][k] != 'X' and floor[i+1][k] != 'X':
          g[(i*l)+k].append(((i+1)*l)+k)
          g[((i+1)*l)+k].append((i*l)+k)
      if floor[i][k] == 'C':
        start=(i*l)+k
      elif floor[i][k] =='W':
        end = (i*l)+k

  q = queue.Queue()
  q.put(start)
  ans = '#notworth'
  dist = [math.inf for i in range(l*w)]
  dist[start] = 0
  while not q.empty():
    node = q.get()
    if dist[node] >= 60 and dist[node]!= math.inf:
      break
    if node == end:
      if dist[node] < 60:
        ans = dist[node]
      break
    for nxt in g[node]:
      if dist[nxt] == math.inf:
        dist[nxt] = dist[node]+1
        q.put(nxt)
  print(ans)