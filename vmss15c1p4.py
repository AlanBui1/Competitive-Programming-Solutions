t, n, m, g = map(int, input().split())
c=0
lis = [[] for i in range(n+1)]
ans = []
for i in range(g):
  x = int(input())
  ans.append(x)

for i in range(m):
  node1, node2, weight = map(int, input().split())
  lis[node1].append([node2, weight])

from queue import PriorityQueue
import math
dist = [math.inf for i in range(n+1)]
q = PriorityQueue()
start = 0
q.put((0, start))
dist[start] = 0

while not q.empty():
  cur = q.get()
  node = cur[1]
  possible = lis[node]
  for p in possible:
    w = p[1]
    x = p[0]
    if dist[node]+w < dist[x]:
      dist[x] = dist[node]+w
      q.put((dist[x], x))

for i in ans:
  if dist[i] <= t:
    c += 1
print(c)