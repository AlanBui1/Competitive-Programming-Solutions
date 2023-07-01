n, t = map(int, input().split())
dist = [10000000000 for i in range(n+2)]
g = [[] for i in range(n+2)]
stops = {'home':0,'Waterloo GO':1}
for i in range(n):
  name = input()
  stops[name] = i+2

for i in range(t):
  x = input().split('-')
  g[stops[x[0]]].append([stops[x[1]],1])
  g[stops[x[1]]].append([stops[x[0]],1])
from queue import PriorityQueue
q = PriorityQueue()

start = 0
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

if dist[1] >= 10000000000:
  print('RIP ACE')
else:
  print(dist[1])