import sys
input = sys.stdin.readline

def solve():
    r, c= map(int, input().split())
    a, b= map(int, input().split())

    h = r*a
    w = c*b

    grid = [["." for i in range(w)] for k in range(h)]

    for i in range(h):
        for k in range(w):
            if (i//a)%2 == (k//b)%2:
                grid[i][k] = "X"

    for i in grid:
        print(*i, sep = "")
    
    
q = 1
for _ in range(q):
    solve()