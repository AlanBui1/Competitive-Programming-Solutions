MOD = 1000000007
import sys; input = sys.stdin.readline

n, a = map(int, input().split())

grid = [[int(i) for i in input().split()]for k in range(n)]

def multiply(lis, old):
    newmatrix = [[0 for i in range(n)] for k in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                toadd = (lis[i][k]*old[k][j])%MOD
                toadd %= MOD
                newmatrix[i][j] += toadd
                newmatrix[i][j] %= MOD

    return newmatrix

def power(matrix, p, mult):

    while p > 0:
        if (p&1):
            matrix = multiply(matrix, mult)
        p//=2
        mult = multiply(mult, mult)

    return matrix

grid = power(grid[:], a-1, grid[:])
ans =0 

for i in range(n):
    for k in range(n):
        ans += grid[i][k]
        ans %= MOD

print(int(ans%MOD))