import queue
n, m = map(int, input().split())
g = [[] for i in range(n)]
lis = []
for i in range(m):
  node1, node2 = map(int, input().split())
  g[node1-1].append(node2-1)
  lis.append([node1-1, node2-1])



for i in range(m):
  q = queue.Queue()
  q.put(0)
  visited = [False for i in range(n)]
  found = False
  re = [lis[i][0], lis[i][1]]
  g[re[0]].remove(re[1])
  while not q.empty():
    c = q.get()
    visited[c] = True
    if c == n-1:
      found = True
      break
    for nxt in g[c]:
      if not visited[nxt]:
        q.put(nxt)
  if found:
    print('YES')
  else:
    print('NO')
  g[re[0]].append(re[1])