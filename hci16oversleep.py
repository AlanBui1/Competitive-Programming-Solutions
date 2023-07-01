from math import inf
import queue
n, m= map(int, input().split())
grid = [[i for i in input()]for k in range(n)]
dist = [[-inf for i in range(m)]for k in range(n)]

for i in range(n):
    for k in range(m):
        if grid[i][k] == "s":
            start = (i, k)

        elif grid[i][k] == "e":
            end = (i, k)
            grid[i][k] = "."

q = queue.Queue()
q.put((start, 0))

grid[start[0]][start[1]] = 0

while not q.empty():
    cur, curDist = q.get()
    
    curX = cur[0]; curY = cur[1];
    grid[curX][curY] = curDist

    if curY+1<m:
        if grid[curX][curY+1] == ".":
            q.put(((curX, curY+1), curDist+1))
  

    if curY-1 >= 0:
        if grid[curX][curY-1] == ".":
            q.put(((curX, curY-1), curDist+1))

    if curX-1 >= 0:
        if grid[curX-1][curY] == ".":
            q.put(((curX-1, curY), curDist+1))

    if curX+1< n:
        if grid[curX+1][curY] == ".":
            q.put(((curX+1, curY), curDist+1))

if grid[end[0]][end[1]] == ".":
    print(-1)
else:
    print(grid[end[0]][end[1]]-1)