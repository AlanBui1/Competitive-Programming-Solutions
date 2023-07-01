from queue import Queue
moves = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [-1, -1], [1, -1], [-1, 1]]
INF = int(1e9)+7
def solve():
    grid = []
    S = []
    E = []
    while True:
        line = input()
        grid.append(line)
        
        if line.count("x") == len(line):
            break

    R = len(grid)-1
    dist = [[INF for i in range(10)] for k in range(R)]
    
    for i in range(R):
        for k in range(10):
            if grid[i][k] == "S":
                S = [i, k]
            if grid[i][k] == "E":
                E = [i, k]
    q = Queue()
    q.put((S[0], S[1], 0))
    dist[S[0]][S[1]] = 0

    while not q.empty():
        x, y, curDist = q.get()

        for mx, my in moves:
            x += mx
            y += my

            if 0 <= x < R and 0 <= y < 10:
                if grid[x][y] != " ":
                    if dist[x][y] > curDist+1:
                        dist[x][y] = curDist+1
                        q.put((x, y, curDist+1))
            
            x -= mx
            y -= my

    print(dist[E[0]][E[1]])

for i in range(5):
    solve()