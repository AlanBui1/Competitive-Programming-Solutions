import sys
input = sys.stdin.readline
import queue
r, c = map(int, input().split())
start = [int(k) for k in input().split()]
end = [int(k) for k in input().split()]
maze = [[k for k in input()] for i in range(r)]
teleporters = {}
t = int(input())
for i in range(t):
  x, y = map(int, input().split())
  teleporters[(x,y)] = True

q = queue.Queue()
q.put((start[0], start[1], 0))
tfound = False
tdist = -1
dist = -1
maze[start[0]][start[1]] = 0

while not q.empty():
  cur = q.get()
  x = cur[0]
  y = cur[1]
  if x > 0 and maze[x-1][y] == 'O':
    maze[x-1][y] = maze[x][y]+1
    q.put((x-1, y))
  if x < r-1 and maze[x+1][y] == 'O':
    maze[x+1][y] = maze[x][y]+1
    q.put((x+1, y))
  if y > 0 and maze[x][y-1] == 'O':
    maze[x][y-1] = maze[x][y]+1
    q.put((x, y-1))
  if y < c-1 and maze[x][y+1] == 'O':
    maze[x][y+1] = maze[x][y]+1
    q.put((x, y+1))
  if not tfound and (x, y) in teleporters:
    tfound = True
    tdist = maze[x][y]
  elif x == end[0] and y == end[1]:
    dist = maze[x][y]
    break

if not tfound:
  print(0)
elif tdist >= dist:
  print(0)
else:
  print(abs(dist-tdist))