n, m = map(int, input().split())
grid = [[int(i) for i in input().split()] for k in range(n)]

for i in range(n):
    for k in range(m):
        if i==0 and k == 0:
            continue
        if i == 0:
            grid[i][k] += grid[i][k-1]
        elif k == 0 and i != 0:
            grid[i][k] += grid[i-1][k]
            
        else:
            grid[i][k] += min(grid[i-1][k], grid[i][k-1])
            
print(grid[n-1][m-1])