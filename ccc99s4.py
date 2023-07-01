import sys
input = sys.stdin.readline
import queue
from pprint import pprint as pp

n = int(input())
inf = int(1e9)

moves = [[-1,2], [1,2], [-1,-2], [1,-2], [2,1], [2,-1], [-2,-1], [-2,1]]

for _ in range(n):
    r = int(input())
    c = int(input())
    pr = int(input())
    pc = int(input())
    kr = int(input())
    kc = int(input())

    dist = [[inf for i in range(101)] for k in range(101)]

    q = queue.Queue()
    q.put((kr, kc, 0))

    dist[kr][kc] = 0

    while not q.empty():
        x, y, d = q.get()

        for mx, my in moves:
            x += mx; y += my;
            if 1 <= x <= r and 1 <= y <= c:
                if dist[x][y] > d+1:
                    dist[x][y] = d+1
                    q.put((x, y, d+1))
            x -= mx; y -= my

    samecol = False
    if (kr+kc)%2 == (pr+pc)%2:
        samecol = True

    win = False
    minmoves = inf
    for i in range(pr+1, r):
        pawnDist = i-pr
        if pawnDist < dist[i][pc]:
            continue
        if pawnDist == dist[i][pc]:
            win = True
            minmoves = min(minmoves, pawnDist)

        elif not samecol:
            minmoves = min(minmoves, pawnDist)
            
        else:
            win = True
            minmoves =min(minmoves, pawnDist)

    if not samecol:
        if dist[r][pc] < r-pr:
            minmoves = min(minmoves, r-pr)

    if samecol and win:    
        print("Win in", minmoves, "knight move(s).")
    else:
        if minmoves >= inf:
            print("Loss in", r-pr-1, "knight move(s).")
        else:
            print("Stalemate in", minmoves-1, "knight move(s).")