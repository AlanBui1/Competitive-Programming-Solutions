import sys
input = sys.stdin.readline
import queue

INF = int(1e9)
r, c = map(int, input().split())

grid = [[int(i) for i in input().split()] for k in range(r)]

dist = [[INF for i in range(c)] for k in range(r)]

dist[0][0] = 0

q = queue.Queue()
q.put((0, 0, 0))

moves = [[0, 1], [0, -1], [1, 0], [-1, 0]]

while not q.empty():
    curX, curY, curDist = q.get()
    if curDist > dist[curX][curY]:
        break
    
    for mx, my in moves:
        x = (mx*grid[curX][curY] + curX) % r
        y = (my*grid[curX][curY] + curY) % c
        
        if dist[x][y] > curDist + 1:
            dist[x][y] = curDist + 1
            q.put((x, y, curDist+1))
        
        
    
    
if dist[r-1][c-1] == INF:
    print("FOREVER")
else:
    print(dist[r-1][c-1])