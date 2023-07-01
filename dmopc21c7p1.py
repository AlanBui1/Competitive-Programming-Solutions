import sys; input = sys.stdin.readline

def solve():
    n, m =map(int, input().split())

    grid = [[int(i) for i in input().split()] for k in range(n)]

    if grid[n-1][m-1] == 0:
        grid[n-1][m-1] = int(1e18)
    
    for i in range(n-1, -1, -1):
        for k in range(m-1, -1, -1):
            if grid[i][k] == 0:
                grid[i][k] = int(1e18)+1
                if k+1 < m:
                    if grid[i][k+1] > 0:
                        grid[i][k] = min(grid[i][k], grid[i][k+1]-1)
                if i+1 < n:
                    if grid[i+1][k] > 0:
                        grid[i][k] = min(grid[i][k], grid[i+1][k]-1)

    flag = False

    for i in range(n):
        for k in range(m):
            if i+1 < n:
                if grid[i][k] >= grid[i+1][k]:
                    flag = True
                    break
            if k+1 < m:
                if grid[i][k] >= grid[i][k+1]:
                    flag = True
                    break

            if grid[i][k] <= 0:
                flag = True
                break
    
    if flag:
        print("-1")
    else:
        for i in range(n):
            print(*grid[i])

    
solve()