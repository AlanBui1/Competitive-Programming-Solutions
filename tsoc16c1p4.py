r, c = map(int, input().split())

grid = [[i for i in input()] for k in range(r)]

visited = [[False for i in range(c)]for k in range(r)]

moves = [[1, 0], [-1, 0], [0,-1], [0,1]]

def dfs(curX, curY):
    visited[curX][curY] = True

    for mx, my in moves:
        curX+=mx
        curY+=my

        if 0 <= curX < r and 0 <= curY < c:
            if not visited[curX][curY] and grid[curX][curY] != "#":
                dfs(curX, curY)

        curX-=mx
        curY -= my

ans = 0
for i in range(r):
    for k in range(c):
        if grid[i][k] == "M" and not visited[i][k]:
            ans += 1
            dfs(i, k)
print(ans)