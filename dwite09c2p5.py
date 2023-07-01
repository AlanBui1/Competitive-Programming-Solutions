import queue

r = int(input())
c = int(input())
maze = [[k for k in input()] for i in range(r)]
g = [[] for i in range(r*c)]
en = [[] for i in range(10)]
ex = [[] for i in range(10)]
trc = {"A":0, "B":1, "C":2, "D":3, "E":4, "F":5, "G":6, "H":7, "I":8, "J":9}
trl = {"a":0, "b":1, "c":2, "d":3, "e":4, "f":5, "g":6, "h":7, "i":8, "j":9}
num=0
for i in range(r):
  for k in range(c):
    if k+1 < c:
      if maze[i][k] != '#' and maze[i][k+1] != '#':
        g[(i*c)+k].append((i*c)+k+1)
        g[(i*c)+k+1].append((i*c)+k)
    if i+1 < r:
      if maze[i][k] != '#' and maze[i+1][k] != '#':
        g[(i*c)+k].append(((i+1)*c)+k)
        g[((i+1)*c)+k].append((i*c)+k)

    if maze[i][k] == '1':
      s1 = (i*c)+k
    elif maze[i][k] == '2':
      s2 = (i*c)+k
    elif maze[i][k] == '3':
      s3 = (i*c)+k
    elif maze[i][k] == '4':
      s4 = (i*c)+k
    elif maze[i][k] == '5':
      s5 = (i*c)+k
    elif maze[i][k] in trc:
      ex[trc[maze[i][k]]]=((i*c)+k)
    elif maze[i][k] in trl:
      en[trl[maze[i][k]]]=((i*c)+k)
      num+=1

for i in range(num):
  g[en[i]].append(ex[i])
lis = []
def bfs(start, n):
  q = queue.Queue()
  q.put(start)
  visited = [False for i in range(r*c)]
  found = [0 for i in range(5)]
  found[n] = 1
  while not q.empty():
    cur = q.get()
    visited[cur] = True
    if 0 not in found:
      break
    if cur in [s1,s2,s3,s4,s5]:
      x = [s1,s2,s3,s4,s5].index(cur)
      found[x] = 1
    for nxt in g[cur]:
      if not visited[nxt]:
        q.put(nxt) 
  found[n] = 0
  ans = str(n+1)+":"
  for i in range(5):
    if found[i] == 1:
      ans = ans+str(i+1)
      
      ans=ans+" "
  if ans[-1] == " ":
    ans = ans[:len(ans)-1]
  #lis.append(ans)
  print(ans)

bfs(s1,0)
bfs(s2,1)
bfs(s3,2)
bfs(s4,3)
bfs(s5,4)