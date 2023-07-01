n = int(input())
maze = [[i for i in input()]for k in range(n)]
psa = [[0 for i in range(n+1)]for k in range(n+1)]

for i in range(n):
    for k in range(n):
        if maze[i][k] == "#":
            psa[i+1][k+1] += 1

for i in range(1, n+1):
    for k in range(1, n+1):
        psa[i][k] += psa[i-1][k] + psa[i][k-1] - psa[i-1][k-1]

def S(x1, y1, x2, y2):
    return psa[x2][y2] - psa[x2][y1-1] - psa[x1-1][y2] + psa[x1-1][y1-1]

def works(x):
    for i in range(1, n+1-x):
        for k in range(1, n+1-x):
            if S(i, k, i, k+x) == 0 and S(i, k, i+x, k) == 0 and S(i+x, k, i+x, k+x) == 0 and S(i, k+x, i+x, k+x) == 0:
                return 1

    return 0

ans = 0
for i in range(1, n):
    if works(i):
        ans = i

print(ans)