import sys
import math
from queue import PriorityQueue
import queue
input = sys.stdin.readline

k, n, m = map(int, input().split())
found = False
g = [[] for i in range(n)]
for i in range(m):
  node1, node2, weight, dmg = map(int, input().split())
  g[node1-1].append([node2-1, weight, dmg])
  g[node2-1].append([node1-1, weight, dmg])
  if dmg != 0:
    found = True

a, b = map(int, input().split())

if found:
  dist = math.inf
  q = queue.Queue()
  q.put((0, 0, a-1, {}))

  cur_distance = 0
  cur_hull = 1
  cur_island = 2
  cur_visited = 3

  while not q.empty():
    cur = q.get()
    node = cur[cur_island]
    hulldmg = cur[cur_hull]
    distsofar = cur[cur_distance]
    visitedsofar = dict(cur[cur_visited])
    possible = g[node]
    for p in possible:
      nxt = p[0]
      distance = p[1]
      newhull = p[2]
      if hulldmg + newhull < k and distsofar+distance < dist:
        if nxt == b-1:
          dist = min(dist, distsofar+distance)
        elif (nxt, distance, newhull) not in visitedsofar:
          visitedsofar[(nxt, distance, newhull)] = True
          q.put((distsofar+distance, hulldmg+newhull, nxt, visitedsofar))

  print(dist if dist != math.inf else -1)

else:
  q = PriorityQueue()
  q.put((0, a-1))
  dist = [math.inf for i in range(n)]
  dist[a-1] = 0
  while not q.empty():
    cur = q.get()
    node = cur[1]
    possible = g[node]
    for p in possible:
      x = p[0]
      w = p[1]
      if dist[node]+w<dist[x]:
        dist[x] = dist[node]+w
        q.put((dist[x], x))
  if dist[b-1] == math.inf:
    print(-1)
  else:
    print(dist[b-1])