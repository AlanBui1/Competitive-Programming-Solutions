import queue
import sys
input = sys.stdin.readline
n = [int(k) for k in input().split()]
g = [[] for i in range(n[0])]
for i in range(n[1]):
  x = [int(j) for j in input().split()]
  g[x[0]-1].append (x[1]-1)
  g[x[1]-1].append (x[0]-1)

y = 0
start = n[2]
dest = n[3]
q = queue.Queue()
q.put((start-1,0))
visited = [False for i in range(n[0])]
while not q.empty():
    c = q.get()
    visited[c[0]] = True
    if c[0] == dest-1:
        print('GO SHAHIR!')
        y = 1
        break
    for nxt in g[c[0]]:
        if not visited[nxt]:
            q.put((nxt, c[1]+1))
if y == 0:
  print('NO SHAHIR!')