import pprint
import sys
input = sys.stdin.readline
r, c = map(int, input().split())
maze = [[0 for i in range(r)]for k in range(c)]

k = int(input())
for i in range(k):  
    x, y = map(int, input().split())
    maze[y-1][x-1] = -1

for i in range(r):
    if maze[0][i] != -1:
        maze[0][i] = 1
    else:
        break
for i in range(c):
    if maze[i][0] != -1:
        maze[i][0] = 1
    else:
        break

for i in range(1, c):
    for k in range(1, r):
        down = 0
        right = 0

        if maze[i-1][k] != -1:
            down = maze[i-1][k]
        if maze[i][k-1] != -1:
            right = maze[i][k-1]
        if maze[i][k] != -1:
            maze[i][k] = down + right
    
print(maze[c-1][r-1])