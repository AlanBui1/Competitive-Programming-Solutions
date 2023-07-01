r = int(input())
c = int(input())

grid = [[i for i in input()] for k in range(r)]
ans = [0 for i in range(6)]
visited = [[0 for i in range(c)] for k in range(r)]
moves = [[0, 1], [0, -1], [1, 0], [-1, 0]]

portal = {}
end = {}

def dfs(x, y):
    if visited[x][y]:
        return 0
    visited[x][y] = 1
    if grid[x][y] in "abcdefhij":
        square = end[chr(ord(grid[x][y]) - 32)]
        return dfs(square[0], square[1])+1
    ret = 1
    for mx, my in moves:
        x += mx
        y += my
        if 0 <= x < r and 0 <= y < c:
            if not visited[x][y] and grid[x][y] != "#":
                ret += dfs(x, y)
        x -= mx
        y -= my

    return ret

for i in range(r):
    for k in range(c):
        if grid[i][k] in "abcdefghij":
            portal[grid[i][k]] = [i, k]
        elif grid[i][k] in "ABCDEFGHIJ":
            end[grid[i][k]] = [i, k]

for i in range(r):
    for k in range(c):
        if grid[i][k] in "12345":
            for a in range(r):
                for b in range(c):
                    visited[a][b] = 0
            ans[int(grid[i][k])] = dfs(i, k)

for i in range(1, 6):
    print(ans[i])