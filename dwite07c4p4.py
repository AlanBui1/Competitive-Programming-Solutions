import queue

def validMove(x, y, cx, cy):
    x += cx; y += cy
    if x < 0 or y < 0:
        return False

    if x >= 10 or y >= 10:
        return False

    if grid[x][y] == "#":
        return False

    return True

for _ in range(5):
    grid = [[i for i in input()] for k in range(10)]

    start = []
    stop = []

    for i in range(10):
        for k in range(10):
            if grid[i][k] == 'X':
                if start != []:
                    stop = i, k

                else:
                    start = i, k

    q = queue.Queue()
    q.put(start)

    dist =[[int(1e9) for i in range(10)]for k in range(10)]

    moves = [[-1, -1], [-1, 0], [-1, 1], [1, 1], [1, 0], [1, -1], [0,1], [0,-1]]

    dist[start[0]][start[1]] = 0

    while not q.empty():
        x, y = q.get()

        for mx, my in moves:
            if validMove(x, y, mx, my):
                if dist[x+mx][y+my] > dist[x][y] +1 :
                    dist[x+mx][y+my] = dist[x][y] +1
                    q.put((x+mx, y+my))

    print(dist[stop[0]][stop[1]])

    ln = input()