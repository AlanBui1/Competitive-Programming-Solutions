from pprint import *

h, w = map(int, input().split())

grid = [[i for i in input()]for k in range(h)]

cost = [[0 for i in range(w)]for k in range(h)]

for i in range(w):
    if grid[0][i] == ".":
        cost[0][i] = 1
    else:

        break
    
for i in range(h):
    if grid[i][0] == ".":
        cost[i][0] = 1
        
    else:
        break
    
for i in range(1, h):
    for k in range(1, w):
        if grid[i][k] == "#":
            continue
        down = 0
        right = 0
        if grid[i-1][k] == ".":
            down = cost[i-1][k]
            
        if grid[i][k-1] == ".":
            right = cost[i][k-1]
            
        cost[i][k] = down+right

print(cost[h-1][w-1] % ((10**9)+7))