import sys
import queue
input = sys.stdin.readline
n = int(input())
g = [[] for i in range(n)]
for i in range(n):
  x, y = map(int, input().split())
  g[x-1].append(y-1)

k = [int(l) for l in input().split()]
q = queue.Queue()
q.put(k[0]-1)
visited = [False for i in range(n)]
found = False
while not q.empty():
  c = q.get()
  visited[c] = True
  if c== k[1]-1:
    found = True
    break
  for nxt in g[c]:
    if not visited[nxt]:
      q.put(nxt)
if found:
  print('Tangled')
else:
  print('Not Tangled')