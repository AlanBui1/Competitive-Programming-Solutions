import sys
input = sys.stdin.readline
import queue

n, m, t = map(int, input().split())
grid = [[i for i in input()] for k in range(n)]
inf = int(1e9)
dist = [[[inf for i in range(m)]for k in range(n)]for j in range(32)]
hider = [[-1 for i in range(m)]for k in range(n)]

cnt = 0
for i in range(n):
    for k in range(m):
        if grid[i][k] == "G":
            start = [i, k]
            dist[0][i][k] = 0
        if grid[i][k] == "H":
            hider[i][k] = cnt
            cnt+=1

moves = [[-1, 0], [1, 0], [0, -1], [0, 1]]

q = queue.Queue()
q.put((start, 0, 0))
ans = inf

while not q.empty():
    cur, curDist, mask = q.get()
    if mask == (1<<t)-1:
        ans = min(ans, curDist)
        continue

    for mx, my in moves:
        if 0 <= cur[0]+mx < n and 0 <= cur[1]+my < m:
            if grid[cur[0]+mx][cur[1]+my] != "X":
                if grid[cur[0]+mx][cur[1]+my] == "H":
                    
                    if dist[mask| 1 << hider[cur[0]+mx][cur[1]+my]][cur[0]+mx][cur[1]+my] > curDist+1:
                        dist[mask| 1 << hider[cur[0]+mx][cur[1]+my]][cur[0]+mx][cur[1]+my] = curDist+1
                        q.put(([cur[0]+mx, cur[1]+my], dist[mask| 1 << hider[cur[0]+mx][cur[1]+my]][cur[0]+mx][cur[1]+my], mask| 1 << hider[cur[0]+mx][cur[1]+my]))
                    
                else:
                    if dist[mask][cur[0]+mx][cur[1]+my] > curDist+1:
                        dist[mask][cur[0]+mx][cur[1]+my] = curDist+1
                        q.put(([cur[0]+mx, cur[1]+my], dist[mask][cur[0]+mx][cur[1]+my], mask))
print(ans)