import sys
input = sys.stdin.readline
from math import inf
import queue
import pprint
n = int(input())
for _ in range(n):
    sz = int(input())
    grid = [[inf for i in range(sz)] for k in range(sz)]
    elev = [[0 for i in range(sz)] for k in range(sz)]
    grid[0][0] = 0

    for i in range(sz):
        for k in range(sz):
            e = int(input())
            elev[i][k] = e
    
    qu = queue.PriorityQueue()
    qu.put((0, 0, 0))

    while not qu.empty():
        o2, y, x = qu.get()
      
        if x+1<sz:
            if abs(elev[y][x] - elev[y][x+1]) <= 2:
                if elev[y][x+1] > elev[0][0] or elev[y][x] > elev[0][0]:
                    if grid[y][x] + 1 < grid[y][x+1]:
                        grid[y][x+1] = grid[y][x]+1
                        qu.put((grid[y][x+1], y, x+1))
                
                elif grid[y][x] <= grid[y][x+1] :
                    grid[y][x+1] = grid[y][x]
                    qu.put((grid[y][x+1],y, x+1))


        if y+1 <sz:
            if abs(elev[y][x] - elev[y+1][x]) <= 2:
                if elev[y+1][x] > elev[0][0] or elev[y][x] > elev[0][0]:
                    if grid[y][x]+1 < grid[y+1][x]:
                        grid[y+1][x]= grid[y][x]+1
                        qu.put((grid[y+1][x], y+1, x))

                elif grid[y][x] < grid[y+1][x]:
                    grid[y+1][x] = grid[y][x]
                    qu.put((grid[y+1][x], y+1, x))

        if y -1 >= 0:
            if abs(elev[y][x] - elev[y-1][x]) <= 2:
                if elev[y-1][x] > elev[0][0] or elev[y][x] > elev[0][0]:
                    if grid[y][x]+1 < grid[y-1][x]:
                        grid[y-1][x]= grid[y][x]+1
                        qu.put((grid[y-1][x], y-1, x))

                elif grid[y][x] < grid[y-1][x]:
                    grid[y-1][x] = grid[y][x]
                    qu.put((grid[y-1][x], y-1, x))

        if x-1 >= 0:
            if abs(elev[y][x] - elev[y][x-1]) <= 2:
                if elev[y][x-1] > elev[0][0] or elev[y][x] > elev[0][0]:
                    if grid[y][x] + 1 < grid[y][x-1]:
                        grid[y][x-1] = grid[y][x]+1
                        qu.put((grid[y][x-1], y, x-1))
                
                elif grid[y][x] < grid[y][x-1]:
                    grid[y][x-1] = grid[y][x]
                    qu.put((grid[y][x-1], y, x-1))

        
    if grid[sz-1][sz-1] == inf:
        print("CANNOT MAKE THE TRIP")
    else:
        print(grid[sz-1][sz-1])
    if _ != n-1:
        print()