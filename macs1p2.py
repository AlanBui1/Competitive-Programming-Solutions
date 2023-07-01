import sys
input = sys.stdin.readline
n = int(input())
g = [[i for i in input()] for k in range(2)]

for i in range(2):
    for k in range(n):
        if g[i][k] == ".":
            g[i][k] = 0
        else:
            g[i][k] = 1

used = [[3 for i in range(n)] for k in range(2)]

import queue
q = queue.Queue()
q.put((0, 0, 0))
used[0][0] = 0

moves = [[1, 1], [-1, 1], [1, -1], [-1, -1], [1, 0], [-1, 0], [0, 1], [0, -1]]

while not q.empty():
    x, y, d = q.get()

    for mx, my in moves:
        x += mx
        y += my

        if 0 <= x < 2 and 0 <= y < n:    
            if g[x][y] + d < used[x][y]:
                used[x][y] = g[x][y] + d
                q.put((x, y, used[x][y]))
        
        x -= mx
        y -= my

if used[1][-1] <= 2:
    print("YES")
else:
    print("NO")