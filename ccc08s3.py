import queue
t = int(input())

def goodSquare(x, y, r, c):
    return 0 <= x < r and 0 <= y < c

for _ in range(t):
    r = int(input())
    c = int(input())

    visited = [[False for i in range(c)]for k in range(r)]
    grid = [[i for i in input()]for k in range(r)]

    q = queue.Queue()
    ans = -2
    q.put((0, 0, 0))

    while not q.empty():
        x, y, d = q.get()
        
        if grid[x][y] == "*" or visited[x][y]:
            continue

        visited[x][y] = True

        if x == r-1 and y == c-1:
            ans = d
            break

        if grid[x][y] == "+":
            if goodSquare(x+1,y, r, c):
                q.put((x+1, y, d+1))
            if goodSquare(x-1, y, r, c):
                q.put((x-1, y, d+1))
            if goodSquare(x, y+1, r, c):
                q.put((x, y+1, d+1))
            if goodSquare(x, y-1, r, c):
                q.put((x, y-1, d+1))
            
        if grid[x][y] == "|":
            if goodSquare(x+1,y, r, c):
                q.put((x+1, y, d+1))
            if goodSquare(x-1, y, r, c):
                q.put((x-1, y, d+1))

        if grid[x][y] == "-":
            if goodSquare(x, y+1, r, c):
                q.put((x, y+1, d+1))
            if goodSquare(x, y-1, r, c):
                q.put((x, y-1, d+1))

    print(ans+1)