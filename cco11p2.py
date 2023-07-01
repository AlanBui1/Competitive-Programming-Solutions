import queue
import sys
input = sys.stdin.readline
import math
limit = int(input())
n, m = map(int, input().split())
g = [[] for i in range(n)]

for i in range(m):
  node1, node2, weight, option = map(int, input().split())
  if option == 1:
    g[node1].append([node2, weight, weight])
    g[node2].append([node1, weight, weight])
  else:
    g[node1].append([node2, weight, 0])
    g[node2].append([node1, weight, 0])

q = queue.Queue()
start = 0
dist = 0
outside = 0
visited = {}
ans = math.inf
q.put((dist, outside, start, visited))

while not q.empty():
  cur = q.get()
  distsofar = cur[0]
  outsofar = cur[1]
  node = cur[2]
  visitedsofar = dict(cur[3])
  visitedsofar[node] = True
  possible = g[node]
  for p in possible:
    nxt = p[0]
    distance = p[1]
    opt = p[2]
    if nxt == n-1 and outsofar+opt<=limit:
      ans = min(ans, distsofar+distance)
    elif distsofar+distance<ans and outsofar+opt <=limit and nxt not in visitedsofar:
      q.put((distsofar+distance, outsofar+opt, nxt, visitedsofar))

print(-1 if ans == math.inf else ans)