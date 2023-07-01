import sys;
input = sys.stdin.readline

r, c = map(int, input().split())

grid = [[i for i in input()]for k in range(r)]

components = 0

vis = [[False for i in range(c)] for k in range(r)]

moves = [[-1,0], [1,0], [0,-1], [0,1]]

def dfs(curX, curY):
    vis[curX][curY]= True
    for mx, my in moves:
        curX += mx
        curY += my
        if 0 <= curX <r and 0 <= curY < c:
            if not vis[curX][curY] and grid[curX][curY] != "X":
                dfs(curX, curY)
        curX -= mx
        curY -= my


for i in range(r):
    for k in range(c):
        if grid[i][k] == "X" or vis[i][k]:
            continue
        components+=1
        dfs(i, k)

print(components)