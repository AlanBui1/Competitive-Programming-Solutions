g = [[] for i in range(64)] 
for i in range(48):
  if (i+17)%8 != 0:
    g[i].append(i+17) #down and right
    g[i+17].append(i)
  if (i+15) not in [7, 15, 23, 31, 39, 47, 55, 63]:
    g[i].append(i+15) #down and left
    g[i+15].append(i)
  
for i in range(56):
  if i not in [6, 7, 14, 15, 22, 23, 30, 31, 38, 39, 46, 47, 54, 55, 62, 63]:
    g[i].append(i+10) #middle down right
    g[i+10].append(i)
  if i not in [0, 1, 8, 9, 16, 17, 24, 25, 32, 33, 40, 41, 48, 49, 56, 57]:
    g[i].append(i+6) #middle up right
    g[i+6].append(i)

for i in range(58, 63):
  g[i].append(i-10)
  g[i-10].append(i)

x, y = map(int, input().split())
dest1, dest2 = map(int, input().split())
start = ((8-y)*8)+(x-1)
dest = ((8-dest2)*8)+(dest1-1)
import queue
visited = [False for i in range(64)]
q = queue.Queue()
q.put([start, 0])
while not q.empty():
  node, dist = q.get()
  if node == dest:    
    ans = dist
    break
  if not visited[node]:
    visited[node] = True
    for nxt in g[node]:
      q.put([nxt, dist+1])
print(ans)