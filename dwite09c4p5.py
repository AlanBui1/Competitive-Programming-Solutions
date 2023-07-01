from queue import PriorityQueue
maze = [[k for k in input()]for i in range(10)]
lis = {'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5}
stops = [[] for i in range(6)]
for i in range(10):
  for k in range(10):
    if maze[i][k] in lis:
      stops[lis[maze[i][k]]]=([i, k])

nxt=0
def right(x, y):
  global nxt
  if maze[x][y] == '#':
    nxt= y-1
    return

  if y == 9:
    nxt = 9
    return
    
  else:
    right(x,y+1)

def left(x, y):
  global nxt
  if maze[x][y] == '#':
    nxt= y+1
    return

  if y == 0:
    nxt= 0
    return

  else:
    left(x,y-1)

def up(x, y):
  global nxt
  if maze[x][y] == '#':
    nxt= x+1
    return 

  if x == 0:
    nxt= 0
    return

  else:
    up(x-1, y)

def down(x, y):
  global nxt
  if maze[x][y] == '#':
    nxt= x-1
    return 

  if x == 9:
    nxt=9
    return

  else:
    down(x+1, y)

for i in range(5):
  q = PriorityQueue()
  q.put((0,stops[i][0],stops[i][1]))
  xgoal = stops[i+1][0]
  ygoal = stops[i+1][1]
  visited = [[False for i in range(10)]for k in range(10)]
  
  while not q.empty():
    cur = q.get()
    curdist,x, y = cur[0],cur[1],cur[2]
    if visited[x][y]:
      continue
    visited[x][y] = True
    if x == xgoal and y == ygoal:
      print(curdist)
      break
    right(x,y)
    if nxt != y:
      q.put((curdist+abs(nxt-y),x,nxt))
    left(x,y)
    if nxt != y:
      q.put((curdist+abs(nxt-y),x,nxt))
    up(x,y)
    if nxt != x:
      q.put((curdist+abs(nxt-x),nxt,y))
    down(x,y)
    if nxt != x:
      q.put((curdist+abs(nxt-x),nxt,y))