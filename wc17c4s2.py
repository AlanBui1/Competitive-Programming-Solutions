import sys
input = sys.stdin.readline
import queue
from math import inf
n, m = map(int, input().split())
g = [[] for i in range(n)]
re = [[] for i in range(n)]
for i in range(m):
  a, b = map(int, input().split())
  g[a-1].append(b-1)
  re[b-1].append(a-1)

q = queue.Queue()
q.put(0)

dist = [inf for i in range(n)]
rdist = [inf for i in range(n)]
dist[0] = 0
rdist[0] = 0
while not q.empty():
  node = q.get()
  for nxt in g[node]:
    if dist[node]+1 < dist[nxt]:
      dist[nxt] = dist[node]+1
      q.put(nxt)

q = queue.Queue()
q.put(0)

while not q.empty():
  node = q.get()
  for nxt in re[node]:
    if rdist[node]+1 < rdist[nxt]:
      rdist[nxt] = rdist[node]+1
      q.put(nxt)

k = int(input())

targets = [int(i) for i in input().split()]
ans = 0
for i in targets:
  ans += (dist[i-1]+rdist[i-1])
  if ans == inf:
    break
if ans != inf:
  print(ans)
else:
  print(-1)