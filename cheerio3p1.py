n, m =map(int, input().split())
grid = [[i for i in input()] for k in range(n)]

moves = [[0, 1], [0, -1], [1, 0], [-1, 0]]

for i in range(n):
    for k in range(m):
        if grid[i][k]  != 'W':
            continue
        for mx, my in moves:
            if 0 <= i+mx < n and 0 <= k+my < m:
                
                if grid[i+mx][k+my] == '.':
                    grid[i+mx][k+my] = 'C'

for i in grid:
    print(*i, sep="")