n = int(input())

lis = []
g = [[] for i in range(n)]

for i in range(n):
  m = input().split()
  if m == ['0']:
    lis.append(i)
  else:
    m.remove(m[0])
    for k in m:
      g[i].append([int(k)-1, 1])

from queue import PriorityQueue
q = PriorityQueue()
start = 0
q.put((0,start))
import math
dist = [math.inf for i in range(n)]
dist[start] = 1

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
ans = math.inf
for i in lis:
  if dist[i] < ans:
    ans = dist[i]

if max(dist) != math.inf:
  print('Y')
else:
  print('N')
print(ans)