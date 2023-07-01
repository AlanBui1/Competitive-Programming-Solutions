def bfs(x, y):
    global ans  
    grid[x][y] = "."

    if x-1 >= 0:
        if grid[x-1][y] == "#":
            ans += 1
            bfs(x-1, y)

    if x+1 < 10:
        if grid[x+1][y] == "#":
            ans+=1
            bfs(x+1, y)

    if y-1 >= 0:
        if grid[x][y-1] == "#":
            ans += 1
            bfs(x, y-1)

    if y+1 < 10:
        if grid[x][y+1] == "#":
            ans += 1
            bfs(x, y+1)

for _ in range(5):
    grid = [[i for i in input()]for k in range(10)]
    line = input()

    for i in range(10):
        for k in range(10):
            if grid[i][k] == "A":
                ans = 1
                bfs(i, k)
                print(ans)
                break