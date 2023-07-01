n, m = map(int, input().split())
dist = [10000000000 for i in range(n)]
g = [[] for i in range(n)]

from queue import PriorityQueue
q = PriorityQueue()

start = 0
q.put((0,start))
dist[start] = 0
for i in range(m):
  node1, node2, weight = map(int, input().split())
  g[node1-1].append([node2-1,weight])
  g[node2-1].append([node1-1,weight])

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

for i in range(n):
  if dist[i] == 10000000000:
    print(-1)
  else:
    print(dist[i])